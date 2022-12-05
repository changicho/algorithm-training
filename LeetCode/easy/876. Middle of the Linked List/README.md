# 876. Middle of the Linked List

[링크](https://leetcode.com/problems/middle-of-the-linked-list/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

링크드 리스트의 길이를 N이라 하자.

모든 리스트를 순회할 경우 O(N)의 시간 복잡도를 사용한다.

길이를 먼저 재고 절반만큼 이동 후 반환할 경우 O(N)의 시간 복잡도를 사용한다.

투 포인터를 이용해 한번에 순회하며 절반을 찾을 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 배열을 사용하지 않는 경우 O(1)의 공간 복잡도를 사용한다.

### 토끼와 거북이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
ListNode* middleNode(ListNode* head) {
  ListNode *fast = head, *slow = head;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow;
}
```

## 고생한 점
