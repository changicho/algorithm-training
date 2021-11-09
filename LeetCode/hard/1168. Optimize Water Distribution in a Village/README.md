# 1168. Optimize Water Distribution in a Village

[링크](https://leetcode.com/problems/optimize-water-distribution-in-a-village/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 개수를 V, 간선의 개수를 E라고 하자.

이 문제는 결국 MST (minimum spanning tree)를 만드는 문제가 되므로 2가지 방법을 사용할 수 있다.

- 프림 알고리즘
- 크루스칼 알고리즘

프림의 알고리즘의 경우 MST를 생성하는 데 시간 복잡도는 O(E \* log_2(V)) 이다.

여기서 각 노드에 직접 물을 공급하는 경우 또한 추가해야 하므로 실제 간선의 개수는 (V + E)개가 된다.

따라서 시간 복잡도는 O((V + E) \* log_2(V + E))이다.

크루스칼 알고리즘의 경우 MST를 생성하는 데 시간 복잡도는 O(E \* log_2(E)) 이다.

이 또한 마찬가지로 각 노드에 직접 물을 공급하는 경우 또한 추가해야 하므로 실제 간선의 개수는 (V + E)개가 된다.

따라서 시간 복잡도는 동일하게 O((V + E) \* log_2(V + E))이다.

### 공간 복잡도

프림의 알고리즘에서 우선순위 큐에 간선을 집어넣어야 한다. 이에 O(V + E)의 공간 복잡도를 사용한다.

그래프를 그리는 경우 또한 간선의 개수만큼만 그리면 되므로 O(V + E)의 공간 복잡도를 사용한다.

크루스칼 알고리즘의 경우 유니온 파인드를 사용할 때 O(V + E)의 공간 복잡도를 사용하며 간선을 정렬하기 위해 vector에 저장하므로 O(V + E)의 공간 복잡도를 사용한다.

### 프림의 알고리즘

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|     144      | O((V + E) \* log_2(V + E)) |  O(V + E)   |

각 노드에 대해서 MST를 그릴 수도, 노드에 직접 물을 공급할 수 도 있다.

특정 노드의 경우 MST에 추가하는것보다 물을 직접 공급하는 쪽이 비용을 절감할 수 있다.

프림의 알고리즘, 크루스칼 알고리즘을 사용할 때 간선의 정보만 이용하므로 노드에 직접 물을 공급하는 경우는 별도로 처리해야 한다.

이를 위해 노드에 직접 물을 공급하는 방법을 투명한 간선에서 해당 노드까지의 edge로 생각한다.

해당 간선까지 추가한 후 MST를 그릴 경우 물을 직접 공급하는 경우 까지 고려한 MST를 생성할 수 있다.

프림의 알고리즘은 우선순위 큐에 모든 edge를 삽입한 뒤, cost가 낮은 순부터 MST에 추가하는 방법이다.

이 때 이전에 방문한 노드를 다시 방문하지 않으며 MST를 완성한다.

이를 위해 다음 자료구조를 사용한다.

```cpp
struct Edge {
  int to, cost;
};

struct Status {
  Edge edge;

  bool operator<(const Status& b) const { return edge.cost > b.edge.cost; }
};
```

이를 구현하면 다음과 같다.

```cpp
int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
  priority_queue<Status> pq;
  vector<bool> visited(n + 1, false);
  vector<vector<Edge>> graph(n + 1);

  for (int i = 0; i < wells.size(); i++) {
    graph[0].push_back({i + 1, wells[i]});
  }

  int answer = 0;
  for (vector<int>& pipe : pipes) {
    int from = pipe[0], to = pipe[1], cost = pipe[2];

    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  for (Edge cur : graph[0]) {
    pq.push({cur});
  }

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();
    Edge edge = cur.edge;

    if (visited[edge.to]) continue;
    visited[edge.to] = true;

    answer += edge.cost;

    for (Edge next : graph[edge.to]) {
      pq.push({next});
    }
  }
  return answer;
}
```

### 크루스칼 알고리즘

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|     116      | O((V + E) \* log_2(V + E)) |  O(V + E)   |

크루스칼 알고리즘을 사용하기 위해 간선 정보를 모두 저장한다.

이를 cost에 대해서 정렬한 뒤 (cost가 낮은쪽이 앞에 오도록)

cost가 낮은 간선부터 연결한다.

이 때 해당 노드들이 이미 연결되었는지 여부는 유니온 파인드로 구현한다.

```cpp
struct Edge {
  int from, to, weight;

  bool const operator<(const Edge& b) const { return weight < b.weight; }
};
vector<int> parents;

int find(int node) {
  if (parents[node] == node) return node;

  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  int parentA = find(a), parentB = find(b);

  if (parentA > parentB) swap(parentA, parentB);
  parents[parentB] = parentA;
}

int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
  vector<Edge> edges;

  parents.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    parents[i] = i;
  }

  for (int i = 0; i < wells.size(); i++) {
    edges.push_back({0, i + 1, wells[i]});
  }
  for (vector<int>& pipe : pipes) {
    edges.push_back({pipe[0], pipe[1], pipe[2]});
  }

  sort(edges.begin(), edges.end());
  int answer = 0;

  for (Edge edge : edges) {
    if (find(edge.from) == find(edge.to)) continue;

    merge(edge.from, edge.to);
    answer += edge.weight;
  }

  return answer;
}
```

## 고생한 점

각 노드에 직접 물을 공급하는 경우의 처리를 가상의 노드에서 해당 노드까지의 간선으로 보는 풀이가 어려웠다.
