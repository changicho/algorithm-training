# 1514. Path with Maximum Probability

[링크](https://leetcode.com/problems/path-with-maximum-probability/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 정점의 수를 V, 간선의 수를 E라 하자.

시작점에서 끝점까지 경로 중 가장 cost가 높은 경로를 찾아야 한다. 이에 다이크스트라 알고리즘을 사용할 수 있다.

그래프를 생성하는데 O(E)의 시간 복잡도를 사용한다.

이후 다이크스트라 알고리즘을 이용해 간선들을 탐색하며 최단 거리를 갱신한다.

이에 O(E \* log_2(V))의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(V + E)의 공간 복잡도를 사용한다.

각 정점에 대한 최대값을 저장하는 데 O(V)의 공간 복잡도를 사용한다.

### 다이크스트라 알고리즘

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     271      | O(E \* log_2(V)) |  O(V + E)   |

입력받은 간선정보를 이용해 그래프를 생성한다.

이 때 각 간선마다 확률이 존재한다.

현재 정점에서 다음 정점으로 갈 때, 다음 정점까지 도달할 확률은 다음과 같다.

- 현재 정점까지 확률 \* 간선의 확률

이를 이용해 그래프 탐색마다 각 정점까지 도달하는 확률을 구할 수 있다.

다이크스트라 알고리즘을 사용해 시작 정점에서 끝 정점까지의 최대 확률을 구할 수 있다.

이를 구현하면 다음과 같다.

```cpp
struct Edge {
  int from, to;
  double cost;

  bool operator<(const Edge& b) const { return cost < b.cost; }
};

double maxProbability(int n, vector<vector<int>>& edges,
                      vector<double>& succProb, int start, int end) {
  vector<vector<Edge>> graph(n);

  for (int i = 0; i < edges.size(); i++) {
    int from = edges[i][0], to = edges[i][1];
    double cost = succProb[i];

    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost});
  }

  priority_queue<Edge> pq;
  pq.push({-1, start, 1.0});

  vector<double> visited(n, 0);

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    if (visited[cur.to] >= cur.cost) continue;
    visited[cur.to] = cur.cost;

    if (cur.to == end) continue;

    for (Edge& next : graph[cur.to]) {
      pq.push({next.from, next.to, next.cost * cur.cost});
    }
  }

  return visited[end];
}
```

## 고생한 점

힙 내부에서 비교 연산을 주의하자.
