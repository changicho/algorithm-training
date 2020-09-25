# 49189. 가장 먼 노드

[링크](https://programmers.co.kr/learn/courses/30/lessons/49189)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv3   |   2903    |

## 설계

### 시간 복잡도

노드의 개수는 20,000개 이하이다.

간선의 개수는 50,000개 이하이다.

다익스트라 알고리즘을 사용해서 한 노드에서 다른 노드들 까지의 거리를 구하는 데 시간 복잡도는

O((V+E)logV) 이므로 제한시간 1초 내에 충분하다. (V는 정점의 개수, E는 한 정점의 주변 노드)

### 공간 복잡도

각 노드마다 연결되어있는 가중치를 1이라고 했을 때, 가장 먼 노드의 가중치 합은 20,000 이하이다.

따라서 int형으로 충분하다.

## 다익스트라

다익스트라에서 사용해야 하는 우선순위 큐는 최소 우선순위 큐 이다.

초기화

1. 거리배열 costs를 전부 INF로 초기화한다.
2. 시작점의 거리를 0으로 지정한다 (A -> A 의 거리는 0이다)
3. 우선순위 큐 pq를 선언한다. (cost에 최소값이 제일 위에 올라와야함)
4. pq에 시작 점을 저장한다.

while문 (pq가 빌 때까지)

1. 현재 노드에 pq의 top값을 할당하고 pop
2. 현재 노드에 연결된 간선을 탐색한다.
3. 간선의 도착점까지 cost를 비교한다 (현재 노드를 지나서 가는 경우 cost vs 원래 간선까지의 cost)
4. 현재 노드를 지나가는 경우의 가중치 합계가 더 작으면
   1. cost를 갱신한다 (costs 배열의 그것을 갱신한다)
   2. pq에 {cost, 도착점}을 push한다.

pq는 최소 힙이므로 cost 가 가장 작을수록 우선순위가 더 높다.

```cpp
struct Edge {
  int to;
  int cost;
};

struct compare {
  bool operator()(Edge a, Edge b) { return a.cost > b.cost; } // 우선순위 큐 최상단이 최소값이 되도록
};

vector<vector<Edge>> lines;
vector<int> costs;

void dijkstra(int start){
  costs.resize(n + 1, INF);
  priority_queue<Edge, vector<Edge>, compare> pq;

  costs[start] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Edge current : lines[cur.to]) {
      int new_val = costs[cur.to] + current.cost;
      int before_val = costs[current.to];

      if (new_val < before_val) {
        int destination = current.to;

        costs[destination] = new_val;
        pq.push({destination, new_val});
      }
    }
  }
}
```

## 고생한 점
