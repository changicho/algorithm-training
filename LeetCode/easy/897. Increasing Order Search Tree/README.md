# 897. Increasing Order Search Tree

[링크](https://leetcode.com/problems/increasing-order-search-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 높이를 H라 하자.

모든 노드를 순회하는데 O(N)의 시간 복잡도를 사용한다.

inorder로 순회한 순서를 저장해 이후 별도의 링크드 리스트를 만들 경우 O(N)의 시간 복잡도를 사용한다.

inorder로 순회한 순서째로 트리를 변환할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 노드를 순회한 순서를 저장하고 이어서 만들 경우 순회 순서를 저장하는 데 O(N)의 공간 복잡도를 사용한다.

inorder로 순회할 경우 재귀 호출에 O(H)의 공간 복잡도를 사용한다.

### 방문 경로 저장

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

노드를 재귀호출로 방문한 경로를 vector에 저장 후 정답으로 변환한다.

```cpp
void recursive(TreeNode* node, vector<int>& v) {
  if (node->left) recursive(node->left, v);
  v.push_back(node->val);
  if (node->right) recursive(node->right, v);
}

TreeNode* increasingBST(TreeNode* root) {
  vector<int> visited;
  if (root) recursive(root, visited);

  TreeNode* head = new TreeNode();
  TreeNode* cur = head;

  for (int& v : visited) {
    cur->right = new TreeNode(v);
    cur = cur->right;
  }

  return head->right;
}
```

### inorder

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(H)     |

트리를 inorder로 순회하며 노드를 이어붙인다.

이 때 기존의 연결 관계를 끊어줘야 함에 유의한다.

```cpp
TreeNode* cur = NULL;

void recursive(TreeNode* node) {
  if (node->left) recursive(node->left);
  node->left = NULL;
  cur->right = node;
  cur = node;
  if (node->right) recursive(node->right);
}

TreeNode* increasingBST(TreeNode* root) {
  TreeNode* head = new TreeNode();
  cur = head;

  if (root) recursive(root);

  return head->right;
}
```

## 고생한 점
