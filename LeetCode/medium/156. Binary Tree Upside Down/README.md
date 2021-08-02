# 156. Binary Tree Upside Down

[링크](https://leetcode.com/problems/binary-tree-upside-down/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리안의 모든 노드의 개수를 N이라 하자.

모든 left 노드들을 순회하며 연결 구조를 바꿔줘야한다.

최악의 경우는 모든 left노드만 존재하는 구조이므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

call stack에 최악의 경우 N개까지 쌓일 수 있다. 이 때 공간 복잡도는 O(N)이다.

혹은 left만 방문하면 되므로 iterate를 이용해 풀이할 수 있다. 이 경우 공간 복잡도는 O(1)이다.

### 재귀

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

재귀 호출을 이용해 새로운 tree의 root를 찾고, 이후 연결관계를 뒤집는다.

이는 top-down으로 연결 관계를 뒤집을 경우 이후 탐색할 노드에서 원본 자식을 찾을 수 없기 때문이다.

```cpp
TreeNode* subRoot = NULL;

void recursive(TreeNode* node) {
  if (!node->left && !subRoot) {
    subRoot = node;
  }

  if (!node->left && !node->right) return;

  if (node->left) recursive(node->left);

  TreeNode* left = node->left;
  TreeNode* right = node->right;

  left->right = node;
  left->left = right;

  node->left = node->right = NULL;
}

TreeNode* upsideDownBinaryTree(TreeNode* root) {
  if (root) recursive(root);

  return subRoot;
}
```

### 반복문

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

위 방법에서 left를 방문하며 부모의 연결관계를 갱신하며 탐색을 진행할 경우 다음에 방문할 노드를 찾을 수 있다.

```cpp
TreeNode* upsideDownBinaryTree(TreeNode* root) {
  TreeNode* cur = root;

  TreeNode *parent = NULL, *right = NULL, *next = NULL;

  while (cur) {
    next = cur->left;

    cur->left = right;
    right = cur->right;
    cur->right = parent;
    parent = cur;

    cur = next;
  }
  return parent;
}
```

## 고생한 점
