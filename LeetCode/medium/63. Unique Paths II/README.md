# 63. Unique Paths II

[링크](https://leetcode.com/problems/unique-paths-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

세로의 길이를 R, 가로의 길이를 C이라 하자.

모든 경우를 탐색할 경우 2^(R + C)의 시간 복잡도가 소요되므로 제한시간 내에 불가능하다.

동적 계획법을 이용해 각 좌표마다의 경로의 수를 계산할 수 있다.

이 경우 O(R \* C)의 시간 내에 탐색할 수 있다.

### 공간 복잡도

동적 계획법을 이용할 경우 보드의 크기 만큼의 공간 복잡도를 이용한다. O(R \* C)

이를 최적화 할 경우 갱신에 2개의 row만 필요하므로 공간 복잡도를 낮출 수 있다. O(R)

### 동적 계획법 (full)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(R \* C)  |  O(R \* C)  |

일반식은 다음과 같이 구성할 수 있다.

```cpp
int dp[y][x]; // y,x 좌표로 오는 경로의 수

// not obstacle
dp[y][x] = dp[y][x - 1] + dp[y - 1][x];

// obstacle
dp[y][x] = 0;
```

이 때 바위가 시작 위치에 있을수도 있으므로 초기값을 설정할 때 주의해야 한다.

- 시작 위치에 바위가 있는 경우 경로가 없음
- 시작 위치에서 y, x축으로 이어지는 경로는 바위가 나타나지 않을 때까지 1가지 방법만 가능
- 바위가 나타나면 dp는 0

```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();

  int dp[101][101] = {
      0,
  };
  dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (obstacleGrid[y][x] == 1) continue;

      dp[y][x] += y - 1 < 0 ? 0 : dp[y - 1][x];
      dp[y][x] += x - 1 < 0 ? 0 : dp[y][x - 1];
    }
  }

  return dp[rows - 1][cols - 1];
}
```

### 동적 계획법 (minimum)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |    O(N)     |

y가 홀수일때와 짝수일 때에 대한 dp배열을 만들어 사용한다.

이 때 이전의 기록이 남아있을 수 있으므로 주의해야한다.

```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int row = obstacleGrid.size();
  int col = obstacleGrid.front().size();

  vector<vector<int>> dp(2, vector<int>(col, 0));

  dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
  if (row == 1 && col == 1) return dp[0][0];

  for (int y = 1; y < min(row, 2); y++) {
    if (obstacleGrid[y][0] != 0) break;
    dp[y][0] = dp[y - 1][0];
  }
  for (int x = 1; x < col; x++) {
    if (obstacleGrid[0][x] != 0) break;
    dp[0][x] = dp[0][x - 1];
  }

  for (int y = 1; y < row; y++) {
    for (int x = 0; x < col; x++) {
      if (obstacleGrid[y][x]) {
        dp[y % 2][x] = 0;
        continue;
      }
      int cur = 0;
      if (x > 0) {
        cur += dp[y % 2][x - 1];
      }
      cur += dp[(y + 1) % 2][x];
      dp[y % 2][x] = cur;
    }
  }

  return dp[(row - 1) % 2][col - 1];
}
```

## 고생한 점

돌이 있는경우에서 현재 좌표로 오는 경우에 대한 처리가 필요함.

또한 시작위치와 끝 위치에 돌이 있는경우에 대한 처리 또한 필요.

dp배열의 크기를 최소화 하는 경우 2단계 전의 기록이 현재에 영향을 미칠 수 있으므로 이를 주의해야함.
