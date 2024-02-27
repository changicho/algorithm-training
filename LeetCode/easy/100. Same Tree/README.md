# 100. Same Tree

[링크](https://leetcode.com/problems/same-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 개수는 최대 100개이다.

루트 노드부터 각 노드를 순회하며 각각 위치에 올바른 값이 있는지 확인해야 한다.

각 노드를 순회할 때 시간 복잡도는 O(N) 이다.

### 공간 복잡도

BFS로 순회할 경우 queue가 필요하다.

공간 복잡도는 O(N) 이다.

DFS를 사용할 때 call stack에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

전위순회를 이용해 트리를 탐색하고, 만약 현재 값이 다른 경우엔 두 트리가 다르다고 판단할 수 있다.

```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
  queue<TreeNode*> q1;
  queue<TreeNode*> q2;

  q1.push(p);
  q2.push(q);

  while (!q1.empty() && !q2.empty()) {
    TreeNode* cur1 = q1.front();
    TreeNode* cur2 = q2.front();

    q1.pop();
    q2.pop();

    if (!cur1 && !cur2) {
      continue;
    }
    if (!cur1 || !cur2) {
      return false;
    }
    if (cur1->val != cur2->val) {
      return false;
    }

    q1.push(cur1->left);
    q1.push(cur1->right);

    q2.push(cur2->left);
    q2.push(cur2->right);
  }

  return true;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

isSameTree를 재귀호출해 두 트리를 동시에 같은 위치의 노드를 탐색할 수 있다.

```cpp
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    if (!q || !p) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }

    bool ret = isSameTree(p->right, q->right) &&
               isSameTree(p->left, q->left);
    return ret;
  }
};
```

## 고생한 점
