# 2316. Count Unreachable Pairs of Nodes in an Undirected Graph

[링크](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E라 하자.

각 노드들의 집합을 구한뒤, 각 집합에 대해 가능한 경우의 수를 계산해 구할 수 있다.

이를 위해 DFS와 disjoint set을 이용할 수 있다.

disjoint set을 이용할 경우 O(N + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

disjoint set을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     937      |  O(N + E)   |    O(N)     |

간선들을 돌며 각 노드들의 집합들을 생성한다.

이후 각 집합을 순회하며, 현재 집합에 대해서 만들 수 있는 경우의 수를 센다.

이는 다음과 같이 구할 수 있다.

- 현재 집합의 노드 수를 X라 하자.
- 가능한 조합의 수는 X \* (N - X)이다.

여기서 모든 집합에 대해 순회해 구할 경우 중복된 경우가 생성된다.

따라서 모든 경우의 수에서 2를 나눈 값을 반환한다.

```cpp
vector<int> parents;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) return;
  if (a > b) swap(a, b);
  parents[b] = a;
}

long long countPairs(int n, vector<vector<int>> &edges) {
  parents.resize(n);
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  for (vector<int> &e : edges) {
    int a = e[0], b = e[1];
    merge(a, b);
  }

  long long answer = 0;
  unordered_map<int, int> counts;
  for (int node = 0; node < n; node++) {
    counts[find(node)]++;
  }

  for (auto &it : counts) {
    int key = it.first, val = it.second;

    answer += (long long)val * (n - val);
  }
  return answer / 2;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1030     |  O(N + E)   |  O(N + E)   |

위 방법과 동일하게 현재 그룹의 노드의 수를 DFS로 탐색해 구한다.

이후 각 그룹마다 순회하며 정답을 갱신한다.

```cpp
vector<bool> visited;

void recursive(int node, vector<vector<int>> &graph, int &count) {
  count++;
  visited[node] = true;
  for (int &next : graph[node]) {
    if (visited[next]) continue;
    recursive(next, graph, count);
  }
}

long long countPairs(int n, vector<vector<int>> &edges) {
  visited.resize(n, false);
  vector<vector<int>> graph(n);
  for (vector<int> &e : edges) {
    int from = e[0], to = e[1];
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  long long answer = 0;
  for (int node = 0; node < n; node++) {
    if (visited[node]) continue;

    int count = 0;
    recursive(node, graph, count);

    answer += (long long)(count) * (n - count);
  }

  return answer / 2;
}
```

## 고생한 점
