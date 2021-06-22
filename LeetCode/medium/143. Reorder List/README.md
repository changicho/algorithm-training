# 143. Reorder List

[링크](https://leetcode.com/problems/reorder-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

우선 한번 순회를 통해 노드의 갯수와 순서를 파악해야한다. 이 순회에 O(N)의 시간 복잡도가 필요하다.

이후 내부적으로 노드들을 재정렬한다. 이는 한번의 순회로 구현이 가능하다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

방문 순서를 기억하고 재 정렬하는 경우 모든 노드의 방문 순서를 저장해야 한다.

이에 O(N)의 공간 복잡도가 필요하다.

별도의 공간을 사용하지 않고 재정렬 할 수 있다. 이 경우 O(1)의 공간 복잡도가 사용된다.

### 방문 순서 저장

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

모든 노드의 방문 순서를 저장한다.

이후 문제 규칙에 따라서 index를 이동시키며 재정렬한다.

이 때 노드의 갯수가 홀수개 인 경우에 대해 예외처리한다.

```cpp
void reorderList(ListNode* head) {
  vector<ListNode*> array;

  ListNode* cur = head;
  ListNode* dummy;

  while (cur) {
    array.push_back(cur);
    cur = cur->next;
  }

  int size = array.size();
  for (int i = 0; i < size / 2; i++) {
    array[i]->next = array[size - 1 - i];
    array[size - 1 - i]->next = i + 1 < size / 2 ? array[i + 1] : NULL;
  }
  if (size % 2 == 1 && size > 1) {
    array[size / 2 + 1]->next = array[size / 2];
    array[size / 2]->next = NULL;
  }

  head = array[0];
}
```

### 절반을 뒤집고 재정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(1)     |

한번 순회를 통해 배열의 절반 이후의 순서를 뒤집는다.

```cpp
// Reverse the half after middle
1->2->3->4->5->6
1->2->3->6->5->4
```

이후 시작점과 절반부터 하나씩 순회하며 새로 배열을 정렬한다.

```cpp
// Start reorder one by one
1->2->3->6->5->4
1->6->2->5->3->4
```

토끼와 거북이 알고리즘을 이용해 배열의 절반 위치를 찾을 수 있다.

이후 절반 이후의 순서를 뒤집는 연산은 O(1)의 공간복잡도로 구현 가능하다.

```cpp
ListNode *slow = head, *fast = head;
while (fast->next != NULL && fast->next->next != NULL) {
  slow = slow->next;
  fast = fast->next->next;
}

ListNode* middle = slow;
ListNode* cur = slow->next;
while (cur->next != NULL) {
  ListNode* temp = cur->next;
  cur->next = temp->next;
  temp->next = middle->next;
  middle->next = temp;
}
```

이후 순서를 재정렬 하는 알고리즘은 다음과 같다.

```cpp
slow = head;
fast = middle->next;
while (slow != middle) {
  middle->next = fast->next;
  fast->next = slow->next;
  slow->next = fast;
  slow = fast->next;
  fast = middle->next;
}
```

여기서 연결 리스트의 원소의 개수가 1개 이하인 경우는 예외 처리한다.

## 고생한 점
