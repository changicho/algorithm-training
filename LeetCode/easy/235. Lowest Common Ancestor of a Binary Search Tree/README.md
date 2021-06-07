# 235. Lowest Common Ancestor of a Binary Search Tree

[링크](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

모든 노드의 갯수를 N이라 하자.

BST구조이므로 p와 q의 값을 알기 때문에 탐색을 바로 진행할 수 있다.

따라서 탐색을 진행하며 최소 공통조상을 찾는다. 이 때 트리가 모두 한쪽으로 쏠린 경우 모든 요소를 탐색하게된다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

현재 진행중인 노드에 대해서만 알면 된다. 따라서 공간 복잡도는 O(1)이다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(1)     |

> 콜 스택을 생성하기 때문에 반복문을 돌리는 것보다 시간이 오래걸림

현재 노드에서 p와 q의 값을 모두 만족하는 경우 left, right중 하나로 재귀호출로 탐색을 진행한다.

두 경우 모두 만족하지 않는 경우는 자식에서 탐색이 갈리는 부분이므로 현재 노드가 최소 공통 조상이 된다.

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root->val < p->val && root->val < q->val) {
    return lowestCommonAncestor(root->right, p, q);
  } else if (root->val > p->val && root->val > q->val) {
    return lowestCommonAncestor(root->left, p, q);
  }

  return root;
}
```

### 반복문

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(1)     |

p를 탐색하는 first, q를 탐색하는 second를 설정하고 탐색을 진행한다.

first와 second가 다른 경우는 탐색을 중지한다.

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode *first = root, *second = root;
  TreeNode* head = root;

  while (first == second) {
    head = first;
    if (head->val < p->val) {
      first = first->right;
    } else if (head->val > p->val) {
      first = first->left;
    }

    if (head->val < q->val) {
      second = second->right;
    } else if (head->val > q->val) {
      second = second->left;
    }
  }

  return head;
}
```

## 고생한 점
