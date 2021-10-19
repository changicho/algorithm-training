# 993. Cousins in Binary Tree

[링크](https://leetcode.com/problems/cousins-in-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

우선 모든 노드를 탐색하며 x, y를 찾아야 하므로 x와 y를 찾는 데 O(N)의 시간 복잡도를 사용한다.

이 때 x, y의 부모와 level 또한 같이 탐색하면 되므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

x, y의 level과 부모를 같이 찾으면 되므로 이는 별도의 공간에 저장하지 않아도 된다.

따라서 O(1)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

BFS를 이용해 level별로 탐색을 진행한다.

이 때 현재 노드에서 다음 level에 자식 노드를 삽입할 때 해당 노드가 x, y인 경우 부모 노드를 저장한다.

이후 현재 노드가 x, y인 경우 해당 노드의 level을 저장한다.

이후 level이 같은지, 부모가 다른지를 판별하고 두 조건 모두 참인 경우 true를, 아닌 경우 false를 반환한다.

```cpp
bool isCousins(TreeNode *root, int x, int y) {
  queue<TreeNode *> q;
  if (root) q.push(root);

  int first = 0, second = 0;
  int parentFirst = 0, parentSecond = 0;

  int step = 0;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      if (cur->val == x) {
        first = step;
      }
      if (cur->val == y) {
        second = step;
      }

      if (cur->left) {
        q.push(cur->left);
        if (cur->left->val == x) parentFirst = cur->val;
        if (cur->left->val == y) parentSecond = cur->val;
      }
      if (cur->right) {
        q.push(cur->right);
        if (cur->right->val == x) parentFirst = cur->val;
        if (cur->right->val == y) parentSecond = cur->val;
      }
    }
    step += 1;
  }

  return first == second && parentFirst != parentSecond;
}
```

## 고생한 점
