# Rotate a Linked List

[링크](https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

링크드 리스트의 길이 N은 최대 10^3이다.

shift 이동을 위해서 한번 순회해야 하므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

vector를 이용하는 경우 N만큼의 별도의 공간이 필요해 O(N)의 공간 복잡도가 필요하다.

그러나 옮길 위치의 시작점 끝점을 이용하면 별도의 공간이 필요하지 않아 공간 복잡도는 O(1)이다.

### 포인터 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     0.25     |    O(N)     |    O(1)     |

우리가 알아야 할 포인터는 다음 4가지이다.

- 시작점
- k번째 노드
- k+1번째 노드
- 맨 마지막 노드

편의상 해당 노드들을 A, B, C, D라고 하자

기존 배열은 다음과 같은 구조이다.

```javascript
[A, ... , B, C, ..., D];
```

위 연결 리스트를 다음과 같이 바꿔야 한다.

```javascript
[C, ..., D, A, ... , B];
```

여기서 맨 첫번째 연결리스트의 이동을 쉽게 생각하기 위해 맨 앞에 dummy 노드를 추가한다.

```javascript
[dummy, A, ... , B, C, ..., D];
[dummy, C, ..., D, A, ... , B];
```

dummy에서 k번 이동해 B를 찾고 이후 C와 D까지 탐색한다.

이 때 찾은 B가 맨 마지막 노드인 경우 shift를 할 필요가 없고 C와 D를 찾을 수 없으므로 예외 처리한다.

```cpp
Node* rotate(Node* head, int k) {
  Node* cur = head;
  Node* dummy = new Node(-1);
  Node* before = dummy;

  dummy->next = head;

  for (int i = 0; i < k; i++) {
    before = before->next;
  }
  if (before->next == NULL) return head;

  cur = before->next;
  before->next = NULL;
  dummy->next = cur;

  while (cur != NULL && cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = head;

  return dummy->next;
}
```

## 고생한 점
