# 142. Linked List Cycle II

[링크](https://leetcode.com/problems/linked-list-cycle-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 최대 길이는 10^4 이다.

사이클을 찾으려면 순회를 해야 하므로 O(N)의 시간 복잡도가 소요된다.

이 때 순회의 시작점을 찾기 위해서 한번 더 순회를 하므로 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

플로이드 순환 찾기 알고리즘을 이용하면 별도의 공간이 필요하지 않다.

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
ListNode *detectCycle(ListNode *head) {
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
