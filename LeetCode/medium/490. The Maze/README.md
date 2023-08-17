# 490. The Maze

[링크](https://leetcode.com/problems/the-maze/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 좌표마다 상하좌우로 이동할 수 있으며 이동시켜 시뮬레이션을 진행할 수 있다.

각 좌표마다 이동하는데 O(R + C)의 시간 복잡도를 사용한다.

이 때 중복 경우를 제거하기 위해 방문한 좌표를 저장해야 한다.

중복을 제외한 좌표를 탐색하는데 O(R \* C)의 시간 복잡도를 사용한다.

BFS를 이용하는 경우 시간 복잡도는 O(R \* C \* (R + C))이다.

### 공간 복잡도

이동한 좌표를 저장하기 위해 배열을 사용할 경우 O(R \* C)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      31      | O(R \* C \* (R + C)) |  O(R \* C)  |

현재 좌표에서 특정 방향으로 기울일 경우 돌은 해당 방향으로 계속해서 굴러간다.

그러다 벽을 만나는 경우 멈추게 된다.

돌이 굴러가는 경우를 구현해놓고, 현재 방문한 좌표마다 4방향으로 돌을 굴려본다.

돌이 도달한 위치를 큐에 삽입하고, BFS를 진행한다.

이 때 중복해서 좌표를 방문할 수 있으므로 중복체크를 수행한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isSafe(Axis a, int rows, int cols) {
  return a.y >= 0 && a.y < rows && a.x >= 0 && a.x < cols;
}

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
  int rows = maze.size(), cols = maze[0].size();

  bool visited[101][101] = {false};

  queue<Axis> q;
  q.push({start[0], start[1]});

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (visited[cur.y][cur.x]) continue;
    visited[cur.y][cur.x] = true;

    for (Axis& dir : dirs) {
      Axis next = cur;

      while (isSafe(next, rows, cols) && maze[next.y][next.x] == 0) {
        next.y += dir.y;
        next.x += dir.x;
      }

      next.y -= dir.y;
      next.x -= dir.x;

      q.push(next);
    }
  }

  return visited[destination[0]][destination[1]];
}
```

## 고생한 점
