# 2487. Remove Nodes From Linked List

[링크](https://leetcode.com/problems/remove-nodes-from-linked-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 리스트의 노드의 갯수를 N이라 하자.

모노토닉 스택을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

연결리스트를 뒤집은 후 순회할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모노토닉 스택에 O(N)의 공간 복잡도를 사용한다.

연결리스트를 뒤집을 경우 O(1)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     269      |    O(N)     |    O(N)     |

연결 리스트를 순회하며 값들이 top으로 갈 수록 감소하는 순서로만 연결한다.

이 때 초기값을 INT_MAX로 설정해 스택이 비지 않고 순회할 수 있도록 구성할 수 있다.

```cpp
ListNode* removeNodes(ListNode* head) {
  ListNode* dummy = new ListNode(INT_MAX);
  dummy->next = head;
  ListNode* before = dummy;
  ListNode* cur = dummy->next;

  stack<ListNode*> stk;
  stk.push(dummy);

  while (cur) {
    while (stk.top()->val < cur->val) {
      stk.pop();
    }

    stk.top()->next = cur;
    stk.push(cur);
    cur = cur->next;
  }
  return dummy->next;
}
```

### 뒤집기 & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     253      |    O(N)     |    O(1)     |

배열을 뒤집은 뒤 순회하며 증가하는 순서로만 연결할 수 있다.

이를 다시 뒤집을 경우 최종적으로 감소하는 순서로만 연결된다.

```cpp
ListNode* reverse(ListNode* head) {
  ListNode* prev = NULL;
  ListNode* cur = head;

  while (cur) {
    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  return prev;
}

ListNode* removeNodes(ListNode* head) {
  head = reverse(head);

  int maximum = 0;
  ListNode* prev = NULL;
  ListNode* cur = head;

  while (cur) {
    maximum = max(maximum, cur->val);

    if (cur->val < maximum) {
      prev->next = cur->next;
      cur = cur->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }

  return reverse(head);
}
```

## 고생한 점
