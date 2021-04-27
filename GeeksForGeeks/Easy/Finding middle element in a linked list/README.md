# Finding middle element in a linked list

[링크](https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

연결 리스트의 길이는 최대 5,000 이다.

중간점을 찾기 위해선 한번 순회해야 하므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

별도의 공간이 필요하지 않다.

### 길이를 찾은 후 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     0.20     |    O(N)     |    O(1)     |

먼저 길이를 찾은 후에 길이의 절반 만큼만 head에서 이동한다.

현재 방문한 중간 노드의 값을 return한다.

```cpp
int getMiddle(Node *head) {
  Node *cur = head;
  int length = 0;

  while (cur != NULL) {
    length += 1;
    cur = cur->next;
  }

  length /= 2;

  cur = head;
  for (int i = 0; i < length; i++) {
    cur = cur->next;
  }

  return cur->data;
}
```

### 토끼와 거북이 (투포인터)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     0.19     |    O(N)     |    O(1)     |

한번에 한칸씩 움직이는 거북이 포인터와 한번에 두칸씩 움직이는 토끼 포인터를 동시에 움직인다.

토끼 포인터가 끝점에 도달한 경우 거북이 포인터는 토끼의 절반을 움직였으므로 중앙에 위치한다.

```cpp
int getMiddle(Node *head) {
  Node *turtle = head, *rabbit = head;
  int length = 0;

  while (rabbit != NULL && rabbit->next != NULL) {
    turtle = turtle->next;
    rabbit = rabbit->next->next;
  }

  return turtle->data;
}
```

## 고생한 점
