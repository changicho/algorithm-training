# 2192. All Ancestors of a Node in a Directed Acyclic Graph

[링크](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

Directed Acyclic Graph(DAG)의 노드의 갯수를 V, 간선의 갯수를 E라고 하자.

위상 정렬을 사용할 경우 위상정렬 자체에 O(V + E)의 시간 복잡도를 사용한다.

이 때 각 과정에서 ancestor들을 각 노드에 삽입해줘야하며 중복을 제거해야 한다. 이 과정에서 BST기반의 set을 사용할 경우 O(V \* log_2(V))의 시간 복잡도를 사용한다.

따라서 위상 정렬을 사용할 경우 시간 복잡도는 O(V^2 \* log_2(V) + E)이다.

DFS를 이용해 각 노드와 연결된 모든 노드에 자신을 ancestor로 추가하는 방법을 사용할 수 있다.

이 경우 시간 복잡도는 O(V^2 + E)가 된다.

### 공간 복잡도

위상 정렬을 사용할 경우 O(V + E)의 공간 복잡도를 사용한다.

DFS를 사용할 경우 O(V + E)의 공간 복잡도를 사용한다.

### 위상 정렬

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     794      | O(V^2 \* log_2(V) + E) |  O(V + E)   |

입력받은 edges 정보를 그래프로 변환한다.

이후 위상 정렬을 수행한다.

이 과정에서 현재 노드에서 다음 노드로 이동할 때, 방문 정점들을 함께 넘겨준다.

이 기록들을 모두 넘겨줘야 하므로 최대 O(V)번 넘겨주게 된다. 이후 정답에서 이를 정렬된 순서로 반환해야 하므로 BST기반의 set을 이용할 경우 O(V \* log_2(V))의 시간 복잡도를 사용한다.

이후 정답 배열을 생성하고 반환한다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
  vector<vector<int>> graph(n);
  vector<int> inDegrees(n, 0);
  // O(E)
  for (vector<int> &e : edges) {
    graph[e[0]].push_back(e[1]);
    inDegrees[e[1]]++;
  }

  queue<int> q;
  // O(V)
  for (int node = 0; node < n; node++) {
    if (inDegrees[node] == 0) q.push(node);
  }

  vector<set<int>> ancestorSets(n);
  // O(V)
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    // total O(E)
    for (int &next : graph[cur]) {
      // add cur and visited node of cur
      ancestorSets[next].insert(cur);
      // O(V)
      for (int node : ancestorSets[cur]) {
        ancestorSets[next].insert(node);
      }

      inDegrees[next]--;
      if (inDegrees[next] == 0) {
        q.push(next);
      }
    }
  }

  vector<vector<int>> ancestors(n);
  // O(V)
  for (int node = 0; node < n; node++) {
    // O(V)
    for (int a : ancestorSets[node]) {
      ancestors[node].push_back(a);
    }
  }
  return ancestors;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     171      | O(V^2 + E)  |  O(V + E)   |

각 노드에서 연결된 모든 노드에 대해 자기 자신을 방문한 노드로 추가해준다.

이를 0번 노드부터 n-1번 노드까지 순서대로 진행한다. 이 경우 작은 숫자부터 추가되므로 자동으로 정렬된 순서를 갖게 된다.

한 노드에서 출발할 때 각 과정에서 이미 방문한 노드는 방문하지 말아야 하므로 visited 배열을 사용한다.

이는 새로운 노드에서 출발할 때마다 초기화된다.

이를 구현하면 다음과 같다.

```cpp
void dfs(vector<vector<int>> &graph, int start, int cur, vector<vector<int>> &ancestors, vector<bool> &visited) {
  visited[cur] = true;

  // total O(E)
  for (int &next : graph[cur]) {
    if (visited[next]) continue;

    ancestors[next].push_back(start);
    dfs(graph, start, next, ancestors, visited);
  }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
  vector<vector<int>> ancestors(n), graph(n);

  // O(E)
  for (vector<int> &e : edges) {
    graph[e[0]].push_back(e[1]);
  }

  // O(V)
  for (int node = 0; node < n; node++) {
    vector<bool> visited(n);

    dfs(graph, node, node, ancestors, visited);
  }
  return ancestors;
}
```

## 고생한 점
