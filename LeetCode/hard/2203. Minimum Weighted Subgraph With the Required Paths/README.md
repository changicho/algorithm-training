# 2203. Minimum Weighted Subgraph With the Required Paths

[링크](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

그래프의 정점의 갯수를 V, 간선의 갯수를 N이라 하자.

각 노드에서 다른 노드까지의 최단 경로의 가중치를 구해야한다.

이를 플로이드 워셜 알고리즘을 사용할 경우 O(N^3)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

다익스트라 알고리즘을 사용해 특정 정점에서부터 다른 노드까지의 최단경로를 구할 수 있다.

이를 src1, src2, dest에 대해서 구한다.

이 경우 O(E \* log_2(V))의 시간 복잡도를 사용한다.

### 공간 복잡도

다익스트라 알고리즘을 사용할 경우 O(V)의 공간 복잡도를 사용한다.

### 다익스트라 알고리즘

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     568      | O(E \* log_2(V)) |    O(V)     |

문제에서 원하는 구간을 다음과 같이 생각할 수 있다.

임의의 정점 X에서 src1 -> X, src2 ->X, X -> dest 인 최소의 X를 찾는 문제이다.

따라서 src1, src2, dest에 대해서 다이크스트라 알고리즘을 이용해 각 노드까지의 최소 경로를 찾는다.

여기서 dest에 대해서는 입력받은 엣지의 관계를 뒤집은 reversed 그래프를 이용한다.

다이크 스트라는 다음과 같이 구현한다.

```cpp
struct Edge {
  int from, to;
  long long cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

void dijkstra(vector<vector<Edge>> &graph, vector<long long> &costs, int src) {
  priority_queue<Edge> pq;

  pq.push({0, src, 0});
  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    if (costs[cur.to] <= cur.cost) continue;
    costs[cur.to] = cur.cost;

    for (Edge &next : graph[cur.to]) {
      if (costs[next.to] > cur.cost + next.cost) {
        pq.push({next.from, next.to, cur.cost + next.cost});
      }
    }
  }
}
```

이를 이용해 구현하면 다음과 같다.

```cpp
long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
  vector<vector<Edge>> graph(n), reversed(n);

  for (vector<int> &edge : edges) {
    int from = edge[0], to = edge[1], cost = edge[2];
    graph[from].push_back({from, to, cost});
    reversed[to].push_back({to, from, cost});
  }

  priority_queue<Edge> pq;
  vector<long long> costs1(n, LONG_MAX), costs2(n, LONG_MAX),
      costsR(n, LONG_MAX);

  dijkstra(graph, costs1, src1);
  dijkstra(graph, costs2, src2);
  dijkstra(reversed, costsR, dest);

  long long answer = LONG_MAX;
  for (int node = 0; node < n; node++) {
    if (costs1[node] == LONG_MAX || costs2[node] == LONG_MAX ||
        costsR[node] == LONG_MAX)
      continue;
    answer = min(answer, costs1[node] + costs2[node] + costsR[node]);
  }
  return answer == LONG_MAX ? -1 : answer;
}
```

## 고생한 점
