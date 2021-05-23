# 86. Partition List

[링크](https://leetcode.com/problems/partition-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

한번 순회하며 x보다 값이 작은 노드들을 앞으로 이동시켜야 한다.

x보다 값이 작은 노드들을 찾는데 한번의 순회, 새로운 리스트 노드를 생성하는데 한번의 순회가 필요하므로

시간 복잡도는 O(N)이다.

### 공간 복잡도

리스트 노드를 모두 저장할 필요는 없고 새로운 리스트 노드를 만들면 된다.

따라서 필요한 공간 복잡도는 O(1)이다.

### 새로운 배열 생성

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

정답으로 반환할 연결 리스트를 새로 생성한다.

연결 리스트를 한번 순회하며 x보다 작은 값을을 발견할 때마다 정답에 붙이고, 현재 연결리스트에서 제거한다.

이후 정답 연결 리스트에 이전에 순회한 연결 리스트를 이어 붙인다.

```cpp
ListNode* partition(ListNode* head, int x) {
  ListNode* dummy = new ListNode();
  ListNode* answer = new ListNode();

  dummy->next = head;
  ListNode* cur = dummy;
  ListNode* answerCur = answer;

  while (cur && cur->next) {
    if (cur->next->val < x) {
      answerCur->next = cur->next;
      answerCur = answerCur->next;
      cur->next = cur->next->next;
    } else {
      cur = cur->next;
    }
  }

  answerCur->next = dummy->next;

  return answer->next;
}
```

## 고생한 점
