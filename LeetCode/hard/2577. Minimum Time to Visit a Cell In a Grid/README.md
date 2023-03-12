# 2577. Minimum Time to Visit a Cell In a Grid

[링크](https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 grid의 모든 원소의 수를 N이라 하자.

grid를 그래프 관계로 나타냈을 때 정점의 수는 N 이며, 간선의 수는 4 \* N 이하이다.

시작 점에서 부터 끝점 까지 도달 가능했을때의 최소 시간을 구하는 문제이다.

이는 일반 BFS를 이용할 경우, 재방문이 가능한 경우를 고려해야 하므로 각 경과 시간에 따른 상태들이 존재할 수 있다. 이는 O(N \* 10^5)의 시간 복잡도를 사용한다.

다익스트라를 사용해 각 경우마다 최소 시간을 갱신해나가면 O(N \* log_2(N))의 시간 복잡도를 사용할 수 있다.

### 공간 복잡도

다익스트라를 사용할 때 우선순위 큐에 O(N)의 공간 복잡도를 사용한다.

### 다익스트라

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     2003     | O(N \* log_2(N)) |    O(N)     |

주어진 문제에서 이동이 가능한 경우 몇번이고 왕복하며 시간을 증가시킬 수 있다.

따라서 시작점에서 다른점으로 이동 가능한 경우, 무한시 시간을 증가시킬 수 있으므로 정답은 -1이 아니다.

반대로 시작점에서 다른 점으로 이동 못하는 경우가 -1이다.

만약 현재 점에서 다음 점을 지금 이동시간으로 도달불가능한 경우 시간을 2초씩 증가시키며 이동이 가능한지 확인할 수 있다.

(현재 점에서 방문가능한 다른 점으로 이동했다 돌아오는데 들어가는 시간은 항상 짝수이므로)

따라서 현재 점에서 다음점으로 넘어갈 때, 모자란 최소시간만큼 더해 이동시킬 수 있다.

이 경우 같은 점을 도달했을 때 시간이 더 적게 걸리는 경우로만 이동시킬 때 최적경로를 구할 수 있다.

이를 위해 다익스트라를 이용해 구현한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Status {
  Axis axis;
  int time;

  bool operator<(const Status &b) const { return time > b.time; }
};

int minimumTime(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid.front().size();

  if (grid[1][0] > 1 && grid[0][1] > 1) return -1;

  vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
  priority_queue<Status> q;

  q.push({{0, 0}, 0});

  while (!q.empty()) {
    Status cur = q.top();
    q.pop();

    Axis axis = cur.axis;

    if (dp[axis.y][axis.x] <= cur.time) continue;
    dp[axis.y][axis.x] = cur.time;

    for (Axis &dir : dirs) {
      Axis next = {axis.y + dir.y, axis.x + dir.x};

      if (next.x < 0 || next.x >= cols || next.y < 0 || next.y >= rows)
        continue;

      if (grid[next.y][next.x] - 1 <= cur.time) {
        q.push({next, cur.time + 1});
      } else {
        // find minimum 2*x time that needed time to reach next cell
        int diff = (grid[next.y][next.x] - cur.time) / 2 * 2;

        q.push({next, cur.time + diff + 1});
      }
    }
  }

  return dp[rows - 1][cols - 1] == INT_MAX ? -1 : dp[rows - 1][cols - 1];
}
```

## 고생한 점
