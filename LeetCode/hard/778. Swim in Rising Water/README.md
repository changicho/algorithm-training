# 778. Swim in Rising Water

[링크](https://leetcode.com/problems/swim-in-rising-water/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 정방 배열의 한 행의 크기를 N이라 하자.

총 좌표의 수는 N^2개이다.

힙을 이용한 BFS를 이용해 가장 최소 높이에서 각 좌표를 방문할 수 있다. 이 경우 O(N^2 \* log_2(N^2))의 시간 복잡도를 사용한다.

### 공간 복잡도

힙에 O(N^2)의 공간 복잡도를 사용한다.

### BFS & 힙

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      3       | O(N^2 \* log_2(N^2)) |   O(N^2)    |

힙을 이용해 빗물의 최소 높이로 각 좌표를 BFS로 방문한다.

각 좌표를 방문할 때 힙의 최소 높이로 방문하게 되므로 목적지에 도달했을 때의 높이가 최소 높이가 된다.

```cpp
struct Axis {
  int y, x;
};
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Status {
  int t;
  Axis a;

  bool operator<(const Status &b) const { return t > b.t; }
};

int swimInWater(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();
  priority_queue<Status> pq;
  bool visited[50][50] = {
      false,
  };
  pq.push({grid[0][0], {0, 0}});
  visited[0][0] = true;

  int answer = INT_MAX;
  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();

    if (cur.a.y == rows - 1 && cur.a.x == cols - 1) {
      answer = min(answer, cur.t);
    }

    for (Axis &dir : dirs) {
      Axis next = {cur.a.y + dir.y, cur.a.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;
      visited[next.y][next.x] = true;

      int cost = max(cur.t, grid[next.y][next.x]);

      pq.push({cost, next});
    }
  }

  return answer;
}
```

## 고생한 점
