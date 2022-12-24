# 834. Sum of Distances in Tree

[링크](https://leetcode.com/problems/sum-of-distances-in-tree/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자. (N은 최대 3 \* 10^4)

간선의 갯수는 N-1개이다.

모든 노드에 대해 BFS를 이용해 거리를 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

이는 제한시간 내에 불가능하다.

각 트리를 서브트리로 나누어 탐색하는 DFS를 이용해 탐색할 수 있다. 이 경우 탐색에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용해 탐색할 경우 호출 스택에 O(N)의 공간 복잡도를 사용한다.

입력받은 간선 정보를 그래프로 표현하는 데 O(N)의 공간 복잡도를 사용한다.

### 서브트리 탐색 DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     227      |    O(N)     |    O(N)     |

```cpp
vector<int> ans, count;
vector<vector<int>> graph;
int size;

void dfs(int node, int parent) {
  for (int &child : graph[node])
    if (child != parent) {
      dfs(child, node);
      count[node] += count[child];
      ans[node] += ans[child] + count[child];
    }
}

void dfs2(int node, int parent) {
  for (int &child : graph[node])
    if (child != parent) {
      ans[child] = ans[node] - count[child] + size - count[child];
      dfs2(child, node);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
  this->size = n;
  graph.resize(n);
  ans.resize(n, 0);
  count.resize(n, 1);

  for (vector<int> &edge : edges) {
    int a = edge.front(), b = edge.back();
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(0, -1);
  dfs2(0, -1);
  return ans;
}
```

## 고생한 점
