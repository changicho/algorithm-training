# 1290. Convert Binary Number in a Linked List to Integer

[링크](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

연결리스트의 길이를 N이라 하자.

순회를 이용할 경우 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

순회와 동시에 현재까지의 값을 계산한다.

```cpp
int getDecimalValue(ListNode* head) {
  int answer = 0;

  ListNode* cur = head;
  while (cur) {
    answer *= 2;
    answer += cur->val;
    cur = cur->next;
  }
  return answer;
}
```

## 고생한 점
