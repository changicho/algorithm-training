# 2699. Modify Graph Edge Weights

[링크](https://leetcode.com/problems/modify-graph-edge-weights/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 노드의 수를 V, 간선의 수를 E라 하자.

다이크스트라 알고리즘을 사용해 시작점에서부터 끝점까지 최소비용을 구할 수 있다.

이에 O(E \* log_2(V))의 시간 복잡도를 사용한다.

여기서 각 간선의 cost가 -1인 간선들을 그래프에 나중에 추가해가며 정답을 구할 수 있다.

이 경우 결국 간선을 순회하며 내부 탐색을 수행하므로 총 시간 복잡도는 O(E \* (E \* log_2(V))) 이다.

### 공간 복잡도

다이크스트라 알고리즘에 O(V)의 공간 복잡도를 사용한다.

### 다이크스트라 알고리즘

| 내 코드 (ms) |       시간 복잡도       | 공간 복잡도 |
| :----------: | :---------------------: | :---------: |
|     1583     | O(E \* (E \* log_2(V))) |    O(V)     |

source에서 detination까지 현재 그래프 상태에서 최소비용을 구하는 데 다이크스트라 알고리즘을 사용할 수 있다.

이 때 간선에서 비용이 -1인 간선들을 제외하고 우선 그래프를 생성한 뒤, 정답에 -1인 간선이 추가되어야 하는 경우에만 해당 간선들을 하나씩 그래프에 추가하고 다이크스트라 알고리즘을 사용할 수 있다.

만약 최초 그래프에 대해 시작점에서 끝점까지 비용에 따라 아래와 같은 경우들이 존재한다.

- 접근 불가능 (불가능)
- 비용이 target이하 (불가능)
- 비용이 target임 (불가능)
- 비용이 target (가능) : 이 경우 -1인 간선은 정답경로에 영향을 주면 안되므로 최대값으로 치환하고 정답으로 반환한다.

여기서 간선의 비용이 -1인 간선들을 추가해도 최소비용은 target 이하가 되는 경우 정답으로 생성이 불가능하다.

이후 간선을 추가해가며 위 과정을 반복한다. 이 때 추가한 간선의 비용은 최솟값인 1로 설정한다.

만약 현재 간선을 추가했을 때 목적지까지 최소 비용이 target이하인 경우, 현재 추가한 간선의 비용을 조정하고 나머지 간선들을 모두 정답에 영향을 끼치지 않는 최대값으로 변환한다.

이후 간선정보를 반환한다.

이 모든 과정에서 target을 못찾은 경우 불가능을 반환한다.

```cpp
struct Edge {
  int from, to, cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

vector<vector<Edge>> graph;

vector<int> dijkstra(int source, int destination) {
  vector<int> costs(graph.size(), INT_MAX);
  priority_queue<Edge> pq;
  pq.push({-1, source, 0});

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    if (costs[cur.to] <= cur.cost) continue;
    costs[cur.to] = cur.cost;

    for (Edge &next : graph[cur.to]) {
      int nextCost = next.cost == -1 ? 0 : cur.cost + next.cost;
      pq.push({next.from, next.to, nextCost});
    }
  }
  return costs;
}

vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target) {
  graph.resize(n);
  vector<Edge> froms(n, {-1, -1, -1});

  for (vector<int> &e : edges) {
    int from = e[0], to = e[1], cost = e[2];

    if (cost == -1) {
      continue;
    }
    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost});
  }

  vector<int> costs = dijkstra(source, destination);

  if (costs[destination] < target) {
    return {};
  }
  if (costs[destination] == target) {
    // convert all -1 edge to maximum number
    for (auto &it : edges) {
      if (it[2] == -1) it[2] = 2e9;
    }

    return edges;
  }

  for (int i = 0; i < edges.size(); i++) {
    vector<int> &e = edges[i];
    int &from = e[0], &to = e[1], &cost = e[2];

    if (cost != -1) continue;

    cost = 1;
    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost});

    vector<int> costs = dijkstra(source, destination);

    if (costs[destination] <= target) {
      cost += (target - costs[destination]);

      for (int j = i + 1; j < edges.size(); j++) {
        // convert all -1 edge to maximum number
        if (edges[j][2] == -1) edges[j][2] = 2e9;
      }
      return edges;
    }
  }
  return {};
}
```

## 고생한 점
