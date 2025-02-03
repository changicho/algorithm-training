# 3418. Maximum Amount of Money Robot Can Earn

[링크](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열 coins의 크기를 R \* C라 하자.

동적 계획법을 이용해 각 경우를 최적화 할 수 있다.

이 경우 O(R \* C)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

동적 계획법에 O(R \* C)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     444      |  O(R \* C)  |  O(R \* C)  |

각 좌표마다 도둑을 쫒아낸 경우의 수 (0, 1, 2)에 대해 각각의 최대값을 저장한다.

이후 현재 좌표의 최대값을 갱신할 때, 이전 좌표의 최대값에 현재 좌표의 값을 더한 값과 비교한다.

이 때 현재 좌표에 도둑이 존재하는 경우 이전 값들을 이용해 갱신한다.

```cpp
struct Axis {
  int y, x;
};

int maximumAmount(vector<vector<int>>& coins) {
  int rows = coins.size();
  int cols = coins[0].size();

  vector<vector<vector<int>>> dp(
      rows, vector<vector<int>>(cols, vector<int>(3, INT_MIN)));

  dp[0][0][0] = coins[0][0];
  if (coins[0][0] < 0) {
    dp[0][0][1] = 0;
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int beforeY = y - 1, beforeX = x - 1;
      bool isRobber = coins[y][x] < 0;

      if (beforeY >= 0) {
        if (isRobber) {
          for (int i = 1; i <= 2; i++) {
            dp[y][x][i] = max(dp[beforeY][x][i - 1], dp[y][x][i]);
          }
        }

        for (int i = 0; i <= 2; i++) {
          if (dp[beforeY][x][i] == INT_MIN) continue;
          dp[y][x][i] = max(dp[beforeY][x][i] + coins[y][x], dp[y][x][i]);
        }
      }
      if (beforeX >= 0) {
        if (isRobber) {
          for (int i = 1; i <= 2; i++) {
            dp[y][x][i] = max(dp[y][beforeX][i - 1], dp[y][x][i]);
          }
        }

        for (int i = 0; i <= 2; i++) {
          if (dp[y][beforeX][i] == INT_MIN) continue;
          dp[y][x][i] = max(dp[y][beforeX][i] + coins[y][x], dp[y][x][i]);
        }
      }
    }
  }

  int answer = INT_MIN;
  for (int i = 0; i <= 2; i++) {
    answer = max(answer, dp[rows - 1][cols - 1][i]);
  }
  return answer;
}
```

## 고생한 점
