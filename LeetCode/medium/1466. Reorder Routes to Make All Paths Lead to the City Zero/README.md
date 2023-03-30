# 1466. Reorder Routes to Make All Paths Lead to the City Zero

[링크](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E라 하자. (N <= 5 \* 10^4, E == N-1)

모든 도시에서 0번 도시로 가는 경로를 만들어야 하며, 이 과정중에서 간선을 뒤집는 갯수를 구해야 한다.

간선을 뒤집는 모든 경우를 탐색할 경우 시간 복잡도는 O(2^E) 이므로 제한시간 내에 불가능하다.

각 간선을 그래프에 설정할 때, 반대 방향의 간선 또한 설정해둔다.

0번 도시에서부터 다른 도시들까지 BFS로 역방향 간선으로 방문하며, 방문한 뒤집혀진 간선의 갯수를 센다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 노드의 방문 여부를 저장하는데 O(N), 각 노드의 간선을 저장하는데 O(E)의 공간 복잡도가 필요하다.

BFS를 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 역방향 BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     356      |    O(N)     |    O(N)     |

모든 도시에서 0번 도시로 방문하기 위해 간선을 뒤집어야 한다.

이를 반대로 0번 도시에서 다른 모든 도시까지 방문할 때 뒤집어야 하는 간선의 갯수를 구한다.

그래프에 간선을 삽입할 때 역방향 간선도 삽입하며, 정방향일 때의 cost는 1, 역방향일때의 cost를 0로 설정한다.

이는 0번 도시에서 다른 도시들을 방문하므로 방향이 반대이기 때문이다.

이후 BFS를 수행하며, 방문한 간선의 cost를 더해가며 답을 구한다.

```cpp
struct Edge {
  int from, to, cost;
};

int minReorder(int n, vector<vector<int>>& connections) {
  vector<vector<Edge>> graph(n);
  for (vector<int>& c : connections) {
    int from = c[0], to = c[1];

    graph[from].push_back({from, to, 1});
    graph[to].push_back({to, from, 0});
  }

  queue<Edge> q;
  vector<bool> visited(n, false);
  q.push({0, 0, 0});
  int answer = 0;
  while (!q.empty()) {
    Edge cur = q.front();
    q.pop();

    if (visited[cur.to]) continue;
    visited[cur.to] = true;
    answer += cur.cost;

    for (Edge next : graph[cur.to]) {
      q.push(next);
    }
  }
  return answer;
}
```

## 고생한 점
