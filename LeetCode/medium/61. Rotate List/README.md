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

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

K번 오른쪽으로 회전시켜야 하며, 따라서 새로운 마지막 노드는 N-K번째 원소가 된다.

연결 리스트의 길이와 원본 마지막 노드, 타겟 노드를 구한 뒤 새로 이어준다.

```cpp
ListNode* rotateRight(ListNode* head, int k) {
  int size = 0;
  ListNode* first = head;
  ListNode* last = NULL;

  ListNode* cur = head;
  while (cur) {
    size++;
    last = cur;
    cur = cur->next;
  }

  if (k == 0 || size == 0 || k % size == 0) return head;

  int target = size - (k % size);

  cur = head;
  while ((target - 1) > 0) {
    target--;
    cur = cur->next;
  }
  ListNode* newFirst = cur->next;
  cur->next = NULL;
  last->next = first;

  return newFirst;
}
```
