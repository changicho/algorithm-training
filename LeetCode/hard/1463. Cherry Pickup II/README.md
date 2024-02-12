# 1463. Cherry Pickup II

[링크](https://leetcode.com/problems/cherry-pickup-ii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열 grid의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 이전의 결과를 이용해 풀이한다.

이 경우 같은 행에서 두 로봇의 위치의 경우는 C^2 가지 이며 이를 모든 행에 대해 탐색할 경우 시간 복잡도는 O(R \* C^2)이다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(R \* C^2)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      67      | O(R \* C^2) | O(R \* C^2) |

두 로봇이 각 행마다 존재할 수 있는 위치의 경우의 수는 C^2이다.

따라서 각 행마다 두 로봇의 좌표에 대해 이전의 결과를 이용해 다음 결과를 갱신한다.

다음과 같은 dp배열을 생성한다.

```cpp
// definition
int dp[y][x1][x2]; // y번째 행까지 왔을 때 x1, x2에 위치한 로봇이 가질 수 있는 최대 cherry의 갯수

// initialize
dp[y][0][cols-1] = grid[0][0] + grid[0][cols-1];
dp[y][x1][x2] = INT_MIN; // 나머지 경우는 불가능한 값으로 초기화

// update
// nx1 != nx2
// 같은 경우는 한번만 더함
dp[y + 1][nx1][nx2] = max(dp[y + 1][nx1][nx2], dp[y][x1][x2] + grid[y + 1][nx1] + grid[y + 1][nx2]);
```

이 때 처음 시작에서 두 로봇의 위치는 고정되어 있으므로 이를 고려해 모든 값을 INT_MIN으로 초기화한다.

이렇게 초기화 할 경우 처음 시작위치에서 도달할 수 없는 위치에서의 dp값은 정답에 포함되지 않는다.

```cpp
int cherryPickup(vector<vector<int>>& grid) {
  // dp[y][x1][x2]
  int dp[71][71][71] = {
      0,
  };

  int rows = grid.size(), cols = grid[0].size();

  for (int y = 0; y < rows - 1; y++) {
    for (int x1 = 0; x1 < cols; x1++) {
      for (int x2 = 0; x2 < cols; x2++) {
        dp[y][x1][x2] = INT_MIN;
      }
    }
  }
  dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];

  for (int y = 0; y < rows - 1; y++) {
    for (int x1 = 0; x1 < cols; x1++) {
      for (int x2 = 0; x2 < cols; x2++) {
        // x1 : -1 0 +1
        // x2 : -1 0 +1

        for (int diff1 = -1; diff1 <= 1; diff1++) {
          for (int diff2 = -1; diff2 <= 1; diff2++) {
            int nx1 = x1 + diff1, nx2 = x2 + diff2;
            if (nx1 < 0 || nx1 >= cols || nx2 < 0 || nx2 >= cols) continue;

            if (nx1 == nx2) {
              dp[y + 1][nx1][nx2] =
                  max(dp[y + 1][nx1][nx2], dp[y][x1][x2] + grid[y + 1][nx1]);
            } else {
              dp[y + 1][nx1][nx2] =
                  max(dp[y + 1][nx1][nx2],
                      dp[y][x1][x2] + grid[y + 1][nx1] + grid[y + 1][nx2]);
            }
          }
        }
      }
    }
  }

  int answer = 0;
  for (int x1 = 0; x1 < cols; x1++) {
    for (int x2 = 0; x2 < cols; x2++) {
      answer = max(answer, dp[rows - 1][x1][x2]);
    }
  }
  return answer;
}
```

## 고생한 점
