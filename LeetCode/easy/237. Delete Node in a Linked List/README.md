# 237. Delete Node in a Linked List

[링크](https://leetcode.com/problems/delete-node-in-a-linked-list/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

연결 리스트의 노드의 수를 N이라 하자.

삭제해야할 노드만 주어진다. 이 노드를 삭제하고 이후 부분을 shift연산을 수행할 수 있다.

만약 현재 노드 이후 값들을 전부 shift하는 경우 이후 노드를 모두 한번 순회하므로 시간 복잡도는 O(N)이다.

혹은 모두 shift하는것이 아닌 필요한 부분만 덧붙이는 경우는 한번의 연산으로 모두 수행할 수 있다.

### 공간 복잡도

연산에 별도의 공간이 필요하지 않다.

### 갈아끼우기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(1)     |    O(1)     |

현재 노드(위치)를 다음 노드로 갈아끼운다.

```cpp
void deleteNode(ListNode* node) {
  node->val = node->next->val;
  node->next = node->next->next;
}
```

### 시프트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

현재 노드의 값을 다음 노드로 갈아끼운다.

이를 이후 모든 노드에 반복하고, 맨 마지막 부분을 NULL로 만든다.

```cpp
void deleteNode(ListNode* node) {
  while (node->next->next) {
    node->val = node->next->val;
    node = node->next;
  }
  node->val = node->next->val;
  node->next = NULL;
}
```

## 고생한 점
