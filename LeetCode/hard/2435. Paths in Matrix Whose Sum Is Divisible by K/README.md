# 2435. Paths in Matrix Whose Sum Is Divisible by K

[링크](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 R, 열의 갯수를 C, 수를 K라 하자.

동적 계획법을 사용할 경우 O(R \* C \* K)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(R \* C \* K)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도   |
| :----------: | :------------: | :------------: |
|     225      | O(R \* C \* K) | O(R \* C \* K) |

각 좌표를 방문하는 경우는 다음 2가지중 하나이다.

- 위에서 내려오는 경우
- 왼쪽에서 오는 경우

이 때 각 경우마다의 합을 K로 나눈 나머지를 기준으로 경우의 수를 저장한다.

이후 각 좌표마다 이전에 방문한 좌표에서의 경우의 수를 더해 현재 좌표에서의 경우의 수를 갱신한다.

```cpp
int numberOfPaths(vector<vector<int>>& grid, int k) {
  const int MOD = 1e9 + 7;

  int rows = grid.size(), cols = grid[0].size();

  vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k)));

  dp[0][0][grid[0][0] % k]++;

  for (int x = 1; x < cols; x++) {
    for (int i = 0; i < k; i++) {
      dp[0][x][(i + grid[0][x]) % k] += dp[0][x - 1][i];
      dp[0][x][(i + grid[0][x]) % k] %= MOD;
    }
  }
  for (int y = 1; y < rows; y++) {
    for (int i = 0; i < k; i++) {
      dp[y][0][(i + grid[y][0]) % k] += dp[y - 1][0][i];
      dp[y][0][(i + grid[y][0]) % k] %= MOD;
    }
  }

  for (int y = 1; y < rows; y++) {
    for (int x = 1; x < cols; x++) {
      for (int i = 0; i < k; i++) {
        // from top
        dp[y][x][(i + grid[y][x]) % k] += dp[y - 1][x][i];
        dp[y][x][(i + grid[y][x]) % k] %= MOD;
        // from left
        dp[y][x][(i + grid[y][x]) % k] += dp[y][x - 1][i];
        dp[y][x][(i + grid[y][x]) % k] %= MOD;
      }
    }
  }

  return dp[rows - 1][cols - 1][0];
}
```

## 고생한 점
