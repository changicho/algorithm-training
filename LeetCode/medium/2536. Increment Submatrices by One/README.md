# 2536. Increment Submatrices by One

[링크](https://leetcode.com/problems/increment-submatrices-by-one/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 N^2, 쿼리의 수를 Q라 하자.

각 쿼리마다 직접 수행할 경우 O(Q \* N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

각 좌표마다의 diff를 관리 후 이를 이용해 실제 정답 배열을 계산할 수 있다.

각 행마다의 diff를 관리할 경우 O(N \* (Q + N))의 시간 복잡도를 사용한다.

2차원 diff를 사용하면 O(Q + N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N^2)의 공간 복잡도를 사용한다.

diff를 저장하는데 O(N^2)의 공간 복잡도를 사용한다.

### 2D diff

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      | O(Q + N^2)  |   O(N^2)    |

2차원 diffs배열을 다음과 같이 설정한다.

```cpp
int diffs[y][x]; // y,x 좌표부터 변화되는 값.
```

특정 좌표에 대해서 이전까지의 변화값을 이용해 계산할 수 있다.

특정 쿼리 (row1, col1, row2, col2)에 대해서 변화하는 값을 다음과 같이 표현할 수 있다.

```cpp
diffs[row1][col1]++;
diffs[row2 + 1][col1]--;
diffs[row1][col2 + 1]--;
diffs[row2 + 1][col2 + 1]++;
```

각 좌표에 대한 값을 계산할 때 현재 diff와 이전 y좌표에서 내려오는 diff와, 이전 x좌표에서 오는 diff, 그리고 이전 y,x 좌표에서 중복으로 더해진 diff를 빼주어야 한다.

이를 각각 다음과 같이 표현할 수 있다.

```cpp
int diff = diffs[y][x];
int fromTop = answer[y - 1][x];
int fromLeft = answer[y][x - 1];
int fromTopLeft = answer[y - 1][x - 1];

cur = diff + fromTop + fromLeft - fromTopLeft;
```

이를 이용해 정답을 구한다.

```cpp
vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
  int rows = n, cols = n;

  vector<vector<int>> diffs(rows + 1, vector<int>(cols + 1, 0));

  for (vector<int>& q : queries) {
    int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];

    diffs[row1][col1]++;
    diffs[row2 + 1][col1]--;
    diffs[row1][col2 + 1]--;
    diffs[row2 + 1][col2 + 1]++;
  }

  vector<vector<int>> answer(rows, vector<int>(cols, 0));
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int fromTop = (y == 0) ? 0 : answer[y - 1][x];
      int fromLeft = (x == 0) ? 0 : answer[y][x - 1];
      int fromTopLeft = (y == 0 || x == 0) ? 0 : answer[y - 1][x - 1];

      answer[y][x] = diffs[y][x] + fromTop + fromLeft - fromTopLeft;
    }
  }
  return answer;
}
```

### 1D diff

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      42      | O((Q + N) \* N) |   O(N^2)    |

각 행에 대한 diff를 관리하며 이를 이용해 정답을 계산한다.

```cpp
vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
  int rows = n, cols = n;

  vector<vector<int>> diffs(rows, vector<int>(cols + 1, 0));

  for (vector<int>& q : queries) {
    int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];

    for (int y = row1; y <= row2; y++) {
      diffs[y][col1]++;
      diffs[y][col2 + 1]--;
    }
  }

  vector<vector<int>> answer(rows, vector<int>(cols, 0));
  for (int y = 0; y < rows; y++) {
    int diff = 0;
    for (int x = 0; x < cols; x++) {
      diff += diffs[y][x];
      answer[y][x] = diff;
    }
  }
  return answer;
}
```

## 고생한 점
