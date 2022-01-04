# 2065. Maximum Path Quality of a Graph

[링크](https://leetcode.com/problems/maximum-path-quality-of-a-graph/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 갯수를 V, 엣지의 갯수를 E라고 하자.

각 노드마다 최대 4개의 연결된 다른 노드가 존재한다.

각 엣지의 cost는 최소값이 10이다.

DFS를 수행하며 maxTime이내에 방문하고 원점으로 돌아왔을 때의 최대값을 찾아야한다.

이를 위해 DFS를 이용할 수 있다.

주어진 maxTime의 최대값은 100이며, 각 엣지의 cost가 최소 10이므로 최대 10번 이동할 수 있다.

이를 각 엣지마다 수행한다고 할 경우 시간 복잡도는 O(4^10)이다.

여기서 다익스트라를 이용해 백트래킹을 추가할 수 있다.

### 공간 복잡도

그래프 연결관계를 표현하는 데 O(V + E)의 공간 복잡도를 사용한다.

그 외에 visited를 관리할 배열에 O(V)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     156      |   O(4^10)   |  O(V + E)   |

현재 노드에서 다음 노드까지 연결된 모든 엣지에 대해서 탐색한다.

이 때 현재까지의 cost에 다음 엣지의 cost를 더한 값이 maxTime을 초과하지 않는 경우만 탐색을 진행한다.

이를 진행하며 시작점에 도착할 때마다 정답을 갱신한다.

여기서 처음 방문한 노드에 대해서만 답을 구해야 한다.

이는 visited를 단순 boolean형으로 사용하지 않고 방문할 때마다 증가하고, 되돌아갈 때마다 감소시키는 int배열로 선언해 현재 방문한 노드가 visited = 0일 때만 추가해 풀이할 수 있다.

```cpp
struct Edge {
  int from, to, cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

vector<vector<Edge>> graph;
vector<int> visited;
int answer;

void dfs(int node, int sum, int cost, int maxTime, vector<int> &values) {
  if (cost > maxTime) return;

  if (visited[node] == 0) sum += values[node];
  visited[node]++;

  if (node == 0) {
    answer = max(answer, sum);
  }

  for (Edge &next : graph[node]) {
    dfs(next.to, sum, cost + next.cost, maxTime, values);
  }

  visited[node]--;
}

int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime) {
  int size = values.size();
  visited.resize(size, 0);
  graph.resize(size);
  for (vector<int> &edge : edges) {
    int from = edge[0], to = edge[1], cost = edge[2];

    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost});
  }

  answer = values[0];

  dfs(0, 0, 0, maxTime, values);

  return answer;
}
```

### DFS + dijkstra

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|     156      | O(4^10 + O(E \* log_2(V))) |  O(V + E)   |

다이크스트라로 시작점에서 다른 모든 노드까지의 cost를 구한다.

이를 이용해 탐색을 진행하며 다음 노드를 방문할 때 원점으로 되돌아오지 못하는 경우에 대해서 더이상 탐색을 진행하지 않을 수 있다.

```cpp
vector<vector<Edge>> graph;
vector<int> visited;
vector<int> costs;
int answer;

void dfs(int node, int sum, int cost, int maxTime, vector<int> &values) {
  if (cost > maxTime) return;

  if (visited[node] == 0) sum += values[node];
  visited[node]++;

  if (node == 0) {
    answer = max(answer, sum);
  }

  for (Edge &next : graph[node]) {
    if (cost + next.cost + costs[next.to] > maxTime) continue;

    dfs(next.to, sum, cost + next.cost, maxTime, values);
  }

  visited[node]--;
}

int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                        int maxTime) {
  int size = values.size();

  visited.resize(size, 0);
  graph.resize(size);
  for (vector<int> &edge : edges) {
    int from = edge[0], to = edge[1], cost = edge[2];

    graph[from].push_back({from, to, cost});
    graph[to].push_back({to, from, cost});
  }

  costs.resize(size, INT_MAX);  // all cost from 0;
  priority_queue<Edge> pq;
  for (Edge &next : graph[0]) {
    pq.push(next);
  }
  costs[0] = 0;

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    if (cur.cost >= costs[cur.to]) continue;
    costs[cur.to] = cur.cost;

    for (Edge &next : graph[cur.to]) {
      pq.push({next.from, next.to, next.cost + cur.cost});
    }
  }

  answer = values[0];

  dfs(0, 0, 0, maxTime, values);

  return answer;
}
```

## 고생한 점
