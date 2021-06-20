# 814. Binary Tree Pruning

[링크](https://leetcode.com/problems/binary-tree-pruning/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

우선 모든 노드를 한번 순회하며 서브트리에 1이 포함되는지 여부를 판별해야 한다.

이 순회중에 모든 노드를 한번 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

내부적으로 left, right의 subTree를 삭제하는데 들어가는 연산은 O(1)이다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 노드에 대해서 방문하므로 call stack에 N번 쌓이므로 O(N)의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

재귀호출로 탐색을 진행하며 1이 포함되지 않은 서브트리를 발견한 경우 해당 노드를 삭제한다.

이 때 루트 노드를 삭제해야 할 경우에는 재귀호출 이후 main method에서 판별한다.

```cpp
TreeNode *pruneTree(TreeNode *root) {
  bool hasOne = false;
  if (root) hasOne = recursive(root);
  if (!hasOne) return NULL;

  return root;
}

bool recursive(TreeNode *node) {
  bool hasOne = false;
  if (node->val == 1) hasOne = true;

  if (node->left) {
    bool hasLeftOne = recursive(node->left);

    if (!hasLeftOne) {
      node->left = NULL;
    } else {
      hasOne = true;
    }
  }

  if (node->right) {
    bool hasRightOne = recursive(node->right);

    if (!hasRightOne) {
      node->right = NULL;
    } else {
      hasOne = true;
    }
  }

  return hasOne;
}
```

## 고생한 점
