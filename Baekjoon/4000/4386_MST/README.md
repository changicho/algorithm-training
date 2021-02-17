# 4386. 별자리 만들기

[링크](https://www.acmicpc.net/problem/4386)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold IV |   53.465    |       1       |

## 설계

### 시간 복잡도

별의 개수(정점) N은 최대 100 까지이다.

각 별(정점) 별로 다른 모든 별에 간선이 존재하므로 간선의 개수는 (101 \* 100) / 2 = 5,050 이다.

문제에서 요구하는 별자리는 간선의 가중치의 합이 최소인 모든 정점이 연결된 트리이므로 최소 스패닝 트리를 구하면 된다.

두 방법이 존재하며 각각 시간 복잡도는 다음과 같다.

- 크루스칼 : O(E \* log_2(E))
- 프림 : O(E \* lob_2(V))

간선의 개수가 매우 많으므로 프림의 알고리즘을 이용한다.

### 공간 복잡도

정답은 소숫점 2자리까지 허용하므로 double로 선언한다.

### 최소 스패닝 트리 - 프림의 알고리즘 (Minimum Spanning Tree, MST)

> 시간 복잡도 O(E\*log_2(V))

각 별들의 좌표만 입력되므로 이를 그래프로 만들어야한다.

```cpp
struct Axis {
  double y, x;
};

for (int from = 0; from < N; from++) {
  for (int to = 0; to < N; to++) {
    if (from == to) continue;

    double cost = getCost(points[from], points[to]);
    graph[from].push_back({to, cost});
  }
}
```

우선 순위 큐를 이용해 간선의 가중치가 낮은 간선부터 순회한다.

이때 해당 간선의 목적지를 이미 방문한 경우 이를 건너 뛴다.

이전에 목적지를 이미 방문했다는 것은 현재 간선보다 가중치가 낮다는 것을 의미하기 때문이다.

즉 가중치가 낮은 간선들부터 순회해 MST를 생성한다.

따라서 처음에는 임의의 점에 속해있는 간선들을 전부 우선순위 큐에 넣고 탐색해야 한다.

```cpp
struct Edge {
  int vertex;
  double cost;
};

struct Status {
  Edge edge;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};
```

```cpp
priority_queue<Status> pq;
vector<bool> visited(V + 1, false);

visited[1] = true;
for (Edge cur : graph[1]) {
  pq.push({cur});
}

double answer = 0;

while (!pq.empty()) {
  Status cur = pq.top();
  pq.pop();
  Edge edge = cur.edge;

  if (visited[edge.vertex]) continue;
  visited[edge.vertex] = true;

  answer += edge.cost;

  for (Edge next : graph[edge.vertex]) {
    pq.push({next});
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

백준 환경에서 cmath 라이브러리를 추가해야함
