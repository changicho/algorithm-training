# 2093. Minimum Cost to Reach City With Discounts

[링크](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 정점의 수를 V, 간선의 수를 E, discounts의 수를 K라 하자.

각 discount 사용 별로 다이크스트라 알고리즘을 사용해 탐색할 수 있다.

이 경우 각 정점당 discount의 경우의 수는 V \* K이다. 이에 다이크스트라 알고리즘을 사용할 경우 O((K \* V) \* log_2(K \* V))의 시간 복잡도가 소요된다.

각 과정마다 간선을 순회하며 정답을 갱신해야 하므로 총 시간 복잡도는 O((K \* V + E) * log_2(K \* V))이다.

### 공간 복잡도

각 정점까지 최소 거리에 O(K \* V)의 공간 복잡도를 사용한다.

그래프를 나타내는 데 O(E)의 공간 복잡도를 사용한다.

### 다이크스트라 알고리즘

| 내 코드 (ms) |           시간 복잡도           |  공간 복잡도  |
| :----------: | :-----------------------------: | :-----------: |
|     382      | O((K \* V + E) * log_2(K \* V)) | O(K \* V + E) |

각 discount를 사용하는 횟수에 따라 각 정점마다 도달가능한 최소 cost를 갱신해야 한다.

이를 다이크스트라 알고리즘을 이용해 구현한다.

이후 도착 점에서 discount의 가능한 모든 경우에 대해 정답을 구한다.

```cpp
struct Edge {
  int from, to, cost;

  int discount;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

int minimumCost(int n, vector<vector<int>> &highways, int discounts) {
  vector<vector<int>> costs(discounts + 1, vector<int>(n, INT_MAX));
  vector<vector<Edge>> graph(n);

  for (vector<int> &edge : highways) {
    int from = edge[0], to = edge[1], cost = edge[2];

    graph[from].push_back({from, to, cost, 0});
    graph[to].push_back({to, from, cost, 0});
  }

  priority_queue<Edge> pq;
  pq.push({-1, 0, 0, discounts});
  costs[discounts][0] = 0;

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Edge &next : graph[cur.to]) {
      int from = next.from, to = next.to, cost = next.cost;

      if (costs[cur.discount][to] > (cur.cost + cost)) {
        costs[cur.discount][to] = (cur.cost + cost);
        pq.push({from, to, cur.cost + cost, cur.discount});
      }

      if (cur.discount > 0 &&
          costs[cur.discount - 1][to] > (cur.cost + cost / 2)) {
        costs[cur.discount - 1][to] = (cur.cost + cost / 2);
        pq.push({from, to, cur.cost + cost / 2, cur.discount - 1});
      }
    }
  }

  int answer = INT_MAX;
  for (int i = 0; i <= discounts; i++) {
    answer = min(answer, costs[i][n - 1]);
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
