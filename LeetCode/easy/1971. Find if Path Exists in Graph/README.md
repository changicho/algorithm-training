# 1971. Find if Path Exists in Graph

[링크](https://leetcode.com/problems/find-if-path-exists-in-graph/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 개수를 V이라 하자. 간선의 개수를 E라 하자.

DFS, BFS로 시작 노드에서 연결된 모든 노드를 방문하는 데 O(V + E)의 시간 복잡도를 사용한다.

유니온 파인드를 이용할 경우 O(E \* a(V))만큼의 시간 복잡도를 사용하며 이는 실질적으로 O(E)가 된다.

### 공간 복잡도

DFS, BFS를 이용할 경우 방문 배열에 O(V)의 공간 복잡도를, 그래프에 O(V + E)의 공간 복잡도를 사용한다.

유니온 파인드를 이용할 경우 O(V)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     572      |  O(V + E)   |  O(V + E)   |

edge들의 정보를 이용해 그래프를 생성한 후 dfs를 이용해 시작점부터 방문 가능한 모든 노드를 방문한다.

이후 끝점을 방문했는지 여부를 판별한다.

```cpp
void recursive(int node, vector<vector<int>> &graph, vector<bool> &visited) {
  visited[node] = true;
  for (int next : graph[node]) {
    if (visited[next]) continue;

    recursive(next, graph, visited);
  }
}

bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
  vector<bool> visited(n, false);

  vector<vector<int>> graph(n);

  for (vector<int> &edge : edges) {
    int from = edge[0], to = edge[1];

    graph[from].emplace_back(to);
    graph[to].emplace_back(from);
  }

  recursive(start, graph, visited);

  return visited[end];
}
```

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     348      |  O(V + E)   |    O(V)     |

edge 정보를 이용해 유니온 파인드로 노드들을 연결한다.

이후 시작점과 끝점이 연결되어있는지 판별한다.

```cpp
vector<int> parents;
vector<int> counts;

int find(int node) {
  if (parents[node] == node) return node;

  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  int parentA = find(a), parentB = find(b);
  if (parentA == parentB) return;

  if (parentA > parentB) swap(parentA, parentB);
  if (counts[parentA] < parents[parentB]) swap(parentA, parentB);

  parents[parentB] = parentA;
  counts[parentA] += counts[parentB];
  counts[parentB] = 0;
}

bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
  parents.resize(n);
  counts.resize(n, 1);

  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  for (vector<int> &edge : edges) {
    int a = edge[0], b = edge[1];

    merge(a, b);
  }

  return find(start) == find(end);
}
```

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     508      |  O(V + E)   |  O(V + E)   |

시작 노드부터 BFS를 이용해 탐색을 진행한다.

```cpp
bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
  vector<vector<int>> graph(n);
  vector<bool> visited(n, false);

  for (vector<int> &edge : edges) {
    int &from = edge[0], &to = edge[1];

    graph[from].emplace_back(to);
    graph[to].emplace_back(from);
  }

  queue<int> q;
  q.push(start);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    visited[cur] = true;
    if (cur == end) break;

    for (int &next : graph[cur]) {
      if (visited[next]) continue;

      q.push(next);
    }
  }

  return visited[end];
}
```

## 고생한 점
