# 144. Binary Tree Preorder Traversal

[링크](https://leetcode.com/problems/binary-tree-preorder-traversal/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 개수는 N이다. 모든 노드를 순회하는데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

재귀호출로 구현할 경우 연산에 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

스택을 이용할 경우 스택에 최대 N개의 노드가 쌓일 수 있으므로 O(N)의 공간 복잡도가 필요하다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

preOrder의 경우 방문 순서는 다음과 같다.

1. Data
2. Left
3. Right

따라서 재귀함수를 이용해 이를 구현할 수 있다.

```cpp
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ret;

  if (root) {
    preOrder(root, ret);
  }

  return ret;
}

void preOrder(TreeNode *node, vector<int> &array) {
  array.push_back(node->val);

  if (node->left) preOrder(node->left, array);
  if (node->right) preOrder(node->right, array);
}
```

preorderTraversal만을 이용할 경우 다음과 같다.

```cpp
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ret;
  if (!root) return {};

  ret.push_back(root->val);
  for (int node : preorderTraversal(root->left)) {
    ret.push_back(node);
  }
  for (int node : preorderTraversal(root->right)) {
    ret.push_back(node);
  }

  return ret;
}
```

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

stack을 이용할 경우 stack에 right, left 순서로 쌓을 경우 preOrder를 구현할 수 있다.

```cpp
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ret;
  stack<TreeNode *> st;

  if (root) st.push(root);

  while (!st.empty()) {
    TreeNode *cur = st.top();
    st.pop();

    ret.push_back(cur->val);

    if (cur->right) st.push(cur->right);
    if (cur->left) st.push(cur->left);
  }

  return ret;
}
```

## 고생한 점
