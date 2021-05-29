# Remove loop in Linked List

[링크](https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

링크드 리스트의 길이는 최대 10^4 이다.

hash를 이용해 방문한 노드들을 저장할 경우 루프를 O(N)번 만에 방문할 수 있다. (hash가 아닌 일반 set인 경우 O(N \* log_2(N)))

플로이드 순환 탐색 알고리즘을 이용할 경우 O(N)번 내에 순환하는 점을 알 수 있다.

### 공간 복잡도

플로이드 순환 탐색 알고리즘의 경우 별도의 공간이 필요하지 않다.

hash를 이용해 방문한 노드를 저장할 경우 O(N)의 공간 복잡도가 필요하다.

### hash

| 내 코드 (s) | 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: | :---------: |
|    0.57     |    O(N)     |    O(N)     |

이전에 방문한 노드들을 저장한다. 만약 현재 노드의 next가 이전에 방문한 노드인 경우 next를 NULL로 설정해 연결을 끊어버린다.

```cpp
void removeLoop(Node* head) {
  unordered_set<Node*> s;

  while (head != NULL) {
    if (s.find(head->next) != s.end()) {
      head->next = NULL;
      return;
    }
    s.insert(head);
    head = head->next;
  }
}
```

### 플로이드 순환 탐색 알고리즘

| 내 코드 (s) | 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: | :---------: |
|    0.25     |    O(N)     |    O(N)     |

두개의 포인터를 이용한다. 속도가 다른 두개의 포인터를 루프에 진입시켰을때, 순환할 경우 결국 두 포인터는 같은 노드에서 만난다.

편의상 속도가 느린 포인터를 거북이, 빠른 포인터를 토끼라고 하자

두 포인터 모두 시작점에 위치한다.

1. 거북이는 매 턴마다 1칸씩 움직인다.
2. 토끼는 매 턴마다 2칸씩 움직인다.
3. 사이클이 존재하지 않는다면, 토끼는 먼저 마지막 노드에 도착한다. (loop 안에서 null 일 경우 체크해서, 마지막노드 도착 판단)
4. 사이클이 존재한다면, 거북이와 토끼는 반드시 특정노드에서 만난다. (while loop condition) 거북이와 토끼의 상대속도는 1이다. 즉 토끼는 1의 속도로 거북이에게 다가가고 있고, 만약 사이클이 있다면 반드시 만나게 된다.
5. 토끼를 그대로 두고, 거북이를 처음위치로 옮긴 뒤 둘 다 1칸씩 증가시켰을 때, 만나는 위치가 사이클의 시작점이다.
6. 사이클의 시작점을 알게되었다면, 토끼를 1칸씩 이동시켜, 사이클의 길이도 알 수 있다.

위 방법을 이용해 사이클의 시작점을 구한다.

그리고 시작점부터 탐색을 진행하며, 사이클의 시작점을 next로 갖는 두번째 노드를 찾는다. (이 노드가 끝점임)

해당 끝 노드의 next를 NULL로 설정한다.

```cpp
void removeLoop(Node* head) {
  if (head->next == NULL) return;
  Node *first = head->next, *second = head->next->next;

  while (first != second) {
    if (second->next == NULL || second->next->next == NULL) return;
    first = first->next;
    second = second->next->next;
  }

  first = head;
  while (first != second) {
    first = first->next;
    second = second->next;
  }

  first = head;
  int count = 0;
  while (true) {
    if (first->next == second) {
      count += 1;
    }
    if (count == 2) break;
    first = first->next;
  }

  first->next = NULL;
}
```

## 고생한 점
