# 3419. Minimize the Maximum Edge Weight of Graph

[링크](https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

다이크스트라 알고리즘을 응용해 간선의 최대값이 작도록 순회할 수 있다.

이 때 시간 복잡도는 O(V \* log_2(E)) 이다.

데이터 전처리와 간선을 삭제할 수 있는지 판단하는데 O(V + E)의 시간 복잡도가 필요하다.

### 공간 복잡도

다이크스트라 알고리즘에 O(V + E)의 공간 복잡도가 필요하다.

### 다이크스트라

| 내 코드 (ms) |       시간 복잡도        | 공간 복잡도 |
| :----------: | :----------------------: | :---------: |
|     242      | O(V + E + V \* log_2(E)) |  O(V + E)   |

모든 간선은 방향이 있으며, 최종적으로 각 노드에서 모두 0번 노드로 갈 수 있어야 한다.

이는 반대로 간선의 방향을 모두 뒤집으면 0번 노드에서 다른 모든 노드로 방문이 가능해야 함을 의미한다.

그래프를 반대방향으로 생성한 뒤 각 노드별로 outDegree를 계산한다.

이후 다이크스트라 알고리즘을 사용해 각 노드를 방문할 때 지나온 간선의 최대값을 기준으로 방문한다.

이 때 최대값이 최소가 되는 순으로 방문한다. (해당 노드까지 도달하는 cost는 상관없음)

만약 현재 간선이 불필요한 경우 해당 간선을 삭제하고 outDegree를 감소시킨다.

탐색이 끝난 후 방문 불가능한 노드가 존재하는지, threshold를 초과하는 outDegree가 존재하는지 확인한다.

```cpp
struct Edge {
  int a, b, w;

  bool operator<(const Edge &b) const { return w > b.w; }
};

int minMaxWeight(int n, vector<vector<int>> &edges, int threshold) {
  vector<vector<Edge>> graph(n);

  vector<int> outDegrees(n);
  for (vector<int> &e : edges) {
    graph[e[1]].push_back({e[1], e[0], e[2]});
    outDegrees[e[0]]++;
  }

  vector<int> costs(n, INT_MAX);
  priority_queue<Edge> pq;
  pq.push({-1, 0, 0});

  int maxW = 0;
  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    if (cur.w >= costs[cur.b]) {
      outDegrees[cur.b]--;
      continue;
    }

    costs[cur.b] = cur.w;

    maxW = max(maxW, cur.w);

    for (Edge &e : graph[cur.b]) {
      pq.push({e.a, e.b, max(e.w, cur.w)});
    }
  }

  for (int i = 0; i < n; i++) {
    if (outDegrees[i] > threshold) return -1;
  }
  for (int i = 0; i < n; i++) {
    if (costs[i] == INT_MAX) return -1;
  }
  return maxW;
}
```

## 고생한 점
