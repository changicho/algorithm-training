# 1836. Remove Duplicates From an Unsorted Linked List

[링크](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 리스트의 길이를 N이라 하자.

각 노드들의 값의 갯수를 센 뒤, 제거해야 하는 노드를 삭제할 수 있다.

이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

노드를 직접 삭제할 경우 별도의 공간 복잡도를 사용하지 않는다.

각 노드의 값을 카운트할 때 O(N)의 공간 복잡도가 필요하다.

### two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     369      |    O(N)     |    O(N)     |

각 노드의 값을 hash map에 저장한다.

이후 다시 순회하며 중복된 (count가 2 이상인) 노드를 삭제한다.

```cpp
ListNode* deleteDuplicatesUnsorted(ListNode* head) {
  unordered_map<int, int> counts;

  ListNode* dummy = new ListNode();
  dummy->next = head;
  ListNode *before = dummy, *cur = dummy->next;

  while (cur) {
    counts[cur->val]++;
    cur = cur->next;
  }

  cur = dummy->next;

  while (cur) {
    if (counts[cur->val] >= 2) {
      before->next = cur->next;
      cur = cur->next;
      continue;
    }

    cur = cur->next;
    before = before->next;
  }

  return dummy->next;
}
```

## 고생한 점
