# 24. Swap Nodes in Pairs

[링크](https://leetcode.com/problems/swap-nodes-in-pairs/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 리스트의 노드의 개수는 최대 100이다.

모든 노드를 순회하며 바꿔야 하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

뒤집을 크기 만큼의 공간이 필요하다. (그부분만큼 뒤집어야 하므로)

따라서 공간 복잡도는 O(N) 이다.

### 뒤집기

특정 부분을 뒤집기 위해 필요한 포인터는 다음 2가지이다.

- 특정 범위 직전의 노드
- 특정 범위에 속한 모든 노드

이 때 맨 처음 노드부터 바꿔야 하므로 이를 일반화 하기 위해 맨 앞에는 dummy 노드를 붙이고 그곳부터 시작한다.

현재 노드를 cur로 두고 cur을 next로 이동시켜가며 노드를 방문한다.

- 순서를 바꾸기 전 현재 노드의 직전 노드를 before로 저장한다. (현재 노드가 바꾸는 구간의 시작점이기 때문)
- 바꾸는 갯수만큼 노드를 순회하며 vector에 집어넣는다.
- 이 때 노드가 NULL인 경우 순회를 중지하며, 바꿔야 하는 갯수 만큼 방문하지 못한 경우 로직을 중지한다.
- 벡터의 맨 첫번째 노드의 next를 맨 마지막 노드의 next로 설정한다.
- i->next = i-1로 연결 순서를 변경해준다.

노드 연결 뒤집기가 완료되면 dummy->next를 반환한다.

```cpp
ListNode* swapPairs(ListNode* head) {
  ListNode* cur = head;
  ListNode* dummy = new ListNode();
  ListNode* before = dummy;
  dummy->next = head;

  int size = 2;
  while (cur) {
    vector<ListNode*> v;
    for (int i = 0; i < size; i++) {
      v.push_back(cur);
      cur = cur->next;

      if (!cur) break;
    }

    if (v.size() != size) break;

    v.front()->next = v.back()->next;
    before->next = v.back();

    for (int i = size - 1; i >= 1; i--) {
      v[i]->next = v[i - 1];
    }

    before = v.front();
  }

  return dummy->next;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
