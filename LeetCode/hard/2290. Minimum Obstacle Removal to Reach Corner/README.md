# 2290. Minimum Obstacle Removal to Reach Corner

[링크](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 원소의 수를 N이라 하자.

각 좌표마다 4방향으로 이동 가능하다. 이를 간선으로 표현할 경우 총 4 \* N개의 간선이 존재한다.

다이크스트라 알고리즘을 사용해 최단 거리를 구할 경우 시간 복잡도는 O(N \* log_2(N)) 이다.

### 공간 복잡도

다이크스트라 알고리즘에 O(N)의 공간 복잡도가 필요하다.

### 다이크스트라 알고리즘

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     252      | O(N \* log_2(N)) |    O(N)     |

다이크스트라 알고리즘을 이용해 최단 거리를 구할 수 있다.

중간에 장애물이 존재하는 경우는 cost를 1 증가시키고, 그 외의 경우는 cost를 증가시키지 않는다.

이를 이용해 각 좌표마다 최단 거리를 구한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Edge {
  Axis a;
  int cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

int minimumObstacles(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  priority_queue<Edge> pq;
  vector<vector<int>> dp(rows, vector<int>(cols, rows * cols + 1));

  pq.push({{0, 0}, 0});
  dp[0][0] = 0;
  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Axis &dir : dirs) {
      Axis next = {cur.a.y + dir.y, cur.a.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      int nextCost = cur.cost + (grid[next.y][next.x] == 1);

      if (dp[next.y][next.x] <= nextCost) continue;
      dp[next.y][next.x] = nextCost;
      pq.push({next, nextCost});
    }
  }

  return dp[rows - 1][cols - 1];
}
```

## 고생한 점
