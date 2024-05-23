# 1325. Delete Leaves With a Given Value

[링크](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

재귀 호출을 이용해 현재 노드를 자식 노드들을 먼저 방문 후 삭제해야 하는 경우를 판별할 수 있다.

이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

재귀호출을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(N)     |

현재 노드가 리프 노드인 경우 삭제해야 한다.

이 때 자식 노드가 없어진 경우 또한 삭제해야 한다.

따라서 먼저 자식 노드들을 방문한 뒤 현재 노드가 리프인 경우 삭제한다.

```cpp
TreeNode *removeLeafNodes(TreeNode *root, int target) {
  if (!root) return NULL;

  root->left = removeLeafNodes(root->left, target);
  root->right = removeLeafNodes(root->right, target);

  // leaf case
  if (!root->left && !root->right) {
    if (root->val == target) return NULL;
    return root;
  }

  return root;
}
```

## 고생한 점
