# 261. Graph Valid Tree

[링크](https://leetcode.com/problems/graph-valid-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N, 간선의 개수를 E라 하자.

DFS를 이용해 사이클이 존재하는지 판별할 수 있으며 이 때의 시간 복잡도는 O(N + E)이다.

이후 2개 이상의 트리로 구성되어있는지 확인하는데 O(N)의 시간 복잡도가 필요하므로 최종 시간 복잡도는 O(N + E)이다.

유니온 파인드를 이용할 경우 merge 중에 사이클이 존재하는지 판별할 수 있다.

이 경우 시간 복잡도는 O(N \* a(N))이며 이후 2개 이상의 그룹이 존재하는지 확인하는데 O(N)의 시간 복잡도가 소요된다. (a는 애커만 상수)

따라서 유니온 파인드의 경우 시간 복잡도는 O(N \* a(N)) 이다.

### 공간 복잡도

유니온 파인드의 경우 부모의 주소를 저장할 공간이 필요하며 O(N)의 공간 복잡도를 사용한다.

DFS를 이용할 경우 그래프를 생성하는데 O(N + E)의 공간 복잡도가 필요하며 방문 여부를 판별하는데 O(N)의 공간 복잡도가 필요하다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      11      | O(N \* a(N)) |    O(N)     |

입력받은 간선들로 연결관계를 구성할 때, 두 노드가 이미 같은 그룹에 속해 있고 이 두 노드를 합치려 하는 경우에 사이클이 발생한다.

사이클을 판별한 이후 2개 이상의 그룹이 나오는지 판별한다.

```cpp
vector<int> parents;

int find(int a) {
  if (parents[a] == a) return a;

  return parents[a] = find(parents[a]);
}

void merge(int a, int b) {
  int parentA = find(a);
  int parentB = find(b);

  if (parentA > parentB) swap(parentA, parentB);

  parents[parentB] = parentA;
}

bool validTree(int n, vector<vector<int>>& edges) {
  parents.resize(n);
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  for (vector<int>& edge : edges) {
    int a = edge[0];
    int b = edge[1];

    if (find(a) == find(b)) return false;

    merge(a, b);
  }

  unordered_set<int> groups;
  for (int i = 0; i < n; i++) {
    groups.insert(find(i));
  }

  return groups.size() == 1;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |  O(N + E)   |  O(N + E)   |

DFS를 수행할 때 직전 부모의 index를 같이 넘긴다.

이는 현재 노드에서 다음 노드를 탐색할 때 부모 노드를 탐색하지 않기 위함이다.

만약 탐색을 계속하며 부모가 아닌 이전에 방문한 노드를 발견한 경우는 사이클이 존재하는것을 알 수 있다.

```cpp
vector<bool> visited;
vector<vector<int>> graph;

bool hasCycle(int node, int parent) {
  if (visited[node]) return true;
  visited[node] = true;

  for (int next : graph[node]) {
    if (next != parent && hasCycle(next, node)) {
      return true;
    }
  }
  return false;
}

bool validTree(int n, vector<vector<int>>& edges) {
  graph.resize(n);

  for (vector<int>& edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }

  visited.resize(n, false);

  if (hasCycle(0, -1)) {
    return false;
  }
  for (bool cur : visited) {
    if (!cur) return false;
  }
  return true;
}
```

## 고생한 점
