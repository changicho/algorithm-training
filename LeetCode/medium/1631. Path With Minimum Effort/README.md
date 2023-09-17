# 1631. Path With Minimum Effort

[링크](https://leetcode.com/problems/path-with-minimum-effort/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열 heights의 총 크기를 N이라 하자. (N = R \* C) 그 중 가장 높은 높이를 M이라 하자.

일반적인 BFS를 이용해 갱신하며 탐색할 경우 재갱신이 일어날 수 있으므로 O(3^N)의 시간 복잡도를 사용한다.

이를 최적화하기 위해 다음과 같은 방법을 사용한다.

다이크스트라 알고리즘을 이용해 최소 비용을 갱신하며 탐색할 경우 O(E \* log_2(V))의 시간 복잡도를 사용한다.

여기서 간선과 정점은 N이므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

혹은 이분 탐색을 이용할 수 있다. 특정 값 이하의 diff로 탐색 가능한 지 판단하는데 O(N)의 시간 복잡도를 사용하며, 값의 범위는 0 ~ M이다.

따라서 O(N \* log_2(M))의 시간 복잡도를 사용할 수 있다.

### 공간 복잡도

탐색시 중복을 방지하기 위해 O(N)의 공간 복잡도를 사용한다.

다이크스트라 알고리즘을 사용시에 힙에 O(N)의 공간 복잡도를 사용한다.

### 다이크스트라

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     136      | O(N \* log_2(N)) |    O(N)     |

하나의 좌표에서 다음 좌표로 넘어갈 때 diff의 최대값을 갱신하며 탐색한다.

이 때 해당 diff의 최대 값이 cost이며 가장 작은 cost를 우선해 탐색한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  int y, x, cost;

  bool operator<(const Status &other) const { return cost > other.cost; }
};

Axis dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dp[105][105] = {
    0,
};

int minimumEffortPath(vector<vector<int>> &heights) {
  int rows = heights.size(), cols = heights[0].size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      dp[y][x] = INT_MAX;
    }
  }

  priority_queue<Status> pq;
  pq.push({0, 0, 0});
  dp[0][0] = 0;

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();

    int y = cur.y, x = cur.x;

    if (y == rows - 1 && x == cols - 1) continue;

    for (Axis &dir : dirs) {
      int ny = y + dir.y, nx = x + dir.x;

      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;

      int diff = abs(heights[y][x] - heights[ny][nx]);
      int cost = max(dp[y][x], diff);

      if (cost < dp[ny][nx]) {
        dp[ny][nx] = cost;
        pq.push({ny, nx, cost});
      }
    }
  }
  return dp[rows - 1][cols - 1];
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     203      | O(N \* log_2(M)) |    O(N)     |

특정 diff 이하의 경로로만 탐색이 가능한 지 판단하는데 O(N)의 시간 복잡도를 사용한다.

따라서 가능한 diff에 대해 이분 탐색을 수행하며 각 과정마다 도달 가능한지 탐색을 수행한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool check(vector<vector<int>> &heights, int target) {
  int rows = heights.size(), cols = heights[0].size();

  queue<Axis> q;
  bool visited[101][101] = {
      false,
  };
  q.push({0, 0});
  visited[0][0] = true;

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (cur.y == rows - 1 && cur.x == cols - 1) {
      return true;
    }

    for (Axis &dir : dirs) {
      int ny = cur.y + dir.y, nx = cur.x + dir.x;
      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
      if (visited[ny][nx]) continue;

      int diff = abs(heights[ny][nx] - heights[cur.y][cur.x]);
      if (diff <= target) {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
  return false;
}

int minimumEffortPath(vector<vector<int>> &heights) {
  int left = 0, right = 1000000;
  int answer = right;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (check(heights, mid)) {
      answer = min(answer, mid);
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
