# 141. Linked List Cycle

[링크](https://leetcode.com/problems/linked-list-cycle/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기는 최대 10^4이다.

배열에 사이클이 있는 지 확인하는데 최소 한번의 순회가 필요하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

set을 이용해 중복 검사를 할 경우 공간 복잡도는 O(N)이다.

특정 횟수동안 움직이고 순회가 끝나는지 아닌지를 판단할 경우 별도의 공간이 필요하지 않으므로 공간 복잡도는 O(1)이다.

### set

> 24ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(N)

방문하는 노드의 포인터들을 기록하고, 현재 노드를 이전에 방문했는지 여부를 판단해 풀이할 수 있다.

```cpp
bool hasCycle(ListNode *head) {
  set<ListNode *> s;
  ListNode *cur = head;
  bool answer = false;

  while (cur) {
    if (s.find(cur) != s.end()) {
      answer = true;
      break;
    }
    s.insert(cur);
    cur = cur->next;
  }

  return answer;
}
```

### 특정 횟수까지 검사

> 12ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(1)

N은 최대 10^4 이다.

만약 최악의 경우 사이클이 존재하면 2 \* N번 이상 소요되는 것이 확실하다.

따라서 사이클이 없는 경우에 절대로 순회가 끝나는 횟수 까지만 순회해서 판별할 수 있다.

```cpp
bool hasCycle(ListNode *head) {
  int count = 20001;
  while (count--) {
    if (head == NULL) {
      return false;
    }
    head = head->next;
  }

  return true;
}
```

### 플로이드 순환 찾기 알고리즘

> 8ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(1)

두개의 포인터를 이용한다. 속도가 다른 두개의 포인터를 루프에 진입시켰을때, 순환할 경우 결국 두 포인터는 같은 노드에서 만난다.

편의상 속도가 느린 포인터를 거북이, 빠른 포인터를 토끼라고 하자

두 포인터 모두 시작점에 위치한다.

1. 거북이는 매 턴마다 1칸씩 움직인다.
2. 토끼는 매 턴마다 2칸씩 움직인다.
3. 사이클이 존재하지 않는다면, 토끼는 먼저 마지막 노드에 도착한다. (loop 안에서 null 일 경우 체크해서, 마지막노드 도착 판단)
4. 사이클이 존재한다면, 거북이와 토끼는 반드시 특정노드에서 만난다. (while loop condition) 거북이와 토끼의 상대속도는 1이다. 즉 토끼는 1의 속도로 거북이에게 다가가고 있고, 만약 사이클이 있다면 반드시 만나게 된다.
5. 토끼를 그대로 두고, 거북이를 처음위치로 옮긴 뒤 둘 다 1칸씩 증가시켰을 때, 만나는 위치가 사이클의 시작점이다.
6. 사이클의 시작점을 알게되었다면, 토끼를 1칸씩 이동시켜, 사이클의 길이도 알 수 있다.

따라서 두 노드가 만나는지 여부로 사이클을 판별할 수 있다.

```cpp
bool hasCycle(ListNode *head) {
  ListNode *slow = head, *fast = head;

  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }

  return false;
}
```

사이클의 길이또한 구할 수 있다.

```cpp
ListNode* findLoopPoint(ListNode *head) {
  ListNode *slow = head, *fast = head;
  bool hasCycle = false;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      hasCycle = true;
      break;
    }
  }

  if (hasCycle) {
    slow = head;
    while (slow != fast) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
  return NULL;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      8       |

## 고생한 점
