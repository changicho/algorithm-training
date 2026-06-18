# 2095. Delete the Middle Node of a Linked List

[링크](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결리스트의 길이를 N이라 하자.

길이를 잰 뒤 중앙부분을 삭제하는데 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

포인터를 이동하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(1)     |

전체 길이를 잰 뒤 (N / 2) - 1 만큼 이동 후 다음 원소를 제거한다.

```cpp
int getLength(ListNode* head) {
  ListNode* cur = head;

  int ret = 0;
  while (cur) {
    ret++;
    cur = cur->next;
  }
  return ret;
}

ListNode* deleteMiddle(ListNode* head) {
  int size = getLength(head);
  if (size == 1) return NULL;
  ListNode* cur = head;
  for (int i = 0; i < size / 2 - 1; i++) {
    cur = cur->next;
  }

  cur->next = cur->next->next;

  return head;
}
```

## 고생한 점
