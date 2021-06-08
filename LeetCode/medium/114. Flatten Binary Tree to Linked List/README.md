# 114. Flatten Binary Tree to Linked List

[링크](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

모든 노드를 inOrder순으로 방문해야 하므로 방문에 걸리는 시간 복잡도는 O(N)이다.

내부적으로 flatten을 수행하는 데 걸리는 시간 복잡도는 O(1)이므로 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

방문 정점을 모두 기록하고 flatten을 수행하는 경우 공간 복잡도는 O(N)이다.

이전 노드에 이어붙이는 식으로 사용할 경우 공간 복잡도는 O(1)이다.

### inOrder travel

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

재귀호출로 inOrder 탐색을 수행하며 이전 노드의 right에 계속 붙여나간다.

이 때 이전 노드의 right가 갱신되므로 다음 탐색을 진행하기 전에 현재 노드의 left, right를 미리 저장한다.

```cpp
TreeNode *pre = new TreeNode();
void flatten(TreeNode *root) {
  recursive(root);
}

void recursive(TreeNode *node) {
  if (!node) return;

  pre->right = node;
  pre = pre->right;

  TreeNode *left = node->left, *right = node->right;

  recursive(left);
  recursive(right);

  node->left = NULL;
}
```

while문으로 위 코드를 구현할 경우 다음과 같다.

```cpp
void flatten(TreeNode *root) {
  TreeNode *cur = root;

  while (cur) {
    if (cur->left) {
      TreeNode *pre = cur->left;
      while (pre->right) {
        pre = pre->right;
      }

      pre->right = cur->right;
      cur->right = cur->left;
      cur->left = NULL;
    }
    cur = cur->right;
  }
}
```

## 고생한 점
