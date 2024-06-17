# E - Reachability in Functional Graph

[링크](https://atcoder.jp/contests/abc357/tasks/abc357_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

입력받은 노드의 수를 N이라 하자.

각 노드의 연결관계를 이용해 SCC를 생성한 뒤, 위상 정렬을 사용할 수 있다.

이 경우 SCC를 생성하는 데 O(N)의 시간 복잡도가 소요되며, 위상 정렬을 수행하는 데 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

SCC 노드끼리 묶는 데 유니온 파인드를 사용할 경우 O(N)의 공간 복잡도가 필요하다.

위상 정렬에 O(N)의 공간 복잡도가 필요하다.

### SCC & 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      87      |    O(N)     |    O(N)     |

입력받은 그래프 정보에 사이클이 존재할 수 있다.

해당 사이클에 속하는 원소들 끼리는 서로 이동이 모두 가능하다.

따라서 SCC (Strongly Connected Component)를 찾고 해당 사이클의 원소들을 묶어준다.

이 때 SCC에 속하는 노드들 끼리 가능한 경우쌍을 정답에 더한다.

이후 SCC끼리 묶인 새로운 그래프에서 위상 정렬을 수행한다.

현재 노드를 방문했을 때, 현재 노드까지로 이동 가능한 경우의 수는 다음과 같다.

- 현재까지 이동하며 방문한 노드의 수 \* 현재 노드의 사이클 크기

따라서 위상 정렬을 수행하며 이동 가능한 경우의 수를 갱신해준다.

아래 방법은 SCC를 코사라주 알고리즘을 이용해 구하는 방법이다.

```cpp
class UnionFind {
  vector<int> childrens;
  vector<int> parents;
  int count;

 public:
  UnionFind(int n) {
    count = n;
    childrens.resize(n, 1);
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
  }

  int find(int node) {
    if (parents[node] == node) {
      return node;
    }

    return parents[node] = find(parents[node]);
  };

  void merge(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;
    if (parentA > parentB) swap(parentA, parentB);

    parents[parentA] = parentB;
    childrens[parentB] += childrens[parentA];
    count--;
  };

  int getChildren(int node) { return childrens[find(node)]; }
  int getCount() { return count; }
};

vector<vector<int>> findSCC(int n, vector<int> &nexts) {
  vector<vector<int>> graph(n), rGraph(n);

  for (int i = 0; i < n; i++) {
    int next = nexts[i];
    graph[i].push_back(next);
    rGraph[next].push_back(i);
  }

  vector<bool> visited(n, false);
  stack<int> stk;
  vector<vector<int>> scc;

  function<void(int)> dfs = [&](int node) {
    visited[node] = true;
    for (int &next : graph[node]) {
      if (!visited[next]) dfs(next);
    }
    stk.push(node);
  };

  function<void(int, vector<int> &)> dfsR = [&](int node, vector<int> &cycle) {
    visited[node] = true;
    cycle.push_back(node);
    for (int &next : rGraph[node]) {
      if (!visited[next]) dfsR(next, cycle);
    }
  };

  for (int node = 0; node < n; node++) {
    if (!visited[node]) dfs(node);
  }
  visited.assign(n, false);
  while (!stk.empty()) {
    int now = stk.top();
    stk.pop();
    if (visited[now]) continue;

    vector<int> cycle;
    dfsR(now, cycle);
    scc.push_back(cycle);
  }

  return scc;
}

long long solution(int n, vector<int> &nexts) {
  UnionFind uf(n);

  long long answer = 0;

  vector<vector<int>> cycles = findSCC(n, nexts);

  for (vector<int> &cycle : cycles) {
    int base = cycle[0];
    for (int node : cycle) {
      uf.merge(base, node);
    }

    answer += cycle.size() * (cycle.size() - 1);
  }

  vector<int> inDegrees(n, INT_MAX);
  for (int i = 0; i < n; i++) {
    inDegrees[uf.find(i)] = 0;
  }
  for (int node = 0; node < n; node++) {
    if (node != uf.find(node)) continue;

    int next = uf.find(nexts[node]);
    if (next == node) continue;
    inDegrees[uf.find(next)]++;
  }

  // use topological sort
  queue<int> q;

  vector<int> childrens(n, 0);
  for (int i = 0; i < n; i++) {
    if (inDegrees[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    int children = childrens[node];
    answer += children * uf.getChildren(node);

    int next = uf.find(nexts[node]);
    childrens[next] += children + 1;

    inDegrees[next]--;

    if (inDegrees[next] == 0) {
      q.push(next);
    }
  }

  return answer + n;
}
```

## 고생한 점
