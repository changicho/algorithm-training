# 1038. Binary Search Tree to Greater Sum Tree

[링크](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

재귀호출을 이용해 오른쪽 노드부터 순회할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

재귀호출을 이용할 경우 call stack에 최대 O(N)의 공간 복잡도가 필요하다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

트리의 오른쪽 노드부터 순회하며 현재까지 방문한 노드들의 원본 val의 합을 현재 노드에 더한다.

이후 합을 갱신하고 왼쪽 노드를 순회한다.

```cpp
int sum = 0;

void recursive(TreeNode *node) {
  if (!node) return;
  recursive(node->right);

  int val = node->val;
  node->val += sum;
  sum += val;

  recursive(node->left);
}

TreeNode *bstToGst(TreeNode *root) {
  recursive(root);

  return root;
}
```

## 고생한 점
