# 3341. Find Minimum Time to Reach Last Room I

[링크](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 좌표의 수를 N이라 하자.

다이크스트라 알고리즘을 사용해 최단 경로를 구할 경우 O(N \* log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

다이크스트라 알고리즘에 O(N)의 공간 복잡도가 필요하다.

### 다이크스트라

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      19      | O(N \* log_2(N)) |    O(N)     |

다이크스트라 알고리즘을 사용해 최단 경로를 구하며, 다음 좌표가 현재까지 시간으로 도달 불가능한 경우 다음 좌표가 열리는 시간까지 대기 후 이동하는 것으로 최단 경로를 구한다.

```cpp
struct Status {
  int y, x, cost;

  bool operator<(const Status &b) const { return cost > b.cost; }
};

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int minTimeToReach(vector<vector<int>> &moveTime) {
  int rows = moveTime.size(), cols = moveTime[0].size();

  vector<vector<int>> costs(rows, vector<int>(cols, INT_MAX));

  priority_queue<Status> pq;
  pq.push({0, 0, 0});

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};
      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      int nextCost = max(moveTime[next.y][next.x], cur.cost) + 1;

      if (costs[next.y][next.x] <= nextCost) continue;
      costs[next.y][next.x] = nextCost;

      pq.push({next.y, next.x, nextCost});
    }
  }

  return costs[rows - 1][cols - 1];
}
```

## 고생한 점
