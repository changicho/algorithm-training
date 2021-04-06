# 104. Maximum Depth of Binary Tree

[링크](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 개수는 최대 10^4개 이다.

모든 트리를 탐색하며 깊이(depth)를 구해야 하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

재귀 호출을 이용할 경우 별도의 공간이 필요하지 않다.

너비 우선 탐색을 이용할 경우 별도의 큐가 필요하다.

### DFS

현재 도달한 노드가 NULL인 경우 인자로 받은 depth - 1를 반환한다.

이는 현재 depth에 노드가 없다는 것을 의미하기 때문이다.

현재 노드에서 왼쪽과 오른쪽에 depth + 1을 인자로 준 뒤 탐색을 진행한다.

```cpp
int maxDepth(TreeNode *root) {
  return findLevel(root, 1);
}

int findLevel(TreeNode *root, int depth) {
  if (!root) return depth - 1;

  return max(findLevel(root->left, depth + 1), findLevel(root->right, depth + 1));
}
```

### BFS

depth별로 탐색해야 하므로 현재 q의 size만큼만 탐색을 진행한다.

탐색을 진행하며 push되는 것들은 다음 depth에서 탐색이 진행된다.

큐가 비었을 때까지 depth가 증가하므로 마지막에 하나를 빼준다.

```cpp
int maxDepth(TreeNode *root) {
  queue<TreeNode *> q;

  q.push(root);
  int depth = 0;

  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *cur = q.front();
      q.pop();

      if (!cur) continue;
      q.push(cur->left);
      q.push(cur->right);
    }

    depth += 1;
  }

  return depth - 1;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|              |

## 고생한 점
