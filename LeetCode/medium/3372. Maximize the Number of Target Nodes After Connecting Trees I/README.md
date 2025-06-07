# 3372. Maximize the Number of Target Nodes After Connecting Trees I

[링크](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 정점의 갯수를 V, 간선의 갯수를 E라 하자.

두 트리의 각 노드를 시작점으로 DFS를 수행해 최대값을 구할 수 있다.

이 경우 시간 복잡도는 O(V \* (V + E))이다.

### 공간 복잡도

DFS에 O(V + E)의 공간이 필요하다.

### DFS

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      98      | O(V \* (V + E)) |  O(V + E)   |

첫번째 트리에서 아무 노드나 선택해도, 두번째 트리에서는 가장 유리한 노드를 선택해야 maximum을 구할 수 있다.

두 트리에 대해서 각 노드를 루트로 하는 거리가 k까지인 노드의 갯수를 DFS로 구할 수 있다.

이후 첫번째 트리에서 각 노드마다 도달 가능한 갯수와 두번째 트리에서 도달 가능한 최대값을 구해 각 노드마다의 최대값을 구한다.

```cpp
int recursive(int node, int parent, vector<vector<int>>& graph, int k) {
  if (k < 0) {
    return 0;
  }
  int count = 1;
  for (int& next : graph[node]) {
    if (next == parent) {
      continue;
    }
    count += recursive(next, node, graph, k - 1);
  }
  return count;
}

vector<int> build(int size, vector<vector<int>>& edges, int k) {
  vector<vector<int>> graph(size);
  for (vector<int>& e : edges) {
    int a = e[0], b = e[1];

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<int> count(size);
  for (int i = 0; i < size; i++) {
    count[i] = recursive(i, -1, graph, k);
  }
  return count;
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
  int size1 = edges1.size() + 1;
  int size2 = edges2.size() + 1;

  vector<int> count1 = build(size1, edges1, k);
  vector<int> count2 = build(size2, edges2, k - 1);

  int maximum2 = *max_element(count2.begin(), count2.end());

  vector<int> answer(size1);

  for (int i = 0; i < size1; i++) {
    answer[i] = count1[i] + maximum2;
  }

  return answer;
}
```

## 고생한 점
