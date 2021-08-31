# 617. Merge Two Binary Trees

[링크](https://leetcode.com/problems/merge-two-binary-trees/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 트리의 노드의 개수를 각각 N, M이라 하자.

결과적으로 두 트리에서 겹치는 부분은 더하고, 겹치지 않는 노드는 확장해야 하므로 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

새로운 트리를 만들어야 하므로 공간 복잡도는 O(N + M)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |  O(N + M)   |  O(N + M)   |

재귀호출로 root1, root2에 대해서 같이 탐색하며 새로운 트리를 채워넣는다.

```cpp
void recursive(TreeNode*& node, TreeNode*& a, TreeNode*& b) {
  if (a) node->val += a->val;
  if (b) node->val += b->val;

  if (a && a->left || b && b->left) {
    TreeNode* aNext = a ? a->left : NULL;
    TreeNode* bNext = b ? b->left : NULL;
    node->left = new TreeNode();
    recursive(node->left, aNext, bNext);
  }

  if (a && a->right || b && b->right) {
    TreeNode* aNext = a ? a->right : NULL;
    TreeNode* bNext = b ? b->right : NULL;
    node->right = new TreeNode();
    recursive(node->right, aNext, bNext);
  }
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
  if (!root1 && !root2) return NULL;
  TreeNode* temp = new TreeNode();

  recursive(temp, root1, root2);

  return temp;
}
```

## 고생한 점
