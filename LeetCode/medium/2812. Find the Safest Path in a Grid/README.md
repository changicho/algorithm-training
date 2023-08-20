# 2812. Find the Safest Path in a Grid

[링크](https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 정사각형 배열의 한 변의 크기를 N이라 하자.

BFS를 이용해 각 지점에서 도둑까지 최단거리를 구할 수 있다. 이에 O(N^2)의 시간 복잡도를 사용한다.

이후 시작점에서 끝점까지 최적의 경로를 구하기 위해 다이크스트라 알고리즘을 사용한다.

이 경우 노드의 갯수는 N^2, 간선의 갯수는 N^2 이다.

따라서 총 시간 복잡도는 O(N^2 \* log_2(N^2))가 된다.

### 공간 복잡도

다이크스트라 알고리즘에 O(N^2)의 공간복잡도를 사용한다.

### BFS & 다이크스트라

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     768      | O(N^2 \* log_2(N^2)) |   O(N^2)    |

각 도둑들의 위치에서 BFS를 진행하며 각 좌표에서 가장 가까운 도둑까지의 최소 거리를 갱신한다.

이후 각 좌표마다의 도둑까지의 최소거리 배열을 생성한 뒤 다이크스트라 알고리즘을 이용해 최적의 경로를 구한다.

이 때 경로의 값 중 최소값이 최대가 되는 경로를 구해야 하므로 가장 cost가 높은 경로를 우선해 탐색을 진행한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Status {
  int y, x, cost;

  bool operator<(const Status &b) const { return cost < b.cost; }
};

int maximumSafenessFactor(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<vector<int>> costs(rows, vector<int>(cols, INT_MAX));

  queue<Axis> q;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 1) q.push({y, x});
    }
  }

  int step = 0;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Axis cur = q.front();
      q.pop();

      if (costs[cur.y][cur.x] != INT_MAX) continue;
      costs[cur.y][cur.x] = step;

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (costs[next.y][next.x] != INT_MAX) continue;
        q.push(next);
      }
    }

    step++;
  }

  priority_queue<Status> pq;
  int visited[401][401] = {
      0,
  };
  pq.push({0, 0, costs[0][0]});
  visited[0][0] = costs[0][0];
  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;

      int nextCost = min(cur.cost, costs[next.y][next.x]);
      if (nextCost <= visited[next.y][next.x]) continue;
      visited[next.y][next.x] = nextCost;
      pq.push({next.y, next.x, nextCost});
    }
  }

  return visited[rows - 1][cols - 1];
}
```

## 고생한 점
