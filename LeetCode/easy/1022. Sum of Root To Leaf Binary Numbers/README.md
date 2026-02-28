# 1022. Sum of Root To Leaf Binary Numbers

[링크](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 수를 N, 높이를 H라 하자.

DFS를 이용해 모든 노드를 방문할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 사용할 경우 O(H)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(H)     |

DFS를 이용해 리프노드에서 루트노드까지의 비용을 계산한다.

```cpp
int recursive(TreeNode* node, int val) {
  int cur = val * 2 + node->val;
  int leftVal = 0, rightVal = 0;
  if (node->left) {
    leftVal = recursive(node->left, cur);
  }
  if (node->right) {
    rightVal = recursive(node->right, cur);
  }

  if (!node->left && !node->right) {
    return cur;
  }
  return leftVal + rightVal;
}

int sumRootToLeaf(TreeNode* root) {
  if (!root) return 0;

  return recursive(root, 0);
}
```

## 고생한 점
