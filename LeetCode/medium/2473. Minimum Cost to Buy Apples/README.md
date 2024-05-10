# 2473. Minimum Cost to Buy Apples

[링크](https://leetcode.com/problems/minimum-cost-to-buy-apples/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

각 노드마다 다이크스트라 알고리즘을 사용할 수 있다.

이 때 다이크스트라 알고리즘에 O(E * log_2(V))의 시간 복잡도가 소요된다.

이를 모든 노드에 대해 수행하므로 시간 복잡도는 O(V * E * log_2(V))이다.

혹은 모든 노드를 시작점으로 한번의 다이크스트라를 사용해 모든 노드에 대해 최소 비용을 구할 수 있다.

이 경우 시간 복잡도는 O((V + E) * log_2(V + E))이다.

### 공간 복잡도

다이크스트라 알고리즘에 O(V + E)의 공간 복잡도를 사용한다.

### 다이크스트라 알고리즘

| 내 코드 (ms) |     시간 복잡도     | 공간 복잡도 |
| :----------: | :-----------------: | :---------: |
|     195      | O(V * E * log_2(V)) |  O(V + E)   |

각 노드마다 다이크스트라 알고리즘을 사용한다.

이후 가장 작은 cost로 정답을 갱신한다.

```cpp
struct Edge {
  int from, to;
  long long cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

vector<long long> minCost(int n, vector<vector<int>> &roads, vector<int> &appleCost, int k) {
  vector<vector<Edge>> graph(n);

  for (vector<int> &e : roads) {
    int from = e[0] - 1, to = e[1] - 1, cost = e[2];

    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost});
  }

  vector<long long> answer(n);

  for (int start = 0; start < n; start++) {
    vector<long long> costs(n, LLONG_MAX);
    costs[start] = 0;

    priority_queue<Edge> pq;
    pq.push({-1, start, 0});

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      for (Edge &e : graph[cur.to]) {
        long long nextCost = cur.cost + e.cost;

        if (costs[e.to] <= nextCost) continue;
        costs[e.to] = nextCost;

        pq.push({e.from, e.to, cur.cost + e.cost});
      }
    }

    long long ret = appleCost[start];
    for (int to = 0; to < n; to++) {
      if (costs[to] == LLONG_MAX) continue;
      ret = min(ret, costs[to] * (1 + k) + appleCost[to]);
    }
    answer[start] = ret;
  }
  return answer;
}
```

### 다이크스트라 알고리즘 (한번)

| 내 코드 (ms) |     시간 복잡도     | 공간 복잡도 |
| :----------: | :-----------------: | :---------: |
|     195      | O(V * E * log_2(V)) |  O(V + E)   |

모든 간선정보를 우선순위 큐에 삽입 후 다이크스트라 알고리즘을 한번 수행한다.

이 때 현재 방문한 노드와 연결된 노드에 대해 다음 값으로 갱신한다.

- 현재 노드를 거쳐갔을 때의 이웃 노드의 최소 cost

즉 각 경우마다 cost가 낮은 순으로 탐색하므로,

현재 노드를 거쳐가거나 현재 노드에서 사과를 사는 경우 cost는 갱신되었다고 볼 수 있다.

따라서 현재 노드를 이용한 다음 노드에 대한 cost를 계산한다.

```cpp
struct Edge {
  int from, to;
  long long cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

vector<long long> minCost(int n, vector<vector<int>> &roads, vector<int> &appleCost, int k) {
  vector<vector<Edge>> graph(n);

  for (vector<int> &e : roads) {
    int from = e[0] - 1, to = e[1] - 1, cost = e[2];

    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost});
  }

  vector<long long> answer(appleCost.begin(), appleCost.end());

  priority_queue<Edge> pq;
  for (int start = 0; start < n; start++) {
    pq.push({-1, start, appleCost[start]});
  }

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Edge &e : graph[cur.to]) {
      long long nextCost = answer[cur.to] + (k + 1) * e.cost;

      if (answer[e.to] > nextCost) {
        answer[e.to] = nextCost;

        pq.push({e.from, e.to, nextCost});
      }
    }
  }

  return answer;
}
```

## 고생한 점
