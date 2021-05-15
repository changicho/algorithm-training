# 145. Binary Tree Postorder Traversal

[링크](https://leetcode.com/problems/binary-tree-postorder-traversal/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

모든 노드를 순회하는데 기본적으로 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

스택을 이용할 경우 별도의 O(N)의 공간이 필요하다.

Morris traversal, 재귀호출을 이용할 경우 별도의 공간이 필요하지 않다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

후위 순회의 경우 다음과 같은 순으로 방문한다

1. Left
2. Right
3. Data

```cpp
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> ret;
  if (root) postOrder(root, ret);

  return ret;
}
void postOrder(TreeNode* node, vector<int>& array) {
  if (node->left) postOrder(node->left, array);
  if (node->right) postOrder(node->right, array);
  array.push_back(node->val);
}
```

별도의 함수가 아니라 자기 자신을 호출할 경우 다음과 같이 표현할 수 있다.

```cpp
vector<int> postorderTraversal(TreeNode* root) {
  if (!root) return {};
  vector<int> ret;

  for (int node : postorderTraversal(root->left)) ret.push_back(node);
  for (int node : postorderTraversal(root->right)) ret.push_back(node);
  if (root) ret.push_back(root->val);

  return ret;
}
```

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

스택으로 순회를 할 때 먼저 node-left 순으로 계속 순회를 진행한다.

이 경우 stack의 top에는 왼쪽으로 순회했을 때 가장 마지막 노드가 담겨있다.

이 순으로 순회를 진행하며 만약 right가 존재하는 경우는 right를 기준으로 다시 left 노드들을 모두 스택에 담는다.

따라서 스택에는 left를 먼저 순회하고, 이후 right를 순회한 순으로 쌓이게 되며 top부터 차례로 데이터를 담을 경우 postOrder순으로 탐색한 결과가 된다.

```cpp
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> ret;
  stack<TreeNode*> st;
  TreeNode* lastNode = NULL;

  while (root || !st.empty()) {
    if (root) {
      st.push(root);
      root = root->left;

      continue;
    }

    TreeNode* node = st.top();
    if (node->right && lastNode != node->right) {
      root = node->right;
      continue;
    }

    ret.push_back(node->val);
    lastNode = node;
    st.pop();
  }
  return ret;
}
```

### Morris Traversal

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

Morris 순회는 트리를 변형하는 순회 방법이다.

처리되는 노드가 왼쪽 서브트리를 가지지 않도록 임시로 트리를 변형하여 왼쪽 서브트리의 탐색, 방문 없이 순회가 이루어질 수 있도록 한다.

왼쪽에 위치한 노드들을 현재 트리에서 root로 설정하며 트리를 연결리스트로 생성한다.

Morris 알고리즘은 왼쪽 자식 수가 많은 경우에 성능이 상당히 떨어지는 경향이 있다.

```cpp
MorrisInorder()
  while not finished
    if node has no left descendant
      visit it;
      go to the right;
    else
      make this node right child of the rightmost node in its left descendant;
      go to this left descendant;
```

```cpp
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> ret;
  TreeNode* dummy = new TreeNode(0);
  dummy->left = root;
  TreeNode* cur = dummy;

  while (cur) {
    if (!cur->left) {
      cur = cur->right;
      continue;
    }

    TreeNode* pre = cur->left;

    while (pre->right && (pre->right != cur)) {
      pre = pre->right;
    }

    if (!(pre->right)) {
      pre->right = cur;
      cur = cur->left;
    } else {
      reverseAddNodes(cur->left, pre, ret);

      pre->right = NULL;
      cur = cur->right;
    }
  }
  return ret;
}

void reverseNodes(TreeNode* start, TreeNode* end) {
  if (start == end) return;

  TreeNode* x = start;
  TreeNode* y = start->right;
  TreeNode* z;

  while (x != end) {
    z = y->right;
    y->right = x;
    x = y;
    y = z;
  }
}

void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& array) {
  reverseNodes(start, end);
  TreeNode* node = end;

  while (true) {
    array.push_back(node->val);

    if (node == start) break;
    node = node->right;
  }

  reverseNodes(end, start);
}
```

## 고생한 점
