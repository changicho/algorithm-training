# 2421. Number of Good Paths

[링크](https://leetcode.com/problems/number-of-good-paths/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E라 하자.

각 노드를 루트로 매번 순회하며 정답을 증가시킬 경우 O(N^2)의 시간 복잡도를 사용한다.

union find를 응용해 가능한 경우들만 탐색하며 정답을 증가시킬 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 간선을 그래프로 표현하는 데 O(E)의 공간 복잡도를 사용한다.

유니온 파인드에 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     738      | O(N \* log_2(N) + E) |  O(N + E)   |

특정 서브트리에 대해 가능한 경우의 수는 다음과 같다.

- 각 노드들의 값을 count한다.
- 각 값마다 노드의 갯수를 n이라 할 때, 이 중 2가지를 고르는 경우의 수 이므로
- n \* (n + 1) / 2 가 된다

여기서 각 노드들을 연결할 때 현재 노드가 다음 노드보다 값이 큰 경우들만 연결할 수 있다.

따라서 각 노드들을 값에 대해 묶고 값이 작은 순서대로 노드들을 그래프에 포함시키며 해당 상황마다의 서브트리에서 현재 값을 가지는 경우의 수를 구한다.

여기서 각 상황마다 서브트리가 여러개 생길 수 있으므로 연결된 노드들 끼리는 union find를 이용해 묶는다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> graph;
vector<int> parents;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);

  if (a > b) swap(a, b);
  if (a == b) return;
  parents[b] = a;
}

int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
  int size = vals.size();

  graph.resize(size);
  parents.resize(size);

  map<int, vector<int>> valuesToNodes;
  for (int node = 0; node < size; node++) {
    valuesToNodes[vals[node]].push_back(node);
    parents[node] = node;
  }

  for (vector<int> &e : edges) {
    int a = e.front(), b = e.back();

    graph[b].push_back(a);
    graph[a].push_back(b);
  }

  int answer = 0;
  for (auto &[value, nodes] : valuesToNodes) {
    for (int node : nodes) {
      for (int next : graph[node]) {
        if (vals[node] < vals[next]) continue;
        merge(node, next);
      }
    }

    unordered_map<int, int> group;
    for (int node : nodes) {
      group[find(node)]++;
    }

    for (auto &[_, size] : group) {
      answer += (size * (size + 1) / 2);
    }
  }

  return answer;
}
```

## 고생한 점
