# 3665. Twisted Mirror Path Count

[링크](https://leetcode.com/problems/twisted-mirror-path-count/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하자.

동적 계획법을 사용할 경우 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(RC)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |    O(RC)    |    O(RC)    |

각 좌표마다 R,D 방향에서 왔을 때의 경우의 수를 저장한다.

이후 현재 좌표에 거울이 있는 경우와 없는 경우에 대해 구분하며 다음 이동 좌표에 대해 경우의 수를 갱신한다.

이 때 맨 처음 시작위치에서는 각 방향 통틀어서 총 1번만이 존재함에 유의한다.

```cpp
int uniquePaths(vector<vector<int>>& grid) {
  const int MOD = 1e9 + 7;
  // 0 : right, 1 : down
  int dp[501][501][2] = {
      0,
  };

  int rows = grid.size();
  int cols = grid[0].size();

  dp[0][0][0] = 1;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      for (int dir = 0; dir <= 1; dir++) {
        bool isMirror = grid[y][x] == 1;

        if (x + 1 < cols && !(isMirror && dir == 0)) {
          dp[y][x + 1][0] += dp[y][x][dir];
          dp[y][x + 1][0] %= MOD;
        }
        if (y + 1 < rows && !(isMirror && dir == 1)) {
          dp[y + 1][x][1] += dp[y][x][dir];
          dp[y + 1][x][1] %= MOD;
        }
      }
    }
  }

  int answer = 0;
  for (int dir = 0; dir <= 1; dir++) {
    answer += dp[rows - 1][cols - 1][dir];
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
