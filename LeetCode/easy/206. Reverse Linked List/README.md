# 206. Reverse Linked List

[링크](https://leetcode.com/problems/reverse-linked-list/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

한번 순회를 통해 순서를 확인하고 이를 배열에 저장한 뒤 역순으로 순회해 뒤집을 수 있다.

혹은 한번의 순회를 통해서 뒤집을 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

배열에 순서를 저장하는 경우 O(N)의 공간 복잡도가 필요하다.

한번의 순회를 이용하는 경우 상수 만큼의 복잡도가 필요하다. 이는 O(1)이다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

head부터 순회하며 dummy->next로 이동시켜 붙이는 작업을 수행할 경우 한번의 순회로 가능하다.

```cpp
ListNode* reverseList(ListNode* head) {
  ListNode* dummy = new ListNode();
  dummy->next = head;
  ListNode *befoe = dummy, *target = head;

  while (target) {
    ListNode* temp = target->next;
    target->next = dummy->next;
    dummy->next = target;
    head->next = temp;
    target = temp;
  }

  return dummy->next;
}
```

## 고생한 점
