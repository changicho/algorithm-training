# 61. Rotate List

[링크](https://leetcode.com/problems/rotate-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

길이 N의 링크드 리스트를 K번 회전시켜야 하며, K는 N을 초과할 수도 있다.

N번 회전할 경우 0번 회전한 것과 동일한 상태이므로 K % N번만큼만 회전하면 된다.

한번 순회를 통해 해결할 수 있으므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

배열을 이용해 이전의 순서를 기억할 경우 O(N)의 공간 복잡도가 필요하다.

자를 지점을 탐색할 경우 상수만큼의 공간 복잡도가 필요하므로 O(1)의 공간 복잡도가 필요하다.

### 점 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

K는 N을 초과할 수 있으며 N이 0일수 있음에 유의한다.

끝에서 K번째 노드와 K-1번째 노드, 맨 마지막 노드를 찾는다.

이후 맨 마지막 노드 뒤에 head를 붙이고 K-1번째 노드의 next를 NULL로 설정한다.

K번째 노드를 반환하면 K번 회전한 링크드 리스트를 만들 수 있다.

```cpp
ListNode *rotateRight(ListNode *head, int k) {
  ListNode *dummy = new ListNode();
  ListNode *cur = dummy;
  dummy->next = head;

  int length = getLength(head);
  if (length < 2) {
    return head;
  }

  k %= length;
  if (k == 0) {
    return head;
  }

  for (int i = 0; i < length - k; i++) {
    cur = cur->next;
  }

  ListNode *after = cur->next;
  ListNode *before = cur;

  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = head;
  before->next = NULL;
  dummy->next = after;

  return dummy->next;
}

int getLength(ListNode *head) {
  int length = 0;
  while (head != NULL) {
    length += 1;
    head = head->next;
  }
  return length;
}
```

## 고생한 점
