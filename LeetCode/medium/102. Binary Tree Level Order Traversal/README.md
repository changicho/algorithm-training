# 102. Binary Tree Level Order Traversal

[링크](https://leetcode.com/problems/binary-tree-level-order-traversal/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 수를 N이라고 하자.

모든 노드의 값을 계층별로 순회해야하므로 모든 노드를 한번 순회하는데 O(N)의 시간복잡도가 필요하다.

내부적으로 순서에 따라 값을 저장하는데 들어가는 시간 복잡도는 O(1)이다.

### 공간 복잡도

모든 노드의 값을 저장하므로 공간 복잡도는 O(N)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

BFS로 왼쪽부터 오른쪽으로 순회하는 경우 자동적으로 정답을 만들 수 있다.

```cpp
vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> answer;

  queue<TreeNode *> q;
  if (root) q.push(root);

  while (!q.empty()) {
    vector<int> level;
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *cur = q.front();
      q.pop();

      level.push_back(cur->val);

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }
    answer.push_back(level);
  }

  return answer;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

깊이 우선탐색을 진행하며 왼쪽부터 우선 탐색을 진행한다.

정답에서 해당 계층의 vector에 값을 저장한다.

```cpp
vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> answer;

  if (root) recursive(answer, root, 0);

  return answer;
}

void recursive(vector<vector<int>> &answer, TreeNode *node, int level) {
  if (answer.size() <= level) {
    answer.resize(level + 1);
  }

  answer[level].push_back(node->val);

  if (node->left) recursive(answer, node->left, level + 1);
  if (node->right) recursive(answer, node->right, level + 1);
}
```

## 고생한 점
