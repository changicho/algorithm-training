# 19. Remove Nth Node From End of List

[링크](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 크기는 최대 30이다. N번째 노드를 찾기 위해선 한번 순회해야 하므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

노드 순서를 기억하기 위해 배열을 사용할 경우 공간 복잡도는 O(N)이다.

그러나 이를 사용하지 않고 포인터만 이용해 공간 복잡도를 O(1)로 만들 수 있다.

### 투 패스

> 0ms

두번 노드를 탐색한다.

1. 노드의 끝까지 탐색하며 노드의 개수를 파악한다.
2. 노드의 끝에서 n번째의 노드를 삭제한다.

이 때 노드의 개수가 1개이며 1개를 삭제하는 경우, 맨 마지막 노드를 삭제하는 경우를 막기 위해 다음을 이용한다.

n번째 노드를 삭제하는 것은 n-1번째 노드의 next를 n+1번째 노드로 설정하는 것이다.

따라서 n-1번째 노드까지만 찾으면 된다.

맨 마지막 노드를 삭제하는 경우는 어차피 n+1번째가 NULL이므로 범위를 벗어나지 않는다.

맨 처음 노드를 삭제하는 경우는 n-1번째 노드가 없으므로, 맨 처음 노드를 시작할 때 dummy노드에서 시작하도록 한다.

```cpp
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode();
    start->next = head;

    int size = 0;
    ListNode* target = head;
    while (target != NULL) {
      size++;
      target = target->next;
    }

    size -= n;
    target = start;
    for (int i = 0; i < size; i++) {
      target = target->next;
    }
    target->next = target->next->next;

    return start->next;
  }
```

### 원 패스

> 4ms

n번만큼 차이가 나도록 두 노드를 탐색한다고 하자.

앞에 있는 노드를 front, 뒤에 있는 노드를 back이라고 하자.

front에서 n번 next로 넘어갈 경우 back이 된다.

이 때 back이 맨 마지막 노드 (NULL)인 경우에 front에 있는 노드를 삭제하면 된다.

투 패스와 마찬가지 방법으로 start dummy를 두고 연결해 사용한다.

이 때 dummy에서 시작하므로 n + 1번 만큼 탐색해야 한다.

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* start = new ListNode();
  start->next = head;

  ListNode* first = start;
  ListNode* second = start;

  for (int i = 0; i < n + 1; i++) {
    first = first->next;
  }

  while (first) {
    first = first->next;
    second = second->next;
  }
  second->next = second->next->next;

  return start->next;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
