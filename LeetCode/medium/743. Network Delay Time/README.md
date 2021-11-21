# 743. Network Delay Time

[링크](https://leetcode.com/problems/network-delay-time/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 V, 간선의 개수를 E라 하자.

시작노드에서 다른 모든 노드들까지의 cost들을 구하고 만약 방문하지 않은 노드가 있는 경우, 혹은 cost중에 최대값을 고르면 된다.

이를 위해서 직접 모든 경우를 탐색하는 방법과 다익스크라 알고리즘을 사용할 수 있다.

만약 직접 모든 경우를 탐색할 경우 한 노드에서 다른 모든 노드로 탐색이 가능하므로 O(V^V)의 시간 복잡도를 사용한다.

다익스트라 알고리즘을 사용할 경우 간선에 대해서 우선순위 큐를 사용해 시간 복잡도를 줄일 수 있다.

우선순위 큐를 사용할 경우 O(V \* log_2(E))의 시간 복잡도를 사용한다.

만약 모든 간선을 방문해 다익스트라를 구현할 경우 O(V^2 + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프 관계를 표현하는 데 O(E)의 공간 복잡도를 사용한다. 그리고 비용을 표현하는 데 O(V)의 공간 복잡도를 사용한다.

따라서 O(V + E)의 공간 복잡도를 사용한다.

### 다익스트라

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     104      | O(V \* log_2(E)) |  O(V + E)   |

힙을 이용해 다익스트라의 시간 복잡도를 최적화한다.

다익스트라 알고리즘은 하나의 노드에서 다른 모든 노드로 방문하는 최소 비용을 구하는 방법이다.

1. 시작점에서부터 다익스트라를 이용해 모든 비용을 구한다.
2. 방문하지 않은 노드가 있다면 -1을 반환한다.
3. 비용 중에서 최대 값을 구한다.

현재 시작 노드에서 다른 노드로 방문할 때 cost를 적은 값으로 갱신할 수 있는 경우에만 탐색을 이어나간다. (pq에 간선을 삽입함)

```cpp
struct Edge {
  int from, to, cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

int networkDelayTime(vector<vector<int>> &times, int n, int k) {
  // graph[n + 1] = {edge{from, to, cost}, ...}
  vector<vector<Edge>> graph(n + 1);
  // change times data to graph
  for (vector<int> &time : times) {
    int from = time[0], to = time[1], cost = time[2];
    graph[from].push_back({from, to, cost});
  }
  // costs[n + 1] = INT_MAX; costs from k to node
  vector<int> costs(n + 1, INT_MAX);
  // setInitial value of costs. start's cost is 0
  costs[k] = 0;

  // use dijkstra algorithm to find costs of node (destination)
  // we use priority queue
  // priority queue<Edge> pq
  priority_queue<Edge> pq;
  // insert start's edge into pq
  // and update costs of edge
  for (Edge &edge : graph[k]) {
    pq.push(edge);
    costs[edge.to] = edge.cost;
  }

  // do it until pq is not empty
  while (!pq.empty()) {
    // pop current edge
    Edge cur = pq.top();
    pq.pop();

    // iterate next edge's from current node
    for (Edge &edge : graph[cur.to]) {
      // compare new value, before value
      int newValue = costs[cur.to] + edge.cost;  // k ~ edge.from ~ edge.to
      int beforeValue = costs[edge.to];          // k ~ edge.to

      // if new value < before value update and push edge
      if (newValue < beforeValue) {
        costs[edge.to] = newValue;
        pq.push(edge);
      }
    }
  }

  // check there are unvisited nodes. if it is return -1
  int answer = 0;
  for (int i = 1; i <= n; i++) {
    int cost = costs[i];

    if (cost == INT_MAX) return -1;
    answer = max(answer, cost);
  }
  // return maximum value of costs
  return answer;
}
```

## 고생한 점
