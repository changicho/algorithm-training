# 572. Subtree of Another Tree

[링크](https://leetcode.com/problems/subtree-of-another-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 개수를 N이라 하자.

서브 트리의 루트 노드와 같은 값인 노드들에 대해서 서브트리가 같은지 확인해야 한다.

확인 하는 데에 O(N)의 시간 복잡도가 소요되며, 모든 노드를 한번 훑으며 서브트리와 같은 값을 찾는 outer시간 복잡도 또한 O(N)이다.

따라서 시간 복잡도는 O(N^2)이다

### 공간 복잡도

call stack에 최대 O(N)까지 쌓일 수 있으므로 공간 복잡도는 O(N)이다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(N^2)    |    O(N)     |

먼저 재귀호출을 통해 현재 노드가 서브트리의 루트 노드가 될 수 있는 경우, 서브트리와 같은지 비교를 수행한다.

만약 이 값이 true라면 (서브트리가 같다면) true를 반환한다.

그 외의 경우는 서브트리의 루트 노드가 같을 때 까지 탐색을 반복한다.

서브트리끼리의 비교연산 또한 재귀호출을 이용해 구현 가능하다.

```cpp
bool isSame(TreeNode* a, TreeNode* b) {
  if (!a && !b) return true;
  if (!a || !b) return false;
  if (a->val != b->val) return false;

  return isSame(a->left, b->left) && isSame(a->right, b->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  if (!root) return false;
  if (isSame(root, subRoot)) return true;

  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```

## 고생한 점
