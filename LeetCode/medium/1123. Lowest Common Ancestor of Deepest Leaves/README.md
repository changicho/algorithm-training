# 1123. Lowest Common Ancestor of Deepest Leaves

[링크](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

LCA 알고리즘을 사용해 리프의 LCA를 구하는 데 DFS를 사용할 경우 O(N) 시간 복잡도를 사용한다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도를 사용한다.

### LCA (dfs)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

리프 노드중 가장 깊은 노드의 depth를 구한다.

이후 depth가 가장 깊은 리프 노드들의 LCA를 구한다.

DFS를 이용해 depth가 가장 깊은 노드만 반환하며 만약 현재 노드의 left, right가 모두 존재하는 경우 현재 노드가 LCA가 된다.

```cpp
int maxDepth = 0;

TreeNode* dfs(TreeNode* root, int len) {
  if (!root) return NULL;
  if (maxDepth == len) return root;

  TreeNode* left = dfs(root->left, len + 1);
  TreeNode* right = dfs(root->right, len + 1);

  if (left && right) return root;

  return left ? left : right;
}

void getDepth(TreeNode* node, int depth) {
  maxDepth = max(maxDepth, depth);
  if (node->left) getDepth(node->left, depth + 1);
  if (node->right) getDepth(node->right, depth + 1);
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
  getDepth(root, 0);

  return dfs(root, 0);
}
```

## 고생한 점
