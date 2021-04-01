# 83. Remove Duplicates from Sorted List

[링크](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

head ListNode를 전부 순회해야 하므로 head의 길이 N만큼의 시간 복잡도가 필요하다. O(N)

### 공간 복잡도

반환하는 연결리스트 만큼의 공간 복잡도가 필요하다.

### 중복 제거

정렬된 배열이 주어지며, 그중에 unique한 값만 뽑아낸다.

따라서 이전값과 같은 경우는 무시한다.

```cpp
ListNode* deleteDuplicates(ListNode* head) {
  ListNode* answer = new ListNode;
  ListNode* cur = answer;

  int before = -101;
  while (head != NULL) {
    if (head->val != before) {
      before = head->val;

      cur->next = new ListNode(head->val);
      cur = cur->next;
    }
    head = head->next;
  }

  answer = answer->next;
  return answer;
}
```

head를 이용해 갈아 끼는 경우 다음과 같이 구현할 수 있다.

```cpp
ListNode* deleteDuplicates(ListNode* head) {
  ListNode* cur = head;
  while (cur != NULL && cur->next != NULL) {
    if (cur->next->val == cur->val) {
      cur->next = cur->next->next;
    } else {
      cur = cur->next;
    }
  }

  return head;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      8       |

## 고생한 점
