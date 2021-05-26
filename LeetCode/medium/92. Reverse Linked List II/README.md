# 92. Reverse Linked List II

[링크](https://leetcode.com/problems/reverse-linked-list-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

특정 구간의 순서를 뒤집으면 된다. 구간을 순회하며 뒤집어야 하므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

연결 리스트의 순서를 모두 저장해 뒤집을 경우 공간 복잡도는 O(N)이 필요하다.

포인터만을 이용해 뒤집는 연산을 수행할 경우 공간 복잡도는 O(1)가 필요하다.

### Array

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

연결 리스트를 vector에 담고, 뒤집는 부분만 뒤집은 뒤 연결 관계를 갱신해준다.

```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
  vector<ListNode*> array;

  ListNode* dummy = new ListNode(-1, head);
  ListNode* cur = head;

  array.push_back(dummy);
  while (cur) {
    array.push_back(cur);
    cur = cur->next;
  }
  array.push_back(NULL);

  // reverse(array.begin() + left, array.begin() + right + 1);
  int diff = (right - left) + 1;
  for (int i = 0; i < diff / 2; i++) {
    swap(array[left + i], array[right - i]);
  }

  for (int i = left - 1; i <= right; i++) {
    array[i]->next = array[i + 1];
  }

  return array[1];
}
```

### Iterative Link Reversal

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

현재 index를 cur 이라고 하자.

pre-cur-next 순서대로 연결되어 있는 리스트 노드가 존재한다고 하자.

현재 index에서 이후에 나오는 모든 index들인 index+1, index+2 ... 등등을 순회하며 pre와 cur 사이에 삽입한다.

즉 next들을 역순으로 pre와 cur사이에 붙인다.

```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
  ListNode* dummy = new ListNode(0, head);
  ListNode *pre = dummy, *cur, *next;

  for (int i = 0; i < left - 1; i++) {
    pre = pre->next;
  }
  cur = pre->next;
  next = cur->next;

  for (int i = 0; i < right - left; i++) {
    cur->next = next->next;
    next->next = pre->next;
    pre->next = next;
    next = cur->next;
  }
  return dummy->next;
}
```

## 고생한 점
