# 1568. Minimum Number of Days to Disconnect Island

[링크](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열 grid 의 크기를 R \* C라 하자.

grid에서 섬이 몇개 존재하는지 BFS를 이용해 탐색할 경우 O(R \* C)의 시간 복잡도가 소요된다.

좌표 두개를 제거하면 어떠한 섬이라도 2개의 섬으로 분리할 수 있다.

따라서 특정 좌표를 제거했을 때 2개의 섬이 생성되는지를 모든 좌표마다 판별한다.

이 때 각 좌표마다 BFS를 수행할 경우 시간 복잡도는 O((R \* C)^2) 이다.

### 공간 복잡도

BFS에 방문 여부를 판별할 visited 배열이 필요하다.

이는 O(R \* C)의 공간 복잡도가 필요하다.

### 완전 탐색 & BFS

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     118      | O((R \* C)^2) |  O(R \* C)  |

grid에 섬이 2개 이상으로 만들어야 한다.

만약 이미 grid에 섬이 없거나 2개 이상인 경우 삭제시킬 좌표가 없다.

따라서 섬이 1개인 경우에만 고려한다.

어떠한 섬이라도 2개의 좌표를 삭제하면 2개의 섬으로 분리가 가능하다.

따라서 1개의 좌표를 삭제해서 2개의 섬으로 분리 가능한지만 판단한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getIslands(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  int island = 0;

  function<void(int, int)> checkVisited = [&](int y, int x) {
    queue<Axis> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[next.y][next.x]) continue;
        if (grid[next.y][next.x] == 0) continue;

        visited[next.y][next.x] = true;
        q.push(next);
      }
    }
  };

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;
      if (visited[y][x]) continue;

      island++;

      checkVisited(y, x);
    }
  }

  return island;
}

int minDays(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  if (getIslands(grid) != 1) return 0;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;

      grid[y][x] = 0;

      if (getIslands(grid) != 1) return 1;

      grid[y][x] = 1;
    }
  }

  return 2;
}
```

## 고생한 점
