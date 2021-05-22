# 82. Remove Duplicates from Sorted List II

[링크](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

중복된 값들을 찾아내기 위해선 우선 한번 순회를 해야한다. 이후 필요한 부분만 연결하면 되므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 공간을 이용해 연결할 경우 O(N)의 공간 복잡도가 필요하다.

이전 점과 현재 방문한 점, 두 포인터를 이용할 경우 공간 복잡도는 O(1)이다.

### 직전 노드와 현재 노드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

현재 방문하는 노드와, 직전에 방문한 노드 두가지를 이용한다.

만약 현재 방문한 노드가 중복된 숫자가 아닌 경우 현재 노드, 직전 노드 둘다 한칸씩 이동한다.

만약 현재 방문한 노드가 중복된 숫자들인 경우 현재의 next 노드가 중복된 숫자가 아닐 때까지 현재 노드를 이동한다.

이후 직전 노드의 next를 현재 노드로 갱신하고, 현재 노드를 다음 노드로 이동한다.

```cpp
ListNode* deleteDuplicates(ListNode* head) {
  ListNode* dummy = new ListNode;
  ListNode* before;
  ListNode* cur = head;

  dummy->next = head;
  before = dummy;
  while (cur) {
    if (cur->next && cur->val == cur->next->val) {
      while (cur->next && cur->val == cur->next->val) {
        cur = cur->next;
      }

      before->next = cur->next;
    } else {
      before = before->next;
    }

    cur = cur->next;
  }

  return dummy->next;
}
```

## 고생한 점
