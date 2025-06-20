# D - XOR Shortest Walk

[링크](https://atcoder.jp/contests/abc410/tasks/abc410_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

그래프를 생성하는 데 O(V + E)의 시간 복잡도를 사용한다.

각 노드를 방문할 때 2^10가지 경우가 존재할 수 있다. 이를 저장해 필요한 경우만 방문할 수 있다.

이를 이용해 유효한 모든 경우를 탐색할 경우 O((V + E) \* 2^10)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프를 저장하는 데 O(V + E)의 공간 복잡도를 사용한다.

각 노드마다 방문 여부를 저장하는데 O(V \* 2^10)의 공간 복잡도를 사용한다.

### BFS & 방문처리

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도  |
| :----------: | :----------------: | :----------: |
|      8       | O((V + E) \* 2^10) | O(V \* 2^10) |

그래프에 주어지는 간선은 단방향이다.

각 노드를 방문할 때, 방문하는 path의 XOR값의 경우의 수가 2^10가지가 존재한다.

따라서 해당 노드를 방문할 때 XOR값에 대해 방문 여부를 저장한다.

이를 이용해 모든 경우를 탐색하며 중복을 제거한다.

이후 목적지 노드에 도달했는 지 판단한다.

```cpp
struct Edge {
  int from, to, cost;
};

int solution(int n, int size, vector<Edge> &edges) {
  vector<int> costs(n, INT_MAX);

  vector<vector<Edge>> graph(n);
  for (int i = 0; i < size; i++) {
    graph[edges[i].from].push_back(edges[i]);
  }

  queue<Edge> q;
  vector<vector<bool>> visited(n, vector<bool>(1024, false));
  q.push({0, 0, 0});
  costs[0] = 0;

  while (!q.empty()) {
    Edge cur = q.front();
    q.pop();

    if (visited[cur.to][cur.cost]) continue;
    visited[cur.to][cur.cost] = true;

    for (Edge &next : graph[cur.to]) {
      int newCost = cur.cost ^ next.cost;

      if (visited[next.to][newCost]) continue;

      costs[next.to] = min(costs[next.to], newCost);
      q.push({next.from, next.to, newCost});
    }
  }

  return costs[n - 1] == INT_MAX ? -1 : costs[n - 1];
}
```

## 고생한 점
