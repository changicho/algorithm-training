# 787. Cheapest Flights Within K Stops

[링크](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 수를 N, 간선의 수를 E, 입력받은 수를 K라 하자. (N <= 100, K < N)

간선을 순회해 그래프를 생성해야 하며 이에 O(E)의 시간 복잡도를 사용한다.

각 간선의 cost는 양수이다.

시작점에서부터 BFS로 탐색을 진행하며 경로의 합이 최소가 되는 경우에만 갱신한다.

이를 최대 K단계 반복한다.

최악의 경우 각 간선들을 K번 방문하므로 O(E \* K)의 시간 복잡도를 사용한다.

벨만 포드 알고리즘을 사용할 경우 O(E \* K)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 이용할 경우 최악의 경우 O(E \* K)의 공간 복잡도를 사용한다.

각 노드마다의 값을 저장할 공간이 필요하므로 O(N), 그래프에 O(E)의 공간 복잡도를 사용한다.

따라서 공간 복잡도는 O(N + E \* K)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 |  공간 복잡도  |
| :----------: | :---------: | :-----------: |
|      34      |  O(E \* K)  | O(N + E \* K) |

BFS를 이용해 시작 노드에서부터 탐색한다.

이 때 각 노드를 방문한 경로의 비용이 최소가 될 때만 갱신해 불필요한 탐색을 줄인다.

```cpp
struct Edge {
  int from, to, cost;
};

struct Status {
  int node, cost, step;
};

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
  vector<vector<Edge>> graph(n);
  vector<int> minCosts(n, INT_MAX);

  for (vector<int> &f : flights) {
    int from = f[0], to = f[1], cost = f[2];

    graph[from].push_back({from, to, cost});
  }

  queue<Status> q;
  q.push({src, 0, 0});

  int answer = INT_MAX;
  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.step > k + 1) continue;
    if (minCosts[cur.node] < cur.cost) continue;
    minCosts[cur.node] = cur.cost;
    if (cur.node == dst) {
      answer = min(answer, cur.cost);
    }

    for (Edge &e : graph[cur.node]) {
      q.push({e.to, cur.cost + e.cost, cur.step + 1});
    }
  }

  return answer == INT_MAX ? -1 : answer;
}
```

### 벨만 포드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      54      |  O(E \* K)  |  O(N \* K)  |

벨만 포드 알고리즘을 사용해 간선들을 K번 순회하며 최소값을 갱신한다.

```cpp
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
  // dp[step][node]; Dist to reach node using atmost step edges from src
  vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
  for (int step = 0; step <= k + 1; step++) {
    dp[step][src] = 0;  // Dist to reach src always zero
  }

  for (int step = 1; step <= k + 1; step++) {
    for (vector<int> &f : flights) {
      int from = f[0], to = f[1], cost = f[2];

      if (dp[step - 1][from] != INT_MAX)
        dp[step][to] = min(dp[step][to], dp[step - 1][from] + cost);
    }
  }

  return (dp[k + 1][dst] == INT_MAX) ? -1 : dp[k + 1][dst];
}
```

## 고생한 점
