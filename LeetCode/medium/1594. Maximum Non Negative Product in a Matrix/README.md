# 1594. Maximum Non Negative Product in a Matrix

[링크](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

동적 계획법을 사용할 경우 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(RC)의 공간 복잡도를 사용한다.

값이 증가함에 따라 음수에서 양수로 변경되는 경우가 존재하므로 맨 마지막 정답에서 MOD연산을 수행한다.

최악의 경우 값 범위는 4^16 이므로 long long 자료형을 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(RC)    |    O(RC)    |

각 좌표마다 2가지 값을 저장해야한다.

- 가장 큰 수
- 가장 작은 수

또한 현재 값을 곱했을 때 현재 값의 부호에 따라 가장 큰 수와 가장 작은 수가 변경될 수 있다.

- 현재 값이 양수
  - 가장 큰값 : 이전 가장 큰값 \* 현재 값
  - 가장 작은값 : 이전 가장 작은값 \* 현재 값
- 현재 값이 음수
  - 가장 큰값 : 이전 가장 작은값 \* 현재 값 (부호 변경)
  - 가장 작은값 : 이전 가장 큰값 \* 현재 값 (부호 변경)

이를 이용해 각 과정마다 좌표의 값을 갱신한다.

```cpp
int maxProductPath(vector<vector<int>>& grid) {
  const int MOD = 1e9 + 7;
  int rows = grid.size(), cols = grid[0].size();

  // 0 : minus, 1 : plus
  long long dp[16][16][2];
  dp[0][0][0] = dp[0][0][1] = grid[0][0];

  for (int y = 1; y < rows; y++) {
    dp[y][0][0] = dp[y][0][1] = dp[y - 1][0][1] * grid[y][0];
  }
  for (int x = 1; x < cols; x++) {
    dp[0][x][0] = dp[0][x][1] = dp[0][x - 1][1] * grid[0][x];
  }

  for (int y = 1; y < rows; y++) {
    for (int x = 1; x < cols; x++) {
      long long cur = grid[y][x];

      if (cur >= 0) {
        dp[y][x][0] = min(dp[y - 1][x][0], dp[y][x - 1][0]) * cur;
        dp[y][x][1] = max(dp[y - 1][x][1], dp[y][x - 1][1]) * cur;
      } else {
        dp[y][x][0] = max(dp[y - 1][x][1], dp[y][x - 1][1]) * cur;
        dp[y][x][1] = min(dp[y - 1][x][0], dp[y][x - 1][0]) * cur;
      }
    }
  }
  int answer = dp[rows - 1][cols - 1][1] % MOD;
  if (answer < 0) return -1;
  return answer;
}
```

## 고생한 점
