# 623. Add One Row to Tree

[링크](https://leetcode.com/problems/add-one-row-to-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

재귀호출을 이용해 탐색하며 추가할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀 호출에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(N)     |

재귀 호출을 이용해 현재 depth에 노드를 추가해야 하는 경우 추가한다.

```cpp
TreeNode *addOneRow(TreeNode *root, int val, int depth) {
  if (depth == 1) {
    return new TreeNode(val, root, NULL);
  }

  if (depth == 2) {
    root->left = new TreeNode(val, root->left, NULL);
    root->right = new TreeNode(val, NULL, root->right);
    return root;
  }

  if (root->left) {
    root->left = addOneRow(root->left, val, depth - 1);
  }
  if (root->right) {
    root->right = addOneRow(root->right, val, depth - 1);
  }
  return root;
}
```

## 고생한 점
