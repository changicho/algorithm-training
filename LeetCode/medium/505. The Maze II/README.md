# 505. The Maze II

[링크](https://leetcode.com/problems/the-maze-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라고 하자.

BFS를 이용해 모든 경우를 탐색할 경우 시간 복잡도는 O(R \* C \* max(R, C)) 이다.

이 때 불필요한 방문을 제거하기 위해 dp배열을 사용한다. (백트래킹)

혹은 다익스트라 알고리즘을 이용해 모든 경우를 탐색할 경우 시간 복잡도는 O(R \* C \* log(R \* C)) 이다.

### 공간 복잡도

탐색에 O(R \* C)의 공간 복잡도를 사용한다.

최소 방문 횟수를 저장하는 데 O(R \* C)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      23      | O(R \* C \* max(R, C)) |  O(R \* C)  |

BFS를 이용해 모든 경우를 탐색한다.

이 때 각 좌표를 이전에 방문했고, 최소 방문 횟수보다 큰 경우에는 현재 경우에서 더이상 탐색하지 않는다.

```cpp
struct Status {
  int y, x, move = 0;
};

Status dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isSafe(Status a, int rows, int cols) {
  return a.y >= 0 && a.y < rows && a.x >= 0 && a.x < cols;
}

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
  int rows = maze.size(), cols = maze[0].size();

  int dp[101][101] = {
      0,
  };
  memset(dp, -1, sizeof(dp));

  queue<Status> q;
  q.push({start[0], start[1], 0});
  dp[start[0]][start[1]] = 0;

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    for (Status& dir : dirs) {
      Status next = cur;

      while (isSafe(next, rows, cols) && maze[next.y][next.x] == 0) {
        next.y += dir.y;
        next.x += dir.x;
      }

      next.y -= dir.y;
      next.x -= dir.x;

      int newMove = abs(next.y - cur.y) + abs(next.x - cur.x);

      if (dp[next.y][next.x] != -1 &&
          dp[next.y][next.x] <= cur.move + newMove)
        continue;

      dp[next.y][next.x] = cur.move + newMove;

      q.push({next.y, next.x, cur.move + newMove});
    }
  }
  return dp[destination[0]][destination[1]];
}
```

## 고생한 점
