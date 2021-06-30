# 116. Populating Next Right Pointers in Each Node

[링크](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

모든 노드에 대해서 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

현재 노드의 next를 구하기 위해서 직접 탐색하는 경우 모든 노드를 찾아봐야 할 수 있다.

현재 노드를 탐색하며 자식들을 next로 이어주고, 만약 현재 노드에 next가 있는경우 이를 이동해 자식들을 연결하는 식으로 구성할 경우 모든 노드를 찾지 않아도 된다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

BFS를 이용할 경우 O(N)만큼의 공간 복잡도가 필요하다.

재귀호출 혹은 while문으로 자식끼리 잇는 방법을 이용할 경우 별도의 공간 복잡도가 필요하지 않다. (문제에서 call stack의 공간복잡도는 고려하지 않음)

따라서 공간 복잡도는 O(1)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(N)     |

BFS를 이용해 높이별로 순회하며 이어준다.

이 때 left ~ right 순으로 이어줘야 하므로 방문 순서를 다음과 같이 한다.

- data
- right
- left

```cpp
Node* connect(Node* root) {
  queue<Node*> q;
  if (root) q.push(root);

  while (!q.empty()) {
    int size = q.size();
    Node* next = NULL;
    while (size--) {
      Node* cur = q.front();
      q.pop();

      cur->next = next;
      next = cur;
      if (cur->right) q.push(cur->right);
      if (cur->left) q.push(cur->left);
    }
  }

  return root;
}
```

### 자식끼리 잇기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

재귀호출로 현재 노드의 자식인 left노드와 right노드를 함께 넘겨준다.

이 두 노드를 이어주며, 다음 자식들도 같이 이어준다.

- left->left ~ left->right
- right->left ~ right->right
- left->right ~ right->left

```cpp
Node* connect(Node* root) {
  if (root) helper(root->left, root->right);

  return root;
}

void helper(Node* node1, Node* node2) {
  if (node1 == NULL) return;

  node1->next = node2;
  helper(node1->left, node1->right);
  helper(node2->left, node2->right);
  helper(node1->right, node2->left);
}
```

재귀호출이 아닌 반복문으로도 구현 가능하다.

시작점에서부터 순회하며 자식노드들 (left, right)를 이어준다.

이 때 자신의 next가 존재할 경우 next가 존재하지 않을 때 까지 똑같이 이어준다.

다음으로 자신의 left로 이동해 위와 같은 방법을 계속한다.

자식들의 next를 미리 이어놓기 때문에 다음 시작점에서 한번에 이어질 수 있다.

```cpp
Node* connect(Node* root) {
  if (!root) return NULL;

  Node *pre = root;
  while (pre->left) {
    Node* cur = pre;

    while (cur) {
      cur->left->next = cur->right;
      if (cur->next) {
        cur->right->next = cur->next->left;
      }
      cur = cur->next;
    }

    pre = pre->left;
  }

  return root;
}
```

## 고생한 점
