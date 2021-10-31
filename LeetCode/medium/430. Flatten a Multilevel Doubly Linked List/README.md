# 430. Flatten a Multilevel Doubly Linked List

[링크](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

모든 노드를 한번 순회해야 하므로 O(N)의 시간 복잡도가 소요된다.

이 때 순회하면서 재귀호출, 혹은 one pass로 한번에 flatten을 수행할 수 있으므로 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

재귀 호출로 풀이할 경우 최악의 경우 call stack에 O(N)의 공간 복잡도를 사용할 수 있다.

순회를 이용해 풀이할 경우 O(1)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

노드를 순회하며 현재 노드에 자식이 있는 경우 flatten을 수행한다.

이 때 자식의 노드중 또 자식이 있는 경우가 있을 수 있으므로 재귀호출로 이를 구현한다.

flatten한 자식노드를 현재 노드의 next로 붙이고, 자식 노드의 끝을 원래 next와 붙인다.

연결 시에 next가 NULL인 경우는 next의 prev를 갱신하지 않는다.

이를 모든 노드에 대해서 순회하며 반복한다.

```cpp
Node* flatten(Node* head) {
  if (!head) return NULL;
  Node* cur = head;

  while (cur) {
    if (cur->child) {
      Node* next = cur->next;
      Node* child = flatten(cur->child);

      cur->next = child;
      child->prev = cur;
      cur->child = NULL;

      while (child->next) {
        child = child->next;
      }

      child->next = next;
      if (next) next->prev = child;

      cur = child;
    }
    cur = cur->next;
  }

  return head;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

위 방법에서 child에 대해서 순회를 바로 하지 않고 child를 연결한다.

이후 다음에 방문하는 노드는 child의 시작점이 되므로 만약 child가 존재하는 경우 flatten을 반복하게 된다.

```cpp
Node* flatten(Node* head) {
  Node* cur = head;

  while (cur) {
    if (cur->child) {
      Node* next = cur->next;
      cur->next = cur->child;
      cur->next->prev = cur;
      cur->child = NULL;

      Node* last = cur->next;
      while (last->next) last = last->next;
      last->next = next;
      if (last->next) last->next->prev = last;
    }

    cur = cur->next;
  }

  return head;
}
```

## 고생한 점
