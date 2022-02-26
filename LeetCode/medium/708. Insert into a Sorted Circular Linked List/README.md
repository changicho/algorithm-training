# 708. Insert into a Sorted Circular Linked List

[링크](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

총 노드의 개수를 N이라 하자.

노드를 순회하며 삽입할 위치를 찾아야 하므로 한번의 순회에 O(N)의 시간 복잡도를 사용한다.

이 과정에서 각 경우별로 삽입할 노드의 위치를 찾는다.

### 공간 복잡도

삽입할 노드의 위치를 순회하며 찾으면 되므로 O(1)의 공간복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

노드를 삽입할 때 다음 3가지 경우가 존재한다.

- 범위 중간에 삽입하는 경우
- 현재 범위보다 insert value가 작은 경우
- 현재 범위보다 insert value가 큰 경우

여기서 현재 범위를 벗어나는 경우는 링크드 리스트의 끝나는 점 (가장 큰 값 마지막)에 insert value를 삽입하면 된다.

중간에 삽입하는 경우는 순회를 통해서 중간에 삽입할 위치를 찾는다.

이 때 조건은 다음과 같다.

- prevValue <= insertValue <= nextValue

만야 head가 없는 경우 현재 노드를 시작점으로 설정해 반환한다. (엣지 케이스)

링크드 리스트의 범위를 찾기 위해서 한번 순회를 통해 범위를 탐색한다.

```cpp
Node* insert(Node* head, int insertVal) {
  Node* node = new Node(insertVal);

  // Edge case
  if (!head) {
    node->next = node;
    return node;
  }

  int minimum = head->val;
  int maximum = head->val;

  Node* cur = head;
  cur = cur->next;
  // O(N)
  while (cur != head) {
    minimum = min(minimum, cur->val);
    maximum = max(maximum, cur->val);
    cur = cur->next;
  }
  // out of range case
  if (insertVal < minimum || maximum < insertVal) {
    // can insert any position case
    if (minimum == maximum) {
      node->next = head->next;
      head->next = node;

      return head;
    }

    // find last maximum node
    cur = head;
    while (cur->val <= cur->next->val) {
      cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;

    return head;
  }

  // find position to insert
  cur = head;
  while (true) {
    if (cur->val <= insertVal && insertVal <= cur->next->val) {
      break;
    }

    cur = cur->next;
  }

  node->next = cur->next;
  cur->next = node;

  return head;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

한번 순회하며 3가지 경우에 대한 조건을 만족하면 삽입한다.

이 때 이전노드와 다음노드를 연이어 이동시키며 탐색을 진행한다.

- 범위 중간에 삽입하는 경우
- 현재 범위보다 insert value가 작은 경우
- 현재 범위보다 insert value가 큰 경우

```cpp
Node* insert(Node* head, int insertVal) {
  Node* node = new Node(insertVal);

  if (!head) {
    node->next = node;
    return node;
  }

  Node* prev = head;
  Node* next = head->next;
  bool inserted = false;

  while (true) {
    bool isCenter = (prev->val <= insertVal && insertVal <= next->val);
    bool isLower = (prev->val > next->val && insertVal < next->val);
    bool isUpper = (prev->val > next->val && insertVal > prev->val);

    if (isCenter || isLower || isUpper) {
      prev->next = new Node(insertVal, next);
      inserted = true;
      break;
    }

    prev = prev->next;
    next = next->next;

    if (prev == head) break;
  }

  if (!inserted) {
    prev->next = new Node(insertVal, next);
  }

  return head;
}
```

## 고생한 점
