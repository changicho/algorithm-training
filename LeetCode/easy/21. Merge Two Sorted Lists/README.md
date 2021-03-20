# 21. Merge Two Sorted Lists

[링크](https://leetcode.com/problems/merge-two-sorted-lists/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

리스트의 최대 크기는 50이다. 두 리스트의 모든 원소를 순회해야 하므로 시간 복잡도는 O(100) 이다.

### 공간 복잡도

구조체를 사용하며 포인터 변수를 사용하므로 포인터를 이용한다.

### 리스트 노드

제공되는 리스트 노드는 다음과 같다.

```cpp
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

리스트 노드에 다음 노드를 추가할 때는 다음과 같은 연산을 사용한다.

```cpp
cur->next = listNode;
listNode = listNode->next;
```

반복문을 이용해 다음과 같이 풀이할 수 있다.

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* ret = new ListNode(0);
  ListNode* cur = ret;

  while (l1 != NULL && l2 != NULL) {
    if (l1->val < l2->val) {
      cur->next = l1;
      l1 = l1->next;
    } else {
      cur->next = l2;
      l2 = l2->next;
    }
    cur = cur->next;
  }

  if (l1 != NULL) {
    cur->next = l1;
  } else {
    cur->next = l2;
  }

  ret = ret->next;
  return ret;
}
```

만약 한쪽 리스트의 원소가 끝에 도달한 경우, 그 뒤로 남은 리스트를 붙여버리면 된다.

그리고 맨 처음 시작점 노드를 한칸 뒤로 옮긴다. (맨 처음 노드는 값이 빈 노드임)

재귀호출을 이용해 보다 간단하게 풀이할 수 있다.

```cpp
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
  if (b == NULL) {
    return a;
  }
  if (a == NULL || (a->val > b->val)) {
    swap(a, b);
  }

  a->next = mergeTwoLists(a->next, b);
  return a;
}
```

리스트노드 a는 값이 작은 노드로 고정한다.

따라서 재귀호출을 진행하며 값이 작은 노드들을 next로 고정해 a를 갱신한다.

이 때 b노드가 NULL인 경우 a를 뒤에 그대로 붙인다.

## 정리

| 내 코드 (ms) |
| :----------: |
|      8       |

## 고생한 점
