# 3373. Maximize the Number of Target Nodes After Connecting Trees II

[링크](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

두 트리의 노드의 갯수의 합을 V, 간선의 수의 합을 E라 하자.

각 트리마다 루트 노드를 시작점으로 지나는 간선의 수가 짝수, 홀수인 경우로 나눌 수 있다.

이에 DFS를 사용할 경우 O(V + E)의 시간 복잡도를 사용한다.

이후 첫번째 트리의 노드마다 간선의 수 (짝수, 홀수) 여부와 해당 그룹에 속하는 수를 이용해 정답을 구할 수 있다.

이에 O(V)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 사용해 짝수, 홀수를 나눌 경우 O(V + E)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     272      |  O(V + E)   |  O(V + E)   |

DFS를 이용해 트리에서 루트에서부터 각 노드마다 지나치는 간선의 수가 짝수, 홀수인 경우로 나눈다.

이후 짝수인 노드와 수와 홀수인 노드의 수를 구한다.

첫번째 트리의 노드를 순회하며 해당 노드에 속하는 수를 구할 수 있다.

이 때 해당 노드에 두번째 트리에 속하는 홀수, 짝수 노드의 수 중 최대값을 더해주면 된다.

```cpp
int recursive(int node, int parent, int depth, vector<vector<int>>& graph, vector<int>& color) {
  int redCount = 1 - depth % 2;
  color[node] = depth % 2;

  for (int& next : graph[node]) {
    if (next == parent) continue;

    redCount += recursive(next, node, depth + 1, graph, color);
  }
  return redCount;
};

// {red, black}
vector<int> build(int size, vector<vector<int>>& edges, vector<int>& color) {
  vector<vector<int>> graph(size);
  for (vector<int>& e : edges) {
    int a = e[0], b = e[1];

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int res = recursive(0, -1, 0, graph, color);
  return {res, size - res};
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
  int size1 = edges1.size() + 1, size2 = edges2.size() + 1;

  vector<int> color1(size1);
  vector<int> color2(size2);
  vector<int> count1 = build(size1, edges1, color1);
  vector<int> count2 = build(size2, edges2, color2);

  vector<int> res(size1);

  for (int i = 0; i < size1; i++) {
    res[i] = count1[color1[i]] + max(count2[0], count2[1]);
  }
  return res;
}
```

## 고생한 점
