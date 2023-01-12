# 1519. Number of Nodes in the Sub-Tree With the Same Label

[링크](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자. 간선의 갯수 E는 N-1개이다.

루트노드에서부터 DFS로 탐색하며 현재 자식노드들의 알파벳의 수를 반환한다.

이 경우 각 노드르 시작점으로 하는 서브트리의 알파벳의 수 들을 계산할 수 있다.

그래프를 생성하는데 O(E), DFS에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프와 각 노드에 대한 정보를 저장하는 데 O(N)의 공간 복잡도를 사용한다.

각 count를 저장하는데 26가지의 정보가 필요하며 이에 O(1)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     545      |    O(N)     |    O(N)     |

DFS를 이용해 각 과정마다 현재 노드를 루트로 하는 서브트리의 알파벳의 수를 반환한다.

이 경우 각 노드를 방문하면서 하위 노드들의 값을 반환하며 값을 계산할 수 있다.

```cpp
vector<int> counts;
vector<vector<int>> graph;
vector<bool> visited;
string labels;

vector<int> recursive(int node) {
  visited[node] = true;

  vector<int> ret(26, 0);
  ret[labels[node] - 'a']++;

  for (int &next : graph[node]) {
    if (visited[next]) continue;
    vector<int> child = recursive(next);

    for (int i = 0; i < 26; i++) {
      ret[i] += child[i];
    }
  }

  counts[node] = ret[labels[node] - 'a'];
  return ret;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
  counts.resize(n, 0);
  graph.resize(n);
  visited.resize(n, 0);
  this->labels = labels;

  for (vector<int> &e : edges) {
    int from = e.front(), to = e.back();

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  recursive(0);

  return counts;
}
```

## 고생한 점
