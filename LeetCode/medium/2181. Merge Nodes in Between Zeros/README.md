# 2181. Merge Nodes in Between Zeros

[링크](https://leetcode.com/problems/merge-nodes-in-between-zeros/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결리스트의 길이를 N이라 하자.

연결리스트를 순회하며 새로운 노드를 만들어 정답에 이어붙일 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

새로 정답 노드를 만들 경우 O(N)의 공간 복잡도가 필요하다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     472      |    O(N)     |    O(N)     |

연결 리스트를 순회하며 0 사이에 있는 노드들의 합인 새 노드를 만들어 붙인다.

```cpp
ListNode* mergeNodes(ListNode* head) {
  ListNode* dummy = new ListNode();
  ListNode* dummyCur = dummy;
  ListNode* cur = head;
  int sum = 0;

  while (cur) {
    if (cur->val != 0) {
      sum += cur->val;
    } else if (sum > 0) {
      dummyCur->next = new ListNode(sum);
      sum = 0;
      dummyCur = dummyCur->next;
    }

    cur = cur->next;
  }

  return dummy->next;
}
```

## 고생한 점
