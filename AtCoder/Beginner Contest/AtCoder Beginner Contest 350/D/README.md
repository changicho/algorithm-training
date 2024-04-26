# D - New Friends

[링크](https://atcoder.jp/contests/abc350/tasks/abc350_d)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

입력받은 노드의 수를 V, 간선의 수를 E라 하자.

결과적으로 각 연결된 노드에 해당하는 그래프를 complete graph로 만들어야 한다.

이를 위해 DFS를 이용할 경우 O(V + E)의 시간 복잡도가 소요된다.

### 공간 복잡도

그래프에 O(V + E)의 공간 복잡도가 필요하다.

DFS에 O(V)의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) |        시간 복잡도        | 공간 복잡도 |
| :----------: | :-----------------------: | :---------: |
|     174      | O(V \* E \* log_2(E) + E) |  O(V + E)   |

현재 그래프에서 연결된 노드들의 그룹을 찾는다. 해당 노드들의 집합들을 서브 그래프 들이라 하자.

각 서브 그래프들을 complete graph로 만들기 위해 필요한 간선의 수를 구한다.

따라서 각 서브 그래프들을 구성하는 간선과 노드의 갯수를 찾는다.

complete graph의 간선의 수는 (n \* (n-1)) / 2 이다.

```cpp
long long answer = 0;
vector<vector<int>> graph;
vector<bool> visited;

long long nodeCount = 0;

void recursive(int node, int parent, set<pair<int, int>>& visitedEdges) {
  visited[node] = true;
  nodeCount++;

  for (int& next : graph[node]) {
    if (next == parent) continue;

    visitedEdges.insert({min(node, next), max(node, next)});

    if (visited[next]) continue;

    recursive(next, node, visitedEdges);
  }
}

long long solution(int n, vector<pair<int, int>> edges) {
  graph.resize(n + 1);
  visited.resize(n + 1, false);

  for (auto& edge : edges) {
    graph[edge.first].push_back(edge.second);
    graph[edge.second].push_back(edge.first);
  }

  for (int node = 1; node <= n; node++) {
    if (visited[node]) continue;

    set<pair<int, int>> visitedEdges;

    nodeCount = 0;

    recursive(node, -1, visitedEdges);

    long long fullCount = (long long)nodeCount * (nodeCount - 1) / 2;
    long long alreadyCount = (long long)visitedEdges.size();

    answer += fullCount - alreadyCount;
  }

  return answer;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      79      |  O(V \* E)  |  O(V + E)   |

위 방법에서 결과적으로 각 서브 그래프들에 추가해야하는 간선의 갯수는 다음과 같이 구할 수 있다.

- complete graph들을 만들 기 위한 간선의 갯수 : X
- 이미 존재하는 간선의 갯수 : Y
- X - Y

여기서 Y는 주어진 간선의 갯수 E이므로 바로 정답을 구할 수 있다.

```cpp
void recursive(int node, int parent, vector<vector<int>>& graph,
               vector<bool>& visited, int& nodeCount) {
  visited[node] = true;
  nodeCount++;

  for (int& next : graph[node]) {
    if (next == parent) continue;

    if (visited[next]) continue;

    recursive(next, node, graph, visited, nodeCount);
  }
}

long long solution(int n, vector<pair<int, int>> edges) {
  vector<vector<int>> graph(n + 1);
  vector<bool> visited(n + 1, false);

  for (auto& edge : edges) {
    graph[edge.first].push_back(edge.second);
    graph[edge.second].push_back(edge.first);
  }

  long long answer = 0;
  for (int node = 1; node <= n; node++) {
    if (visited[node]) continue;

    int nodeCount = 0;
    recursive(node, -1, graph, visited, nodeCount);

    answer += (long long)nodeCount * (nodeCount - 1) / 2;
  }

  answer -= edges.size();

  return answer;
}
```

## 고생한 점
