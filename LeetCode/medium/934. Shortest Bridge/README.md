# 934. Shortest Bridge

[링크](https://leetcode.com/problems/shortest-bridge/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

우선 grid내의 2개의 섬을 덩어리로 나누기 위해 좌표를 탐색해야 한다.

이 때의 시간 복잡도는 O(N \* M)이다.

이후 하나의 섬에서 탐색을 시작해 다른 섬까지 걸리는 거리를 구할 수 있다.

이 경우 시간 복잡도는 O(N \* M)이다.

따라서 최종 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

탐색의 방법으로 BFS, DFS를 이용할 수 있다.

이 경우 공간 복잡도는 O(N \* M)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |  O(N \* M)  |  O(N \* M)  |

먼저 입력받은 grid에서 첫번째 섬의 영역을 찾는다.

이후 해당 영역과 연결된 첫번째 섬의 모든 영역을 찾는다.

이후 해당 영역들을 모두 한번씩 BFS로 탐색을 동시에 진행한다.

이 떄 grid에 해당 step에 대해서 표시해 이전에 방문한 영역에 겹치지 않도록 한다.

이후 두번째 섬의 영역에 도달한 경우 BFS탐색을 종료한다.

이 때 지나온 경로의 길이 - 1이 다리의 길이가 된다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int shortestBridge(vector<vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();

  queue<Axis> islands;
  for (int y = 0; y < rows && islands.empty(); y++) {
    for (int x = 0; x < cols && islands.empty(); x++) {
      if (grid[y][x] != 1) continue;

      queue<Axis> q;
      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (grid[cur.y][cur.x] == -1) continue;
        grid[cur.y][cur.x] = -1;

        islands.push(cur);

        for (Axis dir : dirs) {
          Axis next = {dir.y + cur.y, dir.x + cur.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
          if (grid[next.y][next.x] != 1) continue;

          q.push(next);
        }
      }
    }
  }

  int step = 0;
  bool isLinked = false;
  while (!isLinked) {
    step += 1;
    int size = islands.size();

    while (size-- && !isLinked) {
      Axis cur = islands.front();
      islands.pop();

      for (Axis dir : dirs) {
        Axis next = {dir.y + cur.y, dir.x + cur.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
        if (grid[next.y][next.x] < 0) continue;
        if (grid[next.y][next.x] == 1) {
          isLinked = true;
          break;
        }

        grid[next.y][next.x] = grid[cur.y][cur.x] - 1;
        islands.push(next);
      }
    }
  }
  return step - 1;
}
```

## 고생한 점
