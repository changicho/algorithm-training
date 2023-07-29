# 445. Add Two Numbers II

[링크](https://leetcode.com/problems/add-two-numbers-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 연결리스트의 길이를 N, M이라 하자.

두 연결리스트를 뒤집은 뒤 더한 후 다시 뒤집어 합을 계산할 수 있다.

이 경우 O(N + M)의 시간 복잡도를 사용한다.

혹은 stack을 사용해 역순으로 계산한 뒤 다시 뒤집어 합 연결리스트를 생성 가능하다.

이 또한 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

반환할 연결리스트에 O(N + M)의 공간 복잡도를 사용한다.

### 연결리스트 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     43ms     |  O(N + M)   |  O(N + M)   |

두 연결 리스트를 뒤집은 뒤 1의 자리수 부터 덧셈을 계산한다.

이후 나온 합 연결리스트를 뒤집은 뒤 반환한다.

```cpp
ListNode* reverse(ListNode* node) {
  ListNode* prev = NULL;

  while (node) {
    ListNode* next = node->next;
    node->next = prev;
    prev = node;
    node = next;
  }

  // return tail. tail is prev
  return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  l1 = reverse(l1), l2 = reverse(l2);

  ListNode* dummy = new ListNode();
  ListNode* cur = dummy;

  int carry = 0;
  while (l1 || l2 || carry > 0) {
    int val = 0;
    if (l1) {
      val += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      val += l2->val;
      l2 = l2->next;
    }
    val += carry;

    if (val >= 10) {
      carry = 1;
      val %= 10;
    } else {
      carry = 0;
    }
    ListNode* node = new ListNode(val);

    cur->next = node;
    cur = cur->next;
  }

  return reverse(dummy->next);
}
```

## 고생한 점
