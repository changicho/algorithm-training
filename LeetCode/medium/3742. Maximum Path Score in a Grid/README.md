# 3742. Maximum Path Score in a Grid

[링크](https://leetcode.com/problems/maximum-path-score-in-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하고 입력받은 수를 K라 하자.

동적 계획법을 사용할 경우 O(RCK)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(RCK)의 공간 복잡도를 사용한다.

직전 행만 사용할 경우 O(CK)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     741      |   O(RCK)    |   O(RCK)    |

다음과 같은 3중 동적 계획법 배열을 생성한다.

```cpp
dp[y][x][cost]; // max value to reach y,x with cost

dp[y][x][cost] = max(dp[y-1][x][beforeCost], dp[y][x-1][beforeCost]) + grid[y][x];
```

이를 이용해 각 좌표를 순회하며 cost마다 값을 갱신한다.

```cpp
int maxPathScore(vector<vector<int>>& grid, int k) {
  int rows = grid.size(), cols = grid[0].size();

  // y,x,cost
  vector<vector<int>> dp(cols, vector<int>(k + 1, -1));
  dp[0][0] = 0;

  for (int y = 0; y < rows; y++) {
    vector<vector<int>> newDp(cols, vector<int>(k + 1, -1));

    for (int x = 0; x < cols; x++) {
      for (int cost = 0; cost <= k; cost++) {
        int cur = grid[y][x];

        if (true) {
          int beforeCost = cost - (cur > 0);
          if (beforeCost <= k && beforeCost >= 0 && dp[x][beforeCost] != -1) {
            newDp[x][cost] = max(newDp[x][cost], dp[x][beforeCost] + cur);
          }
        }
        if (x - 1 >= 0) {
          int beforeCost = cost - (cur > 0);
          if (beforeCost <= k && beforeCost >= 0 &&
              newDp[x - 1][beforeCost] != -1) {
            newDp[x][cost] =
                max(newDp[x][cost], newDp[x - 1][beforeCost] + cur);
          }
        }
      }
    }

    swap(newDp, dp);
  }

  int answer = -1;
  for (int cost = 0; cost <= k; cost++) {
    if (dp[cols - 1][cost] != -1) answer = max(answer, dp[cols - 1][cost]);
  }
  return answer;
}
```

## 고생한 점
