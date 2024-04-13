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

임의의 노드를 루트로 지정하고 트리를 루트부터 탐색하며 각 노드가 루트인 서브트리의 아래 2가지 값을 구한다.

- 서브트리의 자식 노드들 갯수 합
- 서브트리의 자식 노드들까지 거리의 합

이를 완료하면 지정한 임의의 루트 노드를 기준으로 다른 노드들까지의 거리와 cost의 합을 구할 수 있다. (정답의 후보 중 하나)

이후 다시 임의의 루트 노드에서부터 DFS로 탐색을 진행하며 각 노드가 루트가 되었을 때의 정답을 구한다.

각 노드가 새로운 루트가 되었을 때 다음과 같은 변동사항이 발생한다.

- 새로운 루트와 가까워진 노드들은 depth(거리)가 1씩 줄어든다.
- 새로운 루트와 멀어진 노드들은 depth(거리)가 1씩 증가한다.

거리가 1씩 증가하는 경우 멀어지는 costs 만큼 증가시켜야 하며 거리가 1씩 줄어드는 경우 가까워지는 costs 만큼 감소시켜야 한다.

여기서 가까워지는 노드들은 해당 노드를 subTree의 루트로 하는 자식 노드들로, 멀어지는 노드들은 그 외 노드들로 생각할 수 있다.

따라서 감소하는 costs들과 증가하는 costs들은 이미 구해놨으므로 바로 계산이 가능하다.

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
