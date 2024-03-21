# 1669. Merge In Between Linked Lists

[링크](https://leetcode.com/problems/merge-in-between-linked-lists/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 연결리스트의 길이를 각각 N, M이라 하자.

두 연결리스트를 순회하며 연결할 점들을 찾는데 O(N + M)의 시간 복잡도를 사용한다.

이후 해당 노드들을 연결하는데 O(1)의 시간 복잡도가 필요하다.

### 공간 복잡도

새로운 노드를 생성하지 않고 기존의 노드들을 연결하므로 별도의 공간 복잡도가 필요하지 않다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     183      |  O(N + M)   |    O(1)     |

list1을 순회하며 연결할 지점을 찾는다.

이후 list2를 순회하여 끝 노드를 찾고 연결한다.

```cpp
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
  ListNode* dummy = new ListNode();
  dummy->next = list1;

  ListNode* cur = dummy;
  ListNode *left = NULL, *right = NULL;
  int i = 0;
  while (cur) {
    if (i == a) {
      left = cur;
    } else if (i == b + 1) {
      right = cur;
    }

    cur = cur->next;
    i++;
  }

  left->next = list2;
  cur = list2;
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = right->next;

  return dummy->next;
}
```

## 고생한 점
