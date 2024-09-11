# 2807. Insert Greatest Common Divisors in Linked List

[링크](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 연결리스트의 길이를 N이라 하자.

순회하며 이어진 값들의 gcd값을 구해야 한다. 최대값은 1000 이므로 gcd를 구하는데 O(1)의 시간 복잡도가 필요하다.

이를 순회하며 반복 하는데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답 연결 리스트에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |    O(N)     |    O(N)     |

이전값과 현재값을 순회하며 사이에 gcd값을 삽입한다.

이 때 다음 노드로 이동할 때 삽입한 노드를 건너뜀에 유의한다.

```cpp
ListNode* insertGreatestCommonDivisors(ListNode* head) {
  ListNode* dummy = new ListNode(0, head);
  ListNode* before = head;

  ListNode* cur = head->next;

  while (cur) {
    int val = gcd(cur->val, before->val);
    before->next = new ListNode(val, cur);

    before = cur;
    cur = cur->next;
  }
  return dummy->next;
}
```

## 고생한 점
