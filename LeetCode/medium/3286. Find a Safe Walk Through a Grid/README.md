# 3286. Find a Safe Walk Through a Grid

[링크](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 좌표의 크기를 RC라 하자.

다이크스트라 알고리즘을 사용할 경우 O(RC \* log_2(RC))의 시간 복잡도를 사용한다.

### 공간 복잡도

다이크스트라 알고리즘에 O(RC)의 공간 복잡도를 사용한다.

### 다이크스트라

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      4       | O(RC \* log_2(RC)) |    O(RC)    |

각 좌표의 비용을 cost로 상하좌우를 간선으로 시작점부터 다이크스트라 알고리즘을 수행한다.

이 때 비용을 더했을 때 음수가 되는 경로는 진행하지 않는다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis a;
  int h;

  bool operator<(const Status& b) const { return h < b.h; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool findSafeWalk(vector<vector<int>>& grid, int health) {
  int rows = grid.size(), cols = grid[0].size();

  priority_queue<Status> q;
  q.push({{0, 0}, health -= grid[0][0]});

  bool visited[51][51] = {
      false,
  };
  visited[0][0] = true;
  while (!q.empty()) {
    Status curS = q.top();
    q.pop();
    Axis cur = curS.a;

    for (Axis& d : dirs) {
      Axis next = {cur.y + d.y, cur.x + d.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;

      int nextH = curS.h - grid[next.y][next.x];
      if (nextH <= 0) continue;

      visited[next.y][next.x] = true;
      q.push({next, nextH});
    }
  }

  return visited[rows - 1][cols - 1];
}
```

## 고생한 점
