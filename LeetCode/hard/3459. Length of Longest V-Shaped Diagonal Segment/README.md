# 3459. Length of Longest V-Shaped Diagonal Segment

[링크](https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

동적 계획법을 사용해 탐색할 경우 각 좌표마다 4 \* 2가지 경우가 발생한다.

총 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용해 탐색할 경우 O(R \* C)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     234      |  O(R \* C)  |  O(R \* C)  |

각 좌표마다 다음과 같은 상태가 존재한다.

- 해당 좌표로 진입한 방향
- 현재 경로에서 90도 회전을 사용했는지 여부

각 시작점마다 DFS로 탐색을 수행하며 dp값을 갱신한다.

이 때 dp값은 해당 좌표, 상태일 때 만들 수 있는 최대 길이로 설정한다.

만약 현재 좌표로 현재 상태에 이미 이전에 방문한 적이 있다면 dp 값을 반환한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

// y,x,dir,turn
int dp[500][500][4][2];

int dfs(vector<vector<int>>& grid, Axis cur, int dir, bool turn, int target) {
  int rows = grid.size(), cols = grid[0].size();
  Axis next = {cur.y + dirs[dir].y, cur.x + dirs[dir].x};

  if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) return 0;
  if (grid[next.y][next.x] != target) return 0;

  if (dp[next.y][next.x][dir][turn] != -1) return dp[next.y][next.x][dir][turn];
  int nextTarget = 2 - target;

  int length = dfs(grid, next, dir, turn, nextTarget);
  if (!turn) {
    length = max(length, dfs(grid, next, (dir + 1) % 4, true, nextTarget));
  }

  return dp[next.y][next.x][dir][turn] = length + 1;
};

int lenOfVDiagonal(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();
  memset(dp, -1, sizeof(dp));

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] != 1) continue;

      for (int dir = 0; dir < 4; dir++) {
        int curLength = dfs(grid, {y, x}, dir, false, 2) + 1;

        answer = max(answer, curLength);
      }
    }
  }

  return answer;
}
```

## 고생한 점
