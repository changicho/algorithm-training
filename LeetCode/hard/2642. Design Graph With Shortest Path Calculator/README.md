# 2642. Design Graph With Shortest Path Calculator

[링크](https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 그래프의 정점의 갯수를 V, 간선의 갯수를 E라 하자.

간선을 추가하는 횟수를 N, 두 점 사이의 거리를 구하는 횟수를 M이라 하자.

간선정보로 그래프를 생성하는 데 O(E)의 시간 복잡도를 사용하며, 이후 간선을 추가하는데 O(N)의 시간 복잡도가 소요된다.

다이크스트라 알고리즘을 사용할 경우 O(E \* log_2(V))의 시간 복잡도로 두 점 사이의 거리를 구할 수 있다. 이 때 방문 비용 배열등의 초기화에 O(V)의 시간 복잡도를 추가로 사용한다.

따라서 모든 연산을 수행할 때의 총 시간 복잡도는 O(N + M \* (V + E \* log_2(V))) 이다.

### 공간 복잡도

그래프를 생성하는데 O(V + E)의 공간 복잡도를 사용한다. 이후 N개의 간선이 추가되므로 총 O(V + E + N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) |           시간 복잡도           | 공간 복잡도  |
| :----------: | :-----------------------------: | :----------: |
|     302      | O(N + M \* (V + E \* log_2(V))) | O(V + E + N) |

두개의 노드 사이의 최소거리를 구할 때 다이크스트라 알고리즘을 사용해 구한다.

미리 그래프를 생성해놓고 간선이 추가될 때마다 그래프에 간선을 추가한다.

```cpp
class Graph {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

  vector<vector<Edge>> graph;

 public:
  Graph(int n, vector<vector<int>> &edges) {
    graph.resize(n);
    for (vector<int> &e : edges) {
      int from = e[0], to = e[1], cost = e[2];

      graph[from].push_back({from, to, cost});
      // graph[to].push_back({to, from, cost});
    }
  }

  void addEdge(vector<int> edge) {
    int from = edge[0], to = edge[1], cost = edge[2];

    graph[from].push_back({from, to, cost});
  }

  int shortestPath(int node1, int node2) {
    int size = graph.size();
    priority_queue<Edge> pq;
    vector<int> costs(size, INT_MAX);

    costs[node1] = 0;
    pq.push({-1, node1, 0});

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      for (Edge &next : graph[cur.to]) {
        if (costs[next.to] <= next.cost + cur.cost) continue;
        costs[next.to] = next.cost + cur.cost;
        pq.push({next.from, next.to, next.cost + cur.cost});
      }
    }

    if (costs[node2] == INT_MAX) return -1;
    return costs[node2];
  }
};
```

## 고생한 점
