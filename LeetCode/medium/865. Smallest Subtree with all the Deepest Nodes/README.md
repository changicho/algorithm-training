# 865. Smallest Subtree with all the Deepest Nodes

[링크](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

DFS를 이용해 각 노드에서 루트까지의 거리를 구할 수 있다. 

가장 깊은 노드들과 같은 거리로 떨어진 최초 노드를 찾는데 DFS를 사용할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

DFS를 이용해 각 노드에서 루트까지의 거리를 구한다.

이 때 해당 노드에서 가장 깊은 노드까지의 거리와, 그 거리에 해당하는 노드를 반환한다.

만약 현재 노드의 왼쪽 자식과 오른쪽 자식에 가장 깊은 노드까지의 거리가 같다면, 현재 노드가 가장 깊은 노드들을 포함하는 최소 서브트리가 된다.

```cpp
pair<TreeNode*, int> dfs(TreeNode* node) {
  if (!node) return {NULL, 0};

  pair<TreeNode*, int> left, right;
  left = dfs(node->left);
  right = dfs(node->right);

  if (left.second > right.second) return {left.first, left.second + 1};
  if (right.second > left.second) return {right.first, right.second + 1};
  return {node, left.second + 1};
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) { return dfs(root).first; }
```

## 고생한 점
