# Intersection Point in Y Shapped Linked Lists

[링크](https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 연결 리스트를 순회하며 겹치는 부분이 있는지를 찾아야 한다.

따라서 최소한 두 연결 리스트를 순회해야 하므로 시간 복잡도는 O(N+M) 이다. (N, M : 두 연결리스트 각각의 길이)

이전에 방문 노드를 저장하는 경우 저장하는데 O(N \* log_2(N))의 시간 복잡도가 필요하다.

두 연결 리스트의 길이를 맞추고 탐색하는 경우 저장할 필요가 없으므로 탐색에만 시간이 소요된다.

### 공간 복잡도

이전에 방문한 노드를 저장하는 경우 O(N)의 공간 복잡도가 필요하다.

두 연결 리스트의 길이를 맞추는 경우 별도의 공간 복잡도가 필요하지 않다.

### 길이 맞추기

| 내 코드 (s) | 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: | :---------: |
|    0.53     |   O(N+M)    |    O(1)     |

두 연결 리스트 에서 길이가 긴 쪽을 미리 이동시켜 시작 점을 맞춘다.

두 연결 리스트의 포인터를 같이 한칸씩 이동하며 common을 찾는다.

common을 찾지 못한 경우는 두 포인터가 NULL에서 만나므로 -1을 반환한다.

```cpp
int getLength(Node* head) {
  int count = 0;
  while (head) {
    head = head->next;
    count += 1;
  }
  return count;
}

int intersectPoint(Node* head1, Node* head2) {
  int length1 = getLength(head1);
  int length2 = getLength(head2);

  if (length2 > length1) {
    swap(head1, head2);
    swap(length1, length2);
  }

  int diff = length1 - length2;
  for (int i = 0; i < diff; i++) {
    head1 = head1->next;
  }

  while (head1 != head2) {
    head1 = head1->next;
    head2 = head2->next;
  }

  if (!head1) {
    return -1;
  }

  return head1->data;
}
```

## 고생한 점
