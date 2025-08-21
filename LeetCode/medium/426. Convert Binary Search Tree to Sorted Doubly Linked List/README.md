# 426. Convert Binary Search Tree to Sorted Doubly Linked List

[링크](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

중위 순회를 이용해 트리의 노드를 이중 연결 리스트로 변환할 경우 O(N)의 시간이 소요된다.

### 공간 복잡도

기존 트리의 정보를 변환할 경우 O(1)의 공간 복잡도가 소요된다.

DFS에 최대 O(N)의 공간 복잡도가 소요된다.

### 중위 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

중위 순회를 사용해 트리의 노드를 오름차순으로 방문한다.

이 때 마지막 방문한 노드와 현재 노드를 연결해준다.

이후 마지막 노드와 첫 번째 노드를 연결해준다.

```cpp
Node* last;

void recursive(Node* node) {
  Node* left = node->left;
  Node* right = node->right;

  if (left) {
    recursive(left);
  }

  last->right = node;
  node->left = last;

  last = node;

  if (right) {
    recursive(right);
  }
}

Node* treeToDoublyList(Node* root) {
  if (!root) return NULL;

  Node* dummy = new Node(-1);
  dummy->right = root;
  last = dummy;

  recursive(root);

  dummy->right->left = last;
  last->right = dummy->right;

  return dummy->right;
}
```

## 고생한 점
