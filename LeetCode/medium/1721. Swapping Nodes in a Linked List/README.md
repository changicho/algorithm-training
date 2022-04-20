# 1721. Swapping Nodes in a Linked List

[링크](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 리스트의 노드의 갯수를 N이라 하자.

K번째, N-K번째 원소를 찾기 위해 한번 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

이후 두 값을 변경하는데 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

투 포인터를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     740      |    O(N)     |    O(1)     |

먼저 연결리스트의 길이를 확인한 뒤, K번째, N-K번째 값을 찾는다.

이후 둘의 값을 교환한다.

```cpp
int getLength(ListNode* head) {
  int length = 0;
  while (head) {
    length++;
    head = head->next;
  }
  return length;
}

ListNode* swapNodes(ListNode* head, int k) {
  int length = getLength(head);

  ListNode *from = head, *to = head;

  for (int i = 0; i < k - 1; i++) {
    from = from->next;
  }
  for (int i = 0; i < length - 1 - (k - 1); i++) {
    to = to->next;
  }

  swap(from->val, to->val);
  return head;
}
```

## 고생한 점
