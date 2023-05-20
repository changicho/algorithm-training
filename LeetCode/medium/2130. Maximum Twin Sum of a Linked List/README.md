# 2130. Maximum Twin Sum of a Linked List

[링크](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 리스트의 노드의 갯수를 N이라 하자.

해당 노드를 순회하며 값들을 별도 배열에 저장 후 순회를 이용해 정답을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

배열을 절반 뒤집은 후 순차적으로 이동하며 정답을 구할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 배열을 생성할 경우 O(N)의 공간 복잡도를 사용한다.

배열의 절반을 뒤집고 순차적으로 이동하며 정답을 구할 경우 O(1)의 공간 복잡도를 사용한다.

### 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     280      |    O(N)     |    O(1)     |

연결 리스트의 절반을 뒤집는다.

이 경우 i번째, i + (N/2)번째 노드의 합을 구하며 정답을 갱신한다.

```cpp
int getLength(ListNode* head) {
  int length = 0;
  ListNode* cur = head;
  while (cur) {
    length++;
    cur = cur->next;
  }
  return length;
}

ListNode* reverse(ListNode* head, int size) {
  size--;

  ListNode* dummy = new ListNode();
  dummy->next = head;

  ListNode* cur = head;
  while (size--) {
    // dummy ... cur next nnext;
    // dummy next ... cur nnext;
    ListNode* next = cur->next;

    cur->next = next->next;
    next->next = dummy->next;
    dummy->next = next;
  }

  return dummy->next;
}

int pairSum(ListNode* head) {
  int length = getLength(head);
  int answer = 0;

  ListNode* start = reverse(head, length / 2);

  ListNode *first = start, *second = start;

  for (int i = 0; i < length / 2; i++) {
    second = second->next;
  }

  for (int i = 0; i < length / 2; i++) {
    int curSum = first->val + second->val;
    answer = max(answer, curSum);

    first = first->next;
    second = second->next;
  }

  return answer;
}
```

## 고생한 점
