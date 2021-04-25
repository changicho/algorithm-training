# 160. Intersection of Two Linked Lists

[링크](https://leetcode.com/problems/intersection-of-two-linked-lists/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

리스트 노드의 최대 길이는 3 \* 10^4 이다.

두 연결 리스트를 순회하며 문제를 해결할 수 있다.

브루트 포스 방법의 경우 시간 복잡도는 O(N^2) 이므로 제한시간 내에 불가능하다.

연결리스트를 순회하며 연결 노드를 찾는 경우 시간 복잡도는 O(N) 이다.

### 공간 복잡도

방문 노드를 기억하기 위해 hash를 사용하는 경우 공간 복잡도는 O(N) 이다.

이 외에 일반 순회를 하는 경우 공간 복잡도는 O(1) 이다.

### 해쉬

> 36ms (일반 set : 60ms)

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(N)

unordered_set을 이용해 A의 방문 노드들을 모두 기억하고 B를 순회하며 이전에 방문했는지 여부를 판단한다.

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  unordered_set<ListNode *> s;

  ListNode *cur = headA;

  while (cur != NULL) {
    s.insert(cur);
    cur = cur->next;
  }

  cur = headB;

  while (cur != NULL) {
    if (s.find(cur) != s.end()) {
      return cur;
    }
    cur = cur->next;
  }

  return NULL;
}
```

### count 후 시작점 맞추기

> 32ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(1)

A와 B의 길이가 다른 경우 긴쪽을 짧은 쪽에 맞춘다.

이후 서로 한칸씩 이동하며 연결점에서 만나는지를 비교한다.

두 연결리스트의 길이를 찾는데 각각 O(N)이 소요되며 이후 탐색하는데 O(N)이 소요된다.

```cpp
int countListNode(ListNode *head) {
  int count = 0;
  while (head) {
    count++;
    head = head->next;
  }
  return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int countA = 0, countB = 0;

  countA = countListNode(headA);
  countB = countListNode(headB);

  if (countA < countB) {
    swap(countA, countB);
    swap(headA, headB);
  }

  int diff = abs(countA - countB);

  for (int i = 0; i < diff; i++) {
    headA = headA->next;
  }

  while (headA != headB) {
    headA = headA->next;
    headB = headB->next;
  }
  return headA;
}
```

### 투 포인터

> 44ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(1)

count하는 방법과 유사하다.

A와 B를 동시에 한칸씩 이동시키며 탐색한다.

이때 A가 끝점에 도달한 경우는 B의 시작점으로 이동하고, B가 끝점에 도달한 경우 A의 시작점으로 이동한다.

결국 A+B의 길이만큼 순회를 하기 때문에 최종적으로는 둘다 끝점인 NULL에서 만나게 된다.

두 연결 리스트의 연결점이 없는 경우에는 NULL에서 만난다.

그렇지 않은 경우는 count를 하는 방법과 유사하게 길이가 긴 노드를 짧은쪽에 맞춰서 연결점을 탐색한다.

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *pointerA = headA, *pointerB = headB;
  while (pointerA != pointerB) {
    if (pointerA != NULL) {
      pointerA = pointerA->next;
    } else {
      pointerA = headB;
    }

    if (pointerB != NULL) {
      pointerB = pointerB->next;
    } else {
      pointerB = headA;
    }
  }
  return pointerA;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      36      |

## 고생한 점
