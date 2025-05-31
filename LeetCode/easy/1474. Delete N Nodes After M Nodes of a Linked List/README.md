# 1474. Delete N Nodes After M Nodes of a Linked List

[링크](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

연결 리스트의 길이를 N이라 하자.

연결리스트를 순회하며 삭제하는 부분만 삭제한다.

이에 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

직접 수정할 경우 O(1)의 공간 복잡도를 갖는다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
ListNode* deleteNodes(ListNode* head, int m, int n) {
  ListNode* dummy = new ListNode();
  dummy->next = head;
  ListNode* cur = head;

  while (cur) {
    for (int i = 0; i < m - 1 && cur; i++) {
      cur = cur->next;
    }
    if (!cur) break;

    ListNode* before = cur;
    cur = cur->next;
    for (int i = 0; i < n && cur; i++) {
      cur = cur->next;
    }
    before->next = cur;
    if (!cur) break;
  }
  return dummy->next;
}
```

## 고생한 점
