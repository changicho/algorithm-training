# 1916. 최소비용 구하기

[링크](https://www.acmicpc.net/problem/1916)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   33.133    |

## 설계

### 시간 복잡도

도시의 개수 N은 최대 1,000개 버스의 개수 M은 최대 100,000개가 존재한다.

두 개의 정점의 최단거리를 구하면 되므로 하나의 정점에서 다이크스트라 알고리즘을 이용해 최단경로를 구한다.

이 떄의 시간 복잡도는 O(E log_2(V)) 이다. 이는 제한시간 0.5초 내에 충분하다.

### 공간 복잡도

최악의 경우 정답은 도시의 개수만큼 비용의 최대치를 곱한 값이다.

이는 100,000,000 이므로 int형으로 충분하다.

### 다이크스트라

문제에서 주어지는 그래프는 양방향 그래프가 아님에 유의한다.

또한 꼭 정답이 존재하는 경우만 주어지므로 연결되지 않은 경우는 고려하지 않아도 된다.

```cpp
struct Edge {
  int to, cost;

  bool operator<(const Edge &b) const {
    return cost > b.cost; // 우선순위 큐의 top이 최소값이 되도록
  }
};

vector<vector<Edge>> graph;
vector<int> costs; // 처음에 INFINITY로 초기화해야함

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

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      24      |       0        |

## 고생한 점
