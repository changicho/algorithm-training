# 1976. Number of Ways to Arrive at Destination

[링크](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

다이크스트라 알고리즘을 사용해 최단 거리와 해당 거리에 속하는 경로의 수를 구할 수 있다.

이 경우 O(E \* log_2(V))의 시간 복잡도가 소요된다.

### 공간 복잡도

다이크스트라 알고리즘에 O(V)의 공간 복잡도가 필요하다.

그래프에 O(E)의 공간 복잡도가 필요하다.

### 다이크스트라 알고리즘

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      4       | O(E * log_2(V)) |  O(V + E)   |

0번 노드를 시작점으로 다른 노드들까지의 최단경로를 다이크스트라 알고리즘을 사용해 구한다.

이 때 해당 노드에 접근하는 경우의 수를 저장하며, cost가 갱신될 때마다 이전 노드의 경우의 수로 갱신한다.

만약 cost가 같으며 이전 노드의 경우의 수가 여러개인 경우에는 이전 노드의 경우의 수를 더한다.

```cpp
const int MOD = 1e9 + 7;

struct Edge {
  int from, to;
  long long cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

int countPaths(int n, vector<vector<int>> &roads) {
  vector<vector<Edge>> graph(n);
  for (vector<int> &e : roads) {
    int a = e[0], b = e[1], c = e[2];

    graph[a].push_back({a, b, c});
    graph[b].push_back({b, a, c});
  }

  priority_queue<Edge> pq;

  vector<long long> costs(n, LLONG_MAX);
  vector<int> counts(n, 0);

  costs[0] = 0;
  counts[0] = 1;

  pq.push({-1, 0, 0});
  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    long long cost = cur.cost;
    int node = cur.to;

    if (cost > costs[node]) continue;

    for (Edge &next : graph[node]) {
      if (cost + next.cost < costs[next.to]) {
        costs[next.to] = cost + next.cost;
        counts[next.to] = counts[node];

        pq.push({next.from, next.to, costs[next.to]});
      } else if (cost + next.cost == costs[next.to]) {
        counts[next.to] += counts[node];
        counts[next.to] %= MOD;
      }
    }
  }

  return counts[n - 1];
}
```

## 고생한 점
