# 939. Minimum Area Rectangle

[링크](https://leetcode.com/problems/minimum-area-rectangle/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

points의 크기를 N이라 하자.

y, x가 겹치지 않는 두 점을 고른 뒤 각 좌표들로 만들 수 있는 별도의 2개의 점이 주어진 점들에 존재하는지 확인해 문제를 풀이할 수 있다.

hash set에 point들을 저장한 뒤 두 점을 순회해 풀이할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 점들을 hash set에 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### Hash Set & 연관 점 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     325      |   O(N^2)    |    O(N)     |

현재 점에서 다음 그룹들을 탐색한다.

- 현재 점과 y좌표 값이 같은 점들 : A
  - A와 x좌표 값이 같은 점들 : B
    - B의 y좌표값들 중 x좌표가 현재 점과 같은 점들 : C

여기서 정답이 될 수 있는 점들 (직사각형을 만들 수 있는 점들)은 C 그룹의 점들이다.

어차피 모든 점들을 탐색하므로 미리 hash set에 저장하지 않고 탐색 후 hash set에 저장할 수 있다. (미리 모든 점을 hash set에 넣고 탐색할 경우 중복된 경우가 생김)

hash set에서 중복된 경우를 줄이기 위해 해당 좌표가 존재하는지 여부를 다음과 같이 판단한다.

```cpp
unordered_map<int, unordered_map<int, bool>> hashP;
// exist : true
```

여기서 A와 B를 탐색할 때의 총 시간 복잡도는 O(N)이다.

이를 이용해 정답을 탐색한다.

```cpp
int minAreaRect(vector<vector<int>>& points) {
  // O(N)
  unordered_map<int, unordered_map<int, bool>> hashP;
  // O(N)
  unordered_map<int, unordered_set<int>> yToX, xToY;

  int answer = INT_MAX;

  // O(N)
  for (vector<int>& point : points) {
    int y1 = point[0], x1 = point[1];

    // O(sqrt(N))
    for (int x2 : yToX[y1]) {
      int xDiff = x1 - x2;
      if (xDiff == 0) continue;

      // O(sqrt(N))
      for (int y2 : xToY[x2]) {
        int yDiff = y1 - y2;
        if (yDiff == 0) continue;

        if (hashP[y2][x1]) {
          answer = min(answer, abs(xDiff * yDiff));
        }
      }
    }

    yToX[y1].emplace(x1);
    xToY[x1].emplace(y1);
    hashP[y1][x1] = true;
  }

  return answer == INT_MAX ? 0 : answer;
}
```

### Hash Set & 대각선 끝 두점 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     385      |   O(N^2)    |    O(N)     |

다음 점 2가지를 뽑는다고 하자.

- (y1, x1)
- (y2, x2)

위 점을 이용해 직사각형을 만들 수 있는지는 hash set에 다음 4개의 점이 존재하는지로 판단할 수 있다.

- (y1, x1)
- (y1, x2)
- (y2, x1)
- (y2, x2)

각 점을 순회하며, 동시에 다른 점을 내부에서 순회한다.

그리고 위 조건에 맞는 점들이 hash set에 존재하는지 판단한다.

여기서 중복된 경우를 줄이기 위해 순회 이후에 hash set에 저장한다.

y, x의 범위는 10^4 이하임이 보장되므로 long long형으로 한꺼번에 관리할 수 있다.

```cpp
unordered_set<long long> hashP;
```

혹은 hash 함수를 만들어 사용할 수 있다.

```cpp
struct Hash {
  size_t operator()(const pair<int, int>& x) const {
    return hash<long long>()(((long long)x.first) ^
                              (((long long)x.second) << 32));
  }
};

unordered_set<pair<int, int>, Hash> hashP;
```

이를 구현하면 다음과 같다.

```cpp
int minAreaRect(vector<vector<int>>& points) {
  // O(N)
  unordered_set<long long> hashP;

  int answer = INT_MAX;

  // O(N)
  for (const vector<int>& p : points) {
    int x1 = p[0], y1 = p[1];

    // O(N)
    for (long long cur : hashP) {
      int x2 = cur / MOD;
      int y2 = cur % MOD;

      if (x2 == x1 || y2 == y1) continue;

      if (hashP.count(x1 * MOD + y2) && hashP.count(x2 * MOD + y1)) {
        answer = min(answer, abs((x1 - x2) * (y1 - y2)));
      }
    }

    hashP.emplace(x1 * MOD + y1);  // insert
  }

  return answer == INT_MAX ? 0 : answer;
}
```

## 고생한 점
