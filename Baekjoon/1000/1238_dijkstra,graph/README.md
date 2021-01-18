# 1238. 파티

[링크](https://www.acmicpc.net/problem/1238)

|  난이도  | 정답률(\_%) | 제한 시간 |
| :------: | :---------: | :-------: |
| Gold III |   44.756    |    1초    |

## 설계

### 시간 복잡도

노드의 수 N은 최대 1,000이다. 간선의 수 M은 최대 10,000이다.

모든 노드에서 X로 오는 경우와, X에서 모든 경우로 탐색하는 경우 두 가지를 조사해야한다.

따라서 다익스트라와 플로이드 와샬 알고리즘을 이용해 풀이할 수 있다.

플로이드 와샬 알고리즘의 경우 O(N^3) 이므로 O(1,000,000,000) 제한시간 내에 아슬아슬하다.

다익스트라의 경우 시간복잡도는 O(E\*log_2(V)) 이다.

### 공간 복잡도

최악의 경우 정답은 1,000\*100 이므로 이는 int형으로 충분하다.

### 다익스트라

X에서 모든 노드로 가는 costs 배열을 갱신하면 X에서 돌아갈 때의 거리들을 계산할 수 있다.

모든 노드에서 X로 오는 경우는, 반대로 생각할 수 있다.

기존에 입력받은 edge의 역방향으로 X에서 탐색하는 경우 모든 노드에서 X로 올 때의 거리들을 구할 수 있다.

따라서 다익스트라를 2번 수행해 문제에서 요구하는 정답을 구할 수 있다.

```cpp
void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &costs) {
  priority_queue<Status> pq;

  fill(costs.begin(), costs.end(), MAX);
  costs[start] = 0;

  pq.push({start, 0});
  while (!pq.empty()) {
    Status cur = pq.top();
    Edge edge = cur.edge;
    pq.pop();

    for (Edge next : graph[edge.to]) {
      int new_val = costs[edge.to] + next.cost;
      int before_val = costs[next.to];

      if (new_val < before_val) {
        costs[next.to] = new_val;
        pq.push({next.to, new_val});
      }
    }
  }
}

dijkstra(X, toGraph, costToTarget);
dijkstra(X, fromGraph, costFromTarget);

int answer = 0;
for (int node = 1; node <= N; node++) {
  answer = max(answer, costFromTarget[node] + costToTarget[node]);
}
```

### 함수의 인자로 배열

### 플로이드 와샬을 이용한 방법

시간 : 948ms

N^3 이므로 1초 내에 아슬아슬하다.

```cpp
for (int through = 1; through <= N; through++) {
  for (int from = 1; from <= N; from++) {
    for (int to = 1; to <= N; to++) {
      costs[from][to] = min(costs[from][to], costs[from][through] + costs[through][to]);
    }
  }
}

int answer = 0;
for (int node = 1; node <= N; node++) {
  int cur_cost = costs[node][target] + costs[target][node];
  if (cur_cost >= MAX) continue;

  answer = max(answer, cur_cost);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

fill 함수의 이용

```cpp
int arr[1001];

// 모두 초기화 하기 위해선 다음과 같이 초기화해야함
fill(&arr[0], &arr[1001], value);
```

맨 끝 pointer를 arr[1000]으로 설정해 문제가 발생했었다.

사용할 때 다음과 같이 사용하는 것이 좋다.

```cpp
int arr[1001];

fill(arr, arr + SIZE + 1, value);
```
