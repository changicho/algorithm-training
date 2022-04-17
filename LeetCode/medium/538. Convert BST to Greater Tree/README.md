# 538. Convert BST to Greater Tree

[링크](https://leetcode.com/problems/convert-bst-to-greater-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 노드들을 방문하며 값을 증가시켜야 하므로 방문에 O(N)의 시간 복잡도를 사용한다.

이전에 방문한 직전 노드의 값을 알면 되며 이를 다음 단계에 넘기면 되므로 계산에 별도의 시간 복잡도를 사용하지 않는다.

### 공간 복잡도

트리 탐색에 O(N)의 공간 복잡도를 사용한다.

### recursive

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      41      |    O(N)     |    O(N)     |

각 노드는, 자신보다 큰 값을 가진 노드들의 원래 값의 합만큼 더해줘야한다.

트리는 BST이므로 재귀호출을 이용해 큰 값인 노드들부터 우선 탐색해 값을 갱신하고, 현재 값을 다음에 탐색하는 노드에 넘겨준다. (갱신된 현재 값이 다음에 방문하는 노드보다 큰 값들의 합이므로)

이를 구현하면 다음과 같다.

```cpp
int before = 0;

void recursive(TreeNode *node) {
  if (node->right) recursive(node->right);

  node->val += before;
  before = node->val;

  if (node->left) recursive(node->left);
}

TreeNode *convertBST(TreeNode *root) {
  if (!root) return NULL;

  recursive(root);

  return root;
}
```

## 고생한 점
