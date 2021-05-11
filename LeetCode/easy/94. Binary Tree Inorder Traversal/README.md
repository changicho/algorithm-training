# 94. Binary Tree Inorder Traversal

[링크](https://leetcode.com/problems/binary-tree-inorder-traversal/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

inOrder로 트리를 순회해야한다.

결국 트리의 모든 노드를 순회해야 하며, 노드의 최대 개수는 100개이다. 노드의 개수를 N개라 했을 때 시간 복잡도는 O(N)이다.

### 공간 복잡도

방문 노드를 기록하기 위해 O(N)의 공간이 필요하다.

스택을 이용하는 경우 별도의 공간이 필요하다. 최악의 경우 스택에 쌓이는 갯수는 N개 이므로 O(N)의 공간 복잡도가 필요하다.

### 재귀 호출 inOrder

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

inOrder를 재귀호출로 직접 구현한다.

- preOrder : Data, Left, Right
- inOrder : Left, Data, Right
- postOrder : Left, Right, Data

```cpp
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ret;

  if (root) inOrder(root, ret);

  return ret;
}

void inOrder(TreeNode *node, vector<int> &array) {
  if (node->left) inOrder(node->left, array);
  array.push_back(node->val);
  if (node->right) inOrder(node->right, array);
}
```

### stack

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

왼쪽부터 방문하며 현재 노드가 리프 노드일 경우 가장 최근에 방문한 노드의 Data, Right를 이용한다.

```cpp
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ret;
  stack<TreeNode *> s;

  TreeNode *cur = root;
  while (cur || !s.empty()) {
    while (cur) {
      s.push(cur);
      cur = cur->left;
    }
    cur = s.top();
    s.pop();
    ret.push_back(cur->val);
    cur = cur->right;
  }

  return ret;
}
```

### Morris Traversal

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

1. 현재 노드를 루트 노드로 설정한다.
2. 현재 노드가 NULL이 아닌 경우

- 현재 노드가 left 자식이 없는 경우
  - 현재 값을 방문에 기록한다
  - right 노드를 방문한다.
- 현재 노드가 left 자식이 있는 경우
  - left 자식의 서브트리 의 가장 오른쪽 자식 노드의 자식으로 현재 노드를 붙인다.
  - left 노드를 방문한다.

```cpp
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ret;

  TreeNode *cur = root;
  TreeNode *pre;

  while (cur) {
    if (!cur->left) {
      ret.push_back(cur->val);
      cur = cur->right;
    } else {
      pre = cur->left;

      while (pre->right) {
        pre = pre->right;
      }

      pre->right = cur;
      TreeNode *temp = cur;
      cur = cur->left;
      temp->left = NULL;
    }
  }

  return ret;
}
```

## 고생한 점
