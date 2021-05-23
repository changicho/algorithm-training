# 203. Remove Linked List Elements

[링크](https://leetcode.com/problems/remove-linked-list-elements/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

한번 순회를 통해서 중복된 요소를 제거한다.

따라서 한번 순회 하는데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

이전 노드와 현재 노드를 저장할 경우 상수 만큼의 시간 복잡도가 필요하다.

따라서 필요한 공간 복잡도는 O(1)이다.

### 두 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(1)     |

현재 노드와 직전 노드를 기록하며 target의 연결 관계를 끊는다.

```cpp
ListNode* removeElements(ListNode* head, int val) {
  ListNode* before;
  ListNode* cur;
  ListNode* dummy = new ListNode();

  dummy->next = head;
  cur = head;
  before = dummy;

  while (cur) {
    if (cur->val == val) {
      before->next = cur->next;

    } else {
      before = before->next;
    }

    cur = cur->next;
  }

  return dummy->next;
}
```

## 싱글 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(1)     |

현재 노드의 next만을 이용해서 하나의 포인터로만 해결이 가능하다.

```cpp
ListNode* removeElements(ListNode* head, int val) {
  ListNode* dummy = new ListNode();
  ListNode* cur = dummy;
  dummy->next = head;

  while (cur && cur->next) {
    if (cur->next->val == val) {
      cur->next = cur->next->next;
    } else {
      cur = cur->next;
    }
  }
  return dummy->next;
}
```

## 고생한 점
