# 285. Inorder Successor in BST

[링크](https://leetcode.com/problems/inorder-successor-in-bst/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 모든 노드의 개수를 N이라 하자.

해당 문제는 트리의 upper_bound를 수행하는 것이므로 balanced tree인 경우 평균 O(log_2(N))의 시간 복잡도로 풀이가 가능하다.

그러나 모든 노드가 한쪽으로 치우친 최악의 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

재귀 호출을 이용할 경우 call stack에 최대 O(N)까지 쌓일 수 있다.

iteration을 사용할 경우 별도의 공간 복잡도가 필요하지 않다.

### 반복문

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(1)     |

트리를 순회하며 현재 노드가 target보다 이하인 경우는 오른쪽으로 이동한다.

현재 노드가 target보다 큰 경우는 현재 노드가 답이 될 수 있으므로 답을 갱신하고 왼쪽으로 이동한다.

```cpp
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
  TreeNode* upper = NULL;
  if (!root || !p) return upper;

  while (root) {
    if (root->val <= p->val) {
      root = root->right;
    } else {
      upper = root;
      root = root->left;
    }
  }

  return upper;
}
```

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

재귀호출을 진행하며 현재 노드의 값이 target이하인 경우는 현재 노드의 오른쪽을 자식으로 재귀 호출을 진행한다.

현재 노드의 값이 target보다 큰 경우는 왼쪽 노드에 대해 재귀호출을 수행한다.

이 때 왼쪽 노드에 대해서 target보다 큰 값이 존재하지 않는 경우는 현재 값을 반환한다.

```cpp
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
  if (!root || !p) return NULL;

  if (root->val <= p->val) {
    return inorderSuccessor(root->right, p);
  }

  TreeNode* ret = inorderSuccessor(root->left, p);
  return ret ? ret : root;
}
```

## 고생한 점
