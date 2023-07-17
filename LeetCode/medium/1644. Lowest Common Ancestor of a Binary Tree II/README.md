# 1644. Lowest Common Ancestor of a Binary Tree II

[링크](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

LCA를 찾기 위해선 모든 노드를 탐색해야 하므로 시간 복잡도는 O(N)이다.

두 노드를 찾은 뒤 높이를 맞추고 부모가 같을 때 까지 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

혹은 재귀호출로 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

call stack에 O(N)의 공간 복잡도를 사용한다.

각 노드별로 부모를 저장할 경우 O(N)의 공간 복잡도를 사용한다.

### LCA (depth)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     312      |    O(N)     |    O(N)     |

두 노드 p와 q를 찾은 뒤 루트에서부터의 깊이를 맞추기 위해 부모로 이동한다.

이후 한칸씩 동시에 이동하며 두 노드가 같을 때 까지 탐색한다.

만약 두 노드가 트리에 존재하지 않는 경우 NULL을 반환한다.

```cpp
unordered_map<TreeNode*, int> depths;
unordered_map<TreeNode*, TreeNode*> parents;

void recursive(TreeNode* node, TreeNode* parent, int depth) {
  depths[node] = depth;
  parents[node] = parent;

  if (node->left) {
    recursive(node->left, node, depth + 1);
  }
  if (node->right) {
    recursive(node->right, node, depth + 1);
  }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  recursive(root, NULL, 0);

  if (depths.count(p) == 0 || depths.count(q) == 0) return NULL;

  while (depths[p] > depths[q]) {
    p = parents[p];
  }
  while (depths[q] > depths[p]) {
    q = parents[q];
  }

  while (p != q) {
    p = parents[p];
    q = parents[q];
  }
  return p;
}
```

### LCA (DFS)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     151      |    O(N)     |    O(N)     |

재귀 호출을 사용해 LCA를 찾을 수 있다.

이 경우 한 노드가 다른 노드의 서브트리 관계인 경우 루트에 가까운 쪽이 LCA가 된다.

따라서 p, q중 하나가 LCA인 경우 다른 노드가 서브트리에 존재하는지 확인해야 한다.

```cpp
TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q) {
  if (!node) return NULL;
  if (node == p || node == q) return node;

  TreeNode* left = LCA(node->left, p, q);
  TreeNode* right = LCA(node->right, p, q);

  if (left && right) return node;

  if (left) return left;
  if (right) return right;
  return NULL;
}

bool isSubtree(TreeNode* node, TreeNode* target) {
  if (!node) return false;
  if (node == target) return true;
  return isSubtree(node->left, target) || isSubtree(node->right, target);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode* answer = LCA(root, p, q);
  if (answer == p) {
    // check if q is in the subtree of p
    return isSubtree(p, q) ? p : NULL;
  } else if (answer == q) {
    // check if p is in the subtree of q
    return isSubtree(q, p) ? q : NULL;
  }
  return answer;
}
```

## 고생한 점
