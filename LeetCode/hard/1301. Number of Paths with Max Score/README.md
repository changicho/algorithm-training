# 1301. Number of Paths with Max Score

[링크](https://leetcode.com/problems/number-of-paths-with-max-score/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 크기를 R \* C라 하자.

동적 계획법을 이용할 경우 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(RC)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(RC)    |    O(RC)    |

시작 위치와 끝 위치는 고정되어있으며 같은 좌표는 2번 이상 방문하지 않는다.

시작 위치부터 탐색을 진행하며 각 좌표별 가장 큰 cost와 해당 cost의 횟수를 갱신한다.

```cpp
vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {-1, -1}};

vector<int> pathsWithMaxScore(vector<string>& board) {
  const int MOD = 1e9 + 7;

  int rows = board.size(), cols = board[0].size();

  board[0][0] = board[rows - 1][cols - 1] = '0';

  // {val, count}
  pair<int, int> dp[101][101];
  dp[rows - 1][cols - 1] = {0, 1};

  for (int y = rows - 1; y >= 0; y--) {
    for (int x = cols - 1; x >= 0; x--) {
      for (vector<int>& d : dirs) {
        int ny = y + d[0], nx = x + d[1];

        if (ny < 0 || nx < 0) continue;
        if (board[ny][nx] == 'X') continue;

        int cur = board[ny][nx] - '0';

        int val = dp[y][x].first;
        int count = dp[y][x].second;
        if (count == 0) continue;

        if (dp[ny][nx].first < val + cur) {
          dp[ny][nx] = {val + cur, count % MOD};
        } else if (dp[ny][nx].first == val + cur) {
          dp[ny][nx].second += count;
          dp[ny][nx].second %= MOD;
        }
      }
    }
  }

  int val = dp[0][0].first, count = dp[0][0].second;
  return {val, count};
}
```

## 고생한 점
