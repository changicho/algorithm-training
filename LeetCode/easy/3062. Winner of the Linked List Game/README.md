# 3062. Winner of the Linked List Game

[링크](https://leetcode.com/problems/winner-of-the-linked-list-game/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

연결 리스트의 길이를 N이라 하자.

각 노드를 순회하며 pair마다 값을 비교하고 point를 더해야 한다.

이 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

홀수, 짝수부의 점수를 저장하는 데 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

연결리스트를 앞에서부터 순회하며 짝수, 홀수부 마다 pair를 비교하고 점수를 계산한다.

```cpp
string gameResult(ListNode *head) {
int even = 0, odd = 0;

ListNode *cur = head;
while (cur) {
  ListNode *first = cur;
  cur = cur->next;
  ListNode *second = cur;
  cur = cur->next;

  if (first->val > second->val) {
    even++;
  } else if (first->val < second->val) {
    odd++;
  }
}

if (even < odd)
  return "Odd";
else if (even > odd)
  return "Even";
else
  return "Tie";
}
```

## 고생한 점
