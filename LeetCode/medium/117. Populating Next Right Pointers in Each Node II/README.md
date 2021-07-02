# 117. Populating Next Right Pointers in Each Node II

[링크](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

모든 노드를 한번씩 방문해야 한다.

따라서 outer 시간 복잡도는 O(N)이다.

level별로 순회하며 옆 노드들을 next로 이어야 한다. 이 next를 찾기 위해 부모의 next들을 이용한다.

최악의 경우 부모의 모든 next를 순회하며 이는 outer 시간 복잡도의 순회와 동일하다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

BFS를 이용할 경우 queue에 O(N)의 공간 복잡도가 필요하다.

자식의 next들을 이어주는데 부모들의 next를 이용하는 경우 별도의 공간 복잡도가 필요하지 않다. 따라서 O(1)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

모든 노드를 레벨별로 순회하며 이어준다.

next는 연결리스트 구조가 되며 NULL에 가까운 순서부터 이어줘야 하므로 right, left순으로 방문한다.

```cpp
Node* connect(Node* root) {
  queue<Node*> q;
  if (root) q.push(root);

  while (!q.empty()) {
    int size = q.size();
    Node* before = NULL;

    while (size--) {
      Node* cur = q.front();
      q.pop();

      cur->next = before;
      before = cur;

      if (cur->right) q.push(cur->right);
      if (cur->left) q.push(cur->left);
    }
  }

  return root;
}
```

### recursive & find next

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

현재 노드의 자식들을 next로 이어주기 위해 자신의 next를 이용하는 방법이다.

만약 자식에게 더이상 이어줄 next를 현재 노드에서 찾지 못한경우 findNext함수를 이용해 다음 노드의 next를 찾아온다.

이어주는 순서를 맞추기 위해 right부터 방문한다.

```cpp
Node* connect(Node* root) {
  if (!root) return NULL;

  if (root->left) {
    root->left->next = root->right ? root->right : findNext(root->next);
  }

  if (root->right) {
    root->right->next = findNext(root->next);
  }

  connect(root->right);
  connect(root->left);

  return root;
}

Node* findNext(Node* node) {
  if (!node) return NULL;

  if (node->left) return node->left;
  if (node->right) return node->right;

  return findNext(node->next);
}
```

### left iteration

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

각 level별로 가장 왼쪽에 있는 노드들 부터 방문하며 이어나간다.

현재 노드에서 자식 노드들의 next를 이어줄 때, 현재 노드의 next들을 이용한다.

left ~ right 순으로 이어줄 때 dummy 노드를 이용하기 때문에 방문 순서는 left ~ right순으로 방문한다.

또한 dummy노드의 next가 다음번에 방문할 가장 왼쪽의 노드이므로 이를 이용한다.

```cpp
Node* connect(Node* root) {
  Node* cur = root;

  while (cur) {
    Node *dummy = new Node(0), *child = dummy;

    while (cur) {
      if (cur->left) {
        child = child->next = cur->left;
      }
      if (cur->right) {
        child = child->next = cur->right;
      }

      cur = cur->next;
    }
    cur = dummy->next;
  }

  return root;
}
```

## 고생한 점
