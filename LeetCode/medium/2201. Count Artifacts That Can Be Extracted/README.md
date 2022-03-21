# 2201. Count Artifacts That Can Be Extracted

[링크](https://leetcode.com/problems/count-artifacts-that-can-be-extracted/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 N, artifacts의 크기를 A, dig의 크기를 D라고 하자.

hash map을 이용해 각 좌표마다의 색상과, 색상마다 남은 좌표를 판단할 수 있다.

이 경우 각 좌표를 순회하는데 O(A \* N^2)의 시간 복잡도를 사용하고 땅을 파는데 O(D)의 시간 복잡도를 사용한다.

땅을 파는 작업을 먼저 수행할 수도 있다.

이 경우 땅을 먼저 판 뒤, artifacts를 순회하며 발굴 가능한지 판별한다. 이 과정에 O(A \* N^2)의 시간 복잡도를 사용한다.

prefixSum을 이용해 O(1)의 시간으로 해당 좌표들이 비어있는지 확인 가능하다.

이 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

각 좌표별로 팠는지, 파지 않았는지 판별하기 위해 O(N^2)의 공간 복잡도를 사용한다.

### hash map (color2axis, axis2color)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1138     | O(A \* N^2) |   O(N^2)    |

다음 2가지 hash map을 생성한다.

- axis2Color
- color2Axis

이후 입력받은 artifacts들을 순회하며 color별로, 그룹별로 묶는다.

이 때 시작점부터 끝점까지 채워야 하므로 최대 O(N^2)번 순회할 수 있다.

이후 땅을 파면서 artifacts의 좌표를 제거해나간다.

이후 모두 제거가 끝난 경우 정답을 증가시킨다.

입력받은 좌표의 범위가 제한되어 있으므로 하나의 int형으로 변환해 사용한다.

```cpp
int convert(int r, int c) { return r * 10000 + c; }
```

이를 구현하면 다음과 같다.

```cpp
int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
  // hash map, axis to num
  // hash map, num to axis
  unordered_map<int, int> axis2Color;
  unordered_map<int, unordered_set<int>> color2Axis;

  // O(A)
  for (vector<int>& a : artifacts) {
    int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];

    int color = color2Axis.size() + 1;
    // O(N^2)
    for (int r = r1; r <= r2; r++) {
      for (int c = c1; c <= c2; c++) {
        int axis = convert(r, c);

        axis2Color[axis] = color;
        color2Axis[color].insert(axis);
      }
    }
  }

  int answer = 0;
  // O(D)
  for (vector<int>& d : dig) {
    int r = d[0], c = d[1];

    int axis = convert(r, c);
    int color = axis2Color[axis];

    if (color == 0) continue;

    color2Axis[color].erase(axis);
    if (color2Axis[color].size() == 0) {
      answer++;
    }
  }

  return answer;
}
```

### dig first

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     665      | O(A \* N^2) |   O(N^2)    |

먼저 땅을 미리 파놓은 뒤, 각 artifact가 들어가는 공간의 땅이 미리 파져있는지를 검사한다.

이 경우 땅이 파여있는지 판단하기 위해 N^2크기의 배열을 사용한다.

```cpp
int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
  // O(N^2)
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  // O(D)
  for (vector<int>& d : dig) {
    visited[d[0]][d[1]] = 1;
  }

  int answer = 0;
  // O(N)
  for (vector<int>& a : artifacts) {
    int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];
    bool canFind = true;

    // O(N^2)
    for (int i = r1; i <= r2 && canFind; i++) {
      for (int j = c1; j <= c2 && canFind; j++) {
        if (visited[i][j]) continue;

        canFind = false;
        break;
      }
    }

    if (canFind) {
      answer++;
    }
  }

  return answer;
}
```

### dig first & prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     444      |   O(N^2)    |   O(N^2)    |

위 방법에서 각 구간이 모두 비었는지 확인하기 위해 prefix sum을 이용한다.

이 경우 O(1)의 시간 복잡도로 각 구간이 모두 비었는지 확인할 수 있다.

```cpp
int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
  vector<vector<int>> visited(n, vector<int>(n, 1));
  // O(D)
  for (vector<int>& d : dig) {
    visited[d[0]][d[1]] = 0;
  }
  // O(N^2)
  int preSum[n + 1][n + 1];

  for (int i = 0; i <= n; i++) {
    preSum[i][0] = 0;
    preSum[0][i] = 0;
  }

  // O(N^2)
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      preSum[y][x] = preSum[y - 1][x] + preSum[y][x - 1] -
                      preSum[y - 1][x - 1] + visited[y - 1][x - 1];
    }
  }

  int answer = 0;
  // O(A)
  for (vector<int>& a : artifacts) {
    int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];

    int sum = preSum[r2 + 1][c2 + 1] - preSum[r1][c2 + 1] -
              preSum[r2 + 1][c1] + preSum[r1][c1];

    if (sum == 0) answer++;
  }

  return answer;
}
```

## 고생한 점
