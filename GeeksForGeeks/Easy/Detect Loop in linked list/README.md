# Detect Loop in linked list

[링크](https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

링크드 리스트의 최대 길이는 10^4이다.

중간에 연결 사이클이 있는 경우 최소한 한번은 노드를 순회해야 찾을 수 있으므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

set을 이용해 방문 노드를 체크하는 경우 O(N) 만큼의 공간 복잡도가 필요하다.

### 방문 체크

| 내 코드 (s) | 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: | :---------: |
|    0.31     |    O(N)     |    O(N)     |

방문한 노드들을 저장하며 현재 노드가 이전에 방문한 노드일 경우 사이클이 존재하는것을 알 수 있다.

```cpp
bool detectLoop(Node* head) {
  unordered_set<Node*> s;

  while (head) {
    if (s.find(head) != s.end()) return true;

    s.insert(head);
    head = head->next;
  }

  return false;
}
```

### 특정 횟수를 반복하며 NULL을 만나는지 체크

| 내 코드 (s) | 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: | :---------: |
|    0.12     |    O(N)     |    O(1)     |

연결 리스트의 길이는 최대 10^4 이다.

2 \* 10^4 번을 순회했을 때 NULL에 도달하지 못한 경우는 사이클이 존재할 때이다.

이를 이용해 사이클 여부를 구할 수 있다.

```cpp
bool detectLoop(Node* head) {
  int count = 20001;

  while (count > 0) {
    count -= 1;
    head = head->next;

    if (head == NULL) return false;
  }

  return true;
}
```

### 플로이드 사이클 찾기 알고리즘

| 내 코드 (s) | 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: | :---------: |
|    0.12     |    O(N)     |    O(1)     |

두 포인터를 이용한다.

처음 포인터는 한칸씩 이동하고, 두번째 포인터는 두칸씩 이동한다.

만약 사이클이 존재할 경우 두 포인터는 한 지점에서 만난다.

사이클이 존재하지 않을 경우 두번째 포인터가 먼저 끝점에 도달한다.

```cpp
bool detectLoop(Node* head) {
  if (head->next == NULL) return false;

  Node *first = head->next, *second = head->next->next;

  while (first != second) {
    if (second == NULL || second->next == NULL) return false;
    first = first->next;
    second = second->next->next;
  }

  return true;
}
```

## 고생한 점
