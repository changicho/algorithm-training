# 1367. Linked List in Binary Tree

[링크](https://leetcode.com/problems/linked-list-in-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N, 연결 리스트의 길이를 M이라 하자.

트리를 순회하며 각각 연결 리스트를 갖고 있는지 확인한다.

이에 DFS를 사용할 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(N \* M)  |    O(N)     |

DFS로 트리를 순회하며 각각의 노드에서 연결 리스트를 순회하며 같은지 비교한다.

```cpp
bool answer = false;

void search(ListNode* valNode, TreeNode* node) {
  if (!node || !valNode) {
    answer |= !valNode;
    return;
  }

  if (valNode->val != node->val) {
    return;
  }

  search(valNode->next, node->left);
  search(valNode->next, node->right);
}

void recursive(ListNode* valNode, TreeNode* node) {
  if (node->val == valNode->val) {
    search(valNode, node);
  }

  if (node->left) recursive(valNode, node->left);
  if (node->right) recursive(valNode, node->right);
}

bool isSubPath(ListNode* head, TreeNode* root) {
  recursive(head, root);

  return answer;
}
```

## 고생한 점
