# 11779. 최소비용 구하기 2

[링크](https://www.acmicpc.net/problem/11779)

|  난이도  | 정답률(\_%) | 제한 시간 |
| :------: | :---------: | :-------: |
| Gold III |   43.802    |   1 초    |

## 설계

### 시간 복잡도

도시의 개수는 최대 1,000개, 버스의 개수는 최대 100,000개 까지이다.

A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력해야한다.

### 공간 복잡도

최악의 경우 정답은 도시의 개수외 최대값과 버스의 최대 비용이다.

이는 100,000,000 이며 int형으로 충분하다.

단순히 최소 경로의 비용을 출력하는 것이 아니라 경로 또한 출력해야 한다.

따라서 다음과 같은 구조체를 이용한다.

```cpp
struct Edge {
  int to, cost;
};

struct Route {
  int cost;
  vector<int> nodes;
};

struct Status {
  Edge edge;
  vector<int> nodes;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};
```

### 다이크스트라

두 정점 사이의 최소 경로와 비용을 구해야 하므로 다이크스트라를 이용한다.

이 때 방문 경로 또한 저장함에 유의한다.

방문 경로를 갱신할 때는 비용이 갱신되었을 때이다.

```cpp
// initialize
graph.resize(N + 1);
routes.resize(N + 1);
costs.resize(N + 1, MAX);

priority_queue<Status> pq;
costs[from] = 0;
pq.push({{from, 0}, {from}});

// dijkstra
while (!pq.empty()) {
  Status cur = pq.top();
  Edge curEdge = cur.edge;
  pq.pop();

  for (Edge next : graph[curEdge.to]) {
    int new_val = costs[curEdge.to] + next.cost;
    int before_val = costs[next.to];

    if (new_val < before_val) {
      vector<int> nodes = cur.nodes;
      nodes.push_back(next.to);

      costs[next.to] = new_val;
      routes[next.to] = nodes;

      pq.push({{next.to, new_val}, nodes});
    }
  }
}
```

### 최단 경로일 때 방문경로

이 문제는 스페셜 저지이다. 이 의미는 가장 빨리 도착하는 경로가 여러개 일 수 있다는 것을 의미한다.

다음과 같은 예시에서 정답은 2가지 이상 될 수도 있다.

```sh
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

# answer 1
4
3
1 3 5

# answer 2
4
3
1 4 5
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      28      |       4        |

## 고생한 점
