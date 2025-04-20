# 2737. Find the Closest Marked Node

[링크](https://leetcode.com/problems/find-the-closest-marked-node/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 수를 V, 간선의 수를 E라 하자.

다이크스트라알고리즘을 사용해 최단경로와 해당하는 경로의 경우의 수를 셀 수 있다.

이 경우 O(E \* log_2(V))의 시간 복잡도가 소요된다.

### 공간 복잡도

다이크스트라 알고리즘에 O(V + E)의 공간 복잡도가 필요하다.

### 다이크스트라

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      10      | O(E \* log_2(V)) |  O(E + V)   |

다이크스트라 알고리즘을 사용해 0번 노드에서 다른 노드들 까지의 최단경로를 구한다.

이후 해당 최단경로와 같은 cost를 가진 경로들 또한 같이 센다.

```cpp
struct Edge {
  int from, to, cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

int minimumDistance(int n, vector<vector<int>> &edges, int s, vector<int> &marked) {
  vector<vector<Edge>> graph(n);
  for (vector<int> &e : edges) {
    int from = e[0], to = e[1], cost = e[2];

    graph[from].push_back({from, to, cost});
  }

  vector<int> costs(n, INT_MAX);
  priority_queue<Edge> pq;
  pq.push({-1, s, 0});

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    if (costs[cur.to] < cur.cost) continue;

    for (Edge &next : graph[cur.to]) {
      int nCost = cur.cost + next.cost;

      if (costs[next.to] < nCost) continue;
      costs[next.to] = nCost;
      pq.push({next.from, next.to, nCost});
    }
  }

  int answer = INT_MAX;
  for (int &node : marked) {
    answer = min(costs[node], answer);
  }
  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
