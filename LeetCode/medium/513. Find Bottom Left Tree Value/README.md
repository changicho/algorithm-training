# 513. Find Bottom Left Tree Value

[링크](https://leetcode.com/problems/find-bottom-left-tree-value/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

트리를 순회할 때 왼쪽 노드부터 방문할 경우 각 깊이마다의 최초의 노드를 구할 수 있다.

이를 DFS로 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

BFS로 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS로 탐색할 경우 재귀 호출을 이용하므로 O(N)의 공간 복잡도가 필요하다.

BFS로 탐색할 경우 큐에 최대 O(N)의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(N)     |

트리를 왼쪽부터 순회하며 각 depth마다 최초의 노드인 경우 정답을 갱신한다.

```cpp
int depth = -1;
int answer = -1;

void recursive(TreeNode *node, int depth) {
  if (depth > this->depth) {
    answer = node->val;
    this->depth = depth;
  }

  if (node->left) recursive(node->left, depth + 1);
  if (node->right) recursive(node->right, depth + 1);
}

int findBottomLeftValue(TreeNode *root) {
  recursive(root, 0);

  return answer;
}
```

### BFS by step

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

depth별로 BFS를 진행하며 각 depth별로 최초의 노드를 찾는다.

이 때 노드의 왼쪽 자식부터 큐에 삽입한다.

```cpp
int findBottomLeftValue(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);

  int answer = root->val;
  while (!q.empty()) {
    int size = q.size();

    answer = q.front()->val;
    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }
  }
  return answer;
}
```

## 고생한 점
