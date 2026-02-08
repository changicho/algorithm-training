# 3650. Minimum Cost Path with Edge Reversals

[링크](https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 정점을 V, 간선의 수를 E라 하자.

다이크스트라 알고리즘을 힙을 이용해 구현할 경우 O(E + V \* log_2(E))의 시간 복잡도를 가진다.

### 공간 복잡도

다이크스트라 알고리즘에 O(V + E)의 공간 복잡도를 사용한다.

### 다이크스트라 알고리즘

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     286      | O(E + V \* log_2(E)) |  O(V + E)   |

그래프는 방향 그래프이며, 역방향 간선을 추가할 때 코스트는 2배가 된다.

간선정보를 이용해 그래프를 생성 후 다이크스트라 알고리즘을 이용해 시작 정점에서 마지막 정점까지 최소 코스트를 구한다.

이후 마지막 정점의 코스트가 갱신되지 않았다면 -1을 반환하고, 갱신되었다면 해당 코스트를 반환한다.

```cpp
struct Edge {
  int from, to, cost;

  bool operator<(const Edge& b) const { return b.cost < cost; }
};

int minCost(int n, vector<vector<int>>& edges) {
  vector<vector<Edge>> graph(n);
  for (vector<int>& e : edges) {
    int from = e[0], to = e[1], cost = e[2];

    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost * 2});
  }

  priority_queue<Edge> pq;
  pq.push({0, 0, 0});

  vector<int> costs(n + 1, INT_MAX);

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    if (costs[cur.to] < cur.cost) continue;

    for (Edge& next : graph[cur.to]) {
      int nextCost = cur.cost + next.cost;
      if (nextCost >= costs[next.to]) continue;
      costs[next.to] = nextCost;

      pq.push({next.from, next.to, nextCost});
    }
  }

  if (costs[n - 1] == INT_MAX) return -1;
  return costs[n - 1];
}
```

## 고생한 점
