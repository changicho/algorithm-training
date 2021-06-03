# 226. Invert Binary Tree

[링크](https://leetcode.com/problems/invert-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

모든 노드들을 한번씩 순회해야 하므로 outer 시간 복잡도는 O(N)이다.

내부적으로 자식을 invert 하는데 들어가는 연산은 O(1)의 시간복잡도이다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

DFS, BFS를 통해서 모든 노드를 방문할 때 call stack, queue에 모두 최대 N개의 데이터가 쌓일 수 있다.

따라서 공간 복잡도는 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

재귀호출을 수행하며 각 노드의 left와 right를 교환한다.

이를 모든 노드에서 반복한다.

```cpp
TreeNode *invertTree(TreeNode *root) {
  recursive(root);
  return root;
}

void recursive(TreeNode *node) {
  if (!node) return;

  swap(node->left, node->right);

  recursive(node->left);
  recursive(node->right);
}
```

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

위 방법에서 모든 노드의 순회를 BFS로 한다.

```cpp
TreeNode *invertTree(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *cur = q.front();
    q.pop();

    if (!cur) continue;

    swap(cur->left, cur->right);

    q.push(cur->left);
    q.push(cur->right);
  }

  return root;
}
```

## 고생한 점
