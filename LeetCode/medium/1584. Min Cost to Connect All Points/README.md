# 1584. Min Cost to Connect All Points

[링크](https://leetcode.com/problems/min-cost-to-connect-all-points/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라고 하자.

최소 신장 트리(MST)를 구하는 문제이며 다음 두가지 알고리즘을 이용할 수 있다.

- 프림의 알고리즘 : O(E \* log_2(V))
- 크루스칼 알고리즘 : O(E \* log_2(E))

V를 노드의 개수, E를 간선의 개수라고 하자.

간선의 개수는 각 노드마다 V-1개가 존재하므로 V^2로 볼 수 있다.

### 공간 복잡도

두 방법 모두 우선순위 큐에 간선들의 정보가 들어가므로 O(E)의 공간 복잡도가 필요하다.

크루스칼 알고리즘의 경우 유니온 파인드에 O(V)의 공간 복잡도를 사용한다.

따라서 공간 복잡도는 O(N^2)이다.

### 프림의 알고리즘

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     1210     | O(N^2 \* log_2(N)) |   O(N^2)    |

처음에 모든 간선의 cost를 구할 경우 MST를 만들 때 필요하지 않은 간선 정보또한 만드므로,
각 노드에서 다음 노드로 진행할 때의 간선정보만 생성해 우선순위 큐에 넣는다.

```cpp
struct Edge {
  int to, cost;

  bool operator<(const Edge &b) const { return cost > b.cost; };
};

int getCost(vector<int> &a, vector<int> &b) {
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>> &points) {
  int size = points.size();

  int answer = 0;
  priority_queue<Edge> pq;
  int start = 0;
  vector<bool> visited(size, false);
  visited[start] = true;

  for (int next = 0; next < size; next++) {
    if (visited[next]) continue;
    int cost = getCost(points[start], points[next]);
    pq.push({next, cost});
  }

  while (!pq.empty()) {
    Edge edge = pq.top();
    pq.pop();

    int cur = edge.to, cost = edge.cost;
    if (visited[cur]) continue;
    visited[cur] = true;
    answer += cost;

    for (int next = 0; next < size; next++) {
      if (visited[next]) continue;
      int cost = getCost(points[cur], points[next]);
      pq.push({next, cost});
    }
  }

  return answer;
}
```

### 프림의 알고리즘 - faster

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     113      |   O(N^2)    |    O(N)     |

한 노드에서 다른 노드로 갈 때 가장 cost가 낮은 간선만 잇고, 이후에 해당 간선의 목적지 노드에서 간선을 또 잇는다.

```cpp
int getCost(vector<int> &a, vector<int> &b) {
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>> &points) {
  int size = points.size();
  int answer = 0, node = 0;
  vector<int> distances(size, 10000000);

  int remain = size;
  while (--remain) {
    distances[node] = INT_MAX;
    int minIdx = node;

    for (int next = 0; next < size; ++next) {
      if (distances[next] == INT_MAX) continue;
      distances[next] =
          min(distances[next], getCost(points[node], points[next]));

      if (distances[next] < distances[minIdx]) minIdx = next;
    }
    answer += distances[minIdx];
    node = minIdx;
  }

  return answer;
}
```

### 크루스칼 알고리즘

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     1832     | O(N^2 \* log_2(N^2)) |   O(N^2)    |

모든 노드에 대한 간선정보를 생성한 뒤 비용이 낮은 간선부터 차례로 MST에 삽입한다.

이 때 한 노드에서 다른 노드로 향하는 경로는 하나만이 존재해야 한다.

```cpp
struct Edge {
  int from, to, cost;

  bool operator<(const Edge &b) const { return cost < b.cost; };
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

int getCost(vector<int> &a, vector<int> &b) {
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>> &points) {
  int size = points.size();
  vector<Edge> edges;

  parents.resize(size);
  for (int i = 0; i < size; i++) {
    parents[i] = i;
  }

  for (int from = 0; from < size; from++) {
    for (int to = 0; to < size; to++) {
      if (from == to) continue;

      int cost = getCost(points[from], points[to]);
      edges.push_back({from, to, cost});
    }
  }

  sort(edges.begin(), edges.end());

  int answer = 0;
  for (Edge &edge : edges) {
    if (find(edge.from) == find(edge.to)) continue;

    answer += edge.cost;
    merge(edge.from, edge.to);
  }

  return answer;
}
```

## 고생한 점
