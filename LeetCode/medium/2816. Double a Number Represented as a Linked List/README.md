# 2816. Double a Number Represented as a Linked List

[링크](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결리스트의 노드의 길이를 N이라 하자.

배열을 이용해 직접 계산 후 새로운 연결리스트를 만드는 경우 시간 복잡도는 O(N)이다.

뒤집기를 이용해 계산 할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

배열을 이용해 직접 계산 후 새로운 연결리스트를 만드는 경우 공간 복잡도는 O(N)이다.

뒤집기를 이용해 계산 할 경우 공간 복잡도는 O(1)이다.

### 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     160      |    O(N)     |    O(1)     |

연결 리스트를 뒤집은 뒤 두 배로 곱한다.

이 때 carry를 사용하며 맨 마지막에 carry가 남을 수 있음에 유의한다.

```cpp
ListNode* reverse(ListNode* node) {
  ListNode* prev = NULL;
  ListNode* cur = node;

  while (cur) {
    ListNode* next = cur->next;
    cur->next = prev;

    prev = cur;
    cur = next;
  }

  return prev;
}

ListNode* doubleIt(ListNode* head) {
  head = reverse(head);
  ListNode* dummy = new ListNode();

  dummy->next = head;
  ListNode* cur = dummy->next;
  ListNode* before = dummy;
  int carry = 0;

  while (cur) {
    int val = cur->val * 2 + carry;
    carry = 0;

    if (val >= 10) {
      carry = 1;
      val %= 10;
    }

    cur->val = val;
    before = cur;
    cur = cur->next;
  }

  if (carry > 0) {
    before->next = new ListNode(1);
  }

  return reverse(head);
}
```

## 고생한 점
