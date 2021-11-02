# 323. Number of Connected Components in an Undirected Graph

[링크](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N, 간선의 개수를 E라고 하자.

모든 간선을 한번씩 순회하며 연결 관계를 만들어야 하므로 O(E)의 시간 복잡도를 사용한다.

이 때 연결된 노드들을 처리하는 데 유니온 파인드를 이용할 수 있다.

유니온 파인드를 이용할 경우 초기에 설정하는 데 O(N)의 시간 복잡도를, find와 merge 연산에 평균적으로 O(a(N))의 시간 복잡도를 사용하며 이는 거의 O(1) 이다. (에커만 상수)

따라서 시간 복잡도는 O(N + E)이다.

BFS를 이용할 경우 간선을 순회하며 그래프를 만들고, 정점들을 순차적으로 방문하므로 O(N + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드를 이용할 경우 노드마다 부모를 저장할 공간이 필요하므로 O(N)의 공간 복잡도를 사용한다.

BFS를 이용할 경우 간선들의 정보를 노드마다 저장해야 하므로 O(N + E)의 시간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |  O(N + E)   |    O(N)     |

간선을 순회하며 연결관계에 따라서 노드들을 연결한다.

이 때 부모의 index가 작은 쪽이 부모가 되도록 연결한다.

이후 각 노드들의 부모의 종류가 몇가지 인지를 찾는다.

```cpp
vector<int> parents;
int find(int node) {
  if (parents[node] == node) return node;

  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  int parentA = find(a), parentB = find(b);

  if (parentA > parentB) swap(parentA, parentB);
  parents[parentB] = parentA;
}

int countComponents(int n, vector<vector<int>>& edges) {
  parents.resize(n);
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  for (vector<int>& edge : edges) {
    merge(edge[0], edge[1]);
  }

  unordered_set<int> us;
  for (int parent : parents) {
    int target = find(parent);
    us.insert(target);
  }

  return us.size();
}
```

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(N + E)   |  O(N + E)   |

우선 edges들을 사용할 수 있도록 그래프 관계로 표현해야 한다.

이 작업에 O(E)의 시간 복잡도와 O(N + E)의 공간 복잡도를 사용한다.

이후 각 노드들을 순차적으로 순회하며 연결된 이웃 노드들을 모두 방문처리 한다.

BFS를 시작하는 횟수가 노드들의 묶음의 갯수가 되므로 이를 반환한다.

```cpp
int countComponents(int n, vector<vector<int>>& edges) {
  vector<bool> visited(n, false);

  vector<vector<int>> graph(n);
  for (vector<int>& edge : edges) {
    int from = edge[0], to = edge[1];

    graph[from].emplace_back(to);
    graph[to].emplace_back(from);
  }

  int answer = 0;
  for (int node = 0; node < n; node++) {
    if (visited[node]) continue;
    answer += 1;

    queue<int> q;
    q.push(node);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      visited[cur] = true;

      for (int& next : graph[cur]) {
        if (visited[next]) continue;
        q.push(next);
      }
    }
  }

  return answer;
}
```

## 고생한 점
