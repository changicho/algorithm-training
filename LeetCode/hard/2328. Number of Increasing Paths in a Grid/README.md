# 2328. Number of Increasing Paths in a Grid

[링크](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 크기를 N이라 하자. (행의 갯수 R, 열의 갯수 C일 때 N = R \* C)

각 좌표마다 증가하는 경로의 갯수를 구해야 한다. 이를 위해 현재 좌표를 끝점으로 하는 경로의 갯수를 구할 수 있다.

이를 각 좌표마다 갱신하며 모든 좌표의 경로의 수를 더할 수 있다.

이 때 값이 작은 좌표부터 순회해야 하므로 정렬 혹은 우선순위 큐를 이용할 수 있다. 이 경우 시간 복잡도는 O(N \* log_2(N))이다.

혹은 각 좌표마다 DFS를 순회하며 메모이제이션을 수행할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표마다의 경로의 수를 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     770      | O(N \* log_2(N)) |    O(N)     |

각 좌표를 지나가는 경로의 수를 구할 수 있다.

현재 좌표에서 방문 가능한 좌표들을 순회하며 다음 좌표에 방문 가능한 경우 현재 경우의 수를 다음 좌표에 더한다.

이 때 작은 값부터 좌표를 순회해야 하므로 우선순위 큐를 이용한다.

```cpp
int MOD = 1e9 + 7;

struct Axis {
  int y, x;
};

struct Data {
  Axis axis;
  int val;

  bool operator<(const Data &b) const { return val > b.val; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int countPaths(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  int dp[1000][1000] = {
      0,
  };

  priority_queue<Data> pq;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      dp[y][x] = 1;
      pq.push({{y, x}, grid[y][x]});
    }
  }

  while (!pq.empty()) {
    Data cur = pq.top();
    pq.pop();

    for (Axis &dir : dirs) {
      Axis next = {cur.axis.y + dir.y, cur.axis.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (grid[next.y][next.x] <= cur.val) continue;
      dp[next.y][next.x] += dp[cur.axis.y][cur.axis.x];
      dp[next.y][next.x] %= MOD;
    }
  }

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer += dp[y][x];
      answer %= MOD;
    }
  }
  return answer;
}
```

### DFS & memoization

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     283      |    O(N)     |    O(N)     |

위 방법과 달리 현재 좌표를 방문할 때, 현재 좌표를 끝점으로 하는 경로의 수를 구한다.

이를 위해 방문 가능한 다음 좌표의 값이 현재 좌표보다 작은 경우에만 탐색을 진행한다.

이후 4방향에서 탐색한 경우의 수를 모두 더한 값이 현재 좌표를 끝점으로 하는 경로의 수 이다.

이 때 좌표를 방문했을 때의 반환값을 저장해놓아 중복 계산을 줄인다.

```cpp
int MOD = 1e9 + 7;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int memo[1001][1001];

// find ways of decreasing path from cur (prev -> cur)
int recursive(vector<vector<int>> &grid, Axis cur) {
  int rows = grid.size(), cols = grid[0].size();

  if (memo[cur.y][cur.x] != -1) return memo[cur.y][cur.x];

  int ret = 1;
  for (Axis &dir : dirs) {
    Axis prev = {cur.y + dir.y, cur.x + dir.x};
    if (prev.y < 0 || prev.y >= rows || prev.x < 0 || prev.x >= cols)
      continue;
    if (grid[prev.y][prev.x] >= grid[cur.y][cur.x]) continue;

    ret += recursive(grid, prev);
    ret %= MOD;
  }

  return memo[cur.y][cur.x] = ret;
}

int countPaths(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();
  memset(memo, -1, sizeof(memo));

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer += recursive(grid, {y, x});
      answer %= MOD;
    }
  }
  return answer;
}
```

## 고생한 점
