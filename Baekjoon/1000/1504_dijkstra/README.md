# 1504. 특정한 최단 경로

[링크](https://www.acmicpc.net/problem/1504)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   23.982    |

## 설계

### 시간 복잡도

정점의 개수 N과 간선의 개수 E는 다음과 같다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000)

각 간선의 비용의 범위는 다음과 같다. (1 ≤ C ≤ 1,000)

정답이 될 수 있는 경로는 다음 두가지이다.

- 1 > V1 > V2 > N
- 1 > V2 > V1 > N

따라서 각 구간마다 최소 거리를 갱신해야한다.

미리 모든 경로의 최소 거리를 구해도 사용할 수 없으므로 다이크스트라를 이용해 문제를 풀이한다.

다이크스트라의 시간 복잡도는 O((V + E)log_2(V)) 이다.

문제를 풀이하기 위해 다이크스트라를 세번 반복해야 하므로 이는 계산하면 대략

```cpp
3 * ((800 + 200,000) * 10) = 3 * 2,008,000 = 6,024,000
```

이며 이는 제한시간 1초 내에 충분하다.

### 공간 복잡도

최악의 경우 경로의 최대 값은 800,000 까지이다. 이는 int형으로 충분하다.

### 다이크스트라

```cpp
struct Edge {
  int to, cost;

  bool operator<(const Edge &b) const {
    return cost > b.cost;
  }
};

vector<vector<Edge>> graph;
vector<int> costs;

void dijkstra(int from) {
  priority_queue<Edge> pq;

  costs[from] = 0;
  pq.push({from, 0});

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Edge next : graph[cur.to]) {
      int new_val = costs[cur.to] + next.cost;
      int before_val = costs[next.to];

      if (new_val < before_val) {
        costs[next.to] = new_val;
        pq.push({next.to, new_val});
      }
    }
  }
}
```

위 다이크스크라를 다음 두가지 방법에 대해 반복한다

- 1 > V1 > V2 > N
- 1 > V2 > V1 > N

### cpp vector clear

벡터를 임의의 값으로 초기화 할 때에 다음 순서로 초기화 해야 한다.

1. v.clear();
2. v.resize(size, initValue);

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      44      |       8        |

## 고생한 점
