# 2. Add Two Numbers

[링크](https://leetcode.com/problems/add-two-numbers/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

리스트 노드의 최대 길이는 100이다.

따라서 최악의 경우 시간 복잡도는 O(101)이다.

### 공간 복잡도

ListNode를 반환한다.

### 큰수 덧셈

숫자가 뒤집어진 상태로 들어오므로 순서대로 연산을 수행하면 된다.

이때 carry가 존재하는 경우 연산을 수행해야한다.

ListNode는 포인터이므로 생성시에 new를 붙여 생성한다.

또한 현재 ListNode와 시작점 ListNode를 동시에 가져야한다.

연산이 끝난 후 시작점 ListNode를 한단계 뒤로 이동시킨다.

포인터가 NULL인지 판단은 다음과 같이 수행한다.

```cpp
ListNode* cur;
if (cur) {
  // cur is not NULL
}
// or
if (cur != NULL) {
  // cur is not NULL
}
```

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* answer = new ListNode();
  ListNode* curNode = answer;

  bool carry = false;

  while (l1 || l2 || carry) {
    int cur = 0;

    if (l1) {
      cur += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      cur += l2->val;
      l2 = l2->next;
    }
    if (carry) {
      cur += 1;
      carry = false;
    }

    if (cur >= 10) {
      cur -= 10;
      carry = true;
    }

    ListNode* next = new ListNode(cur);
    curNode->next = next;
    curNode = curNode->next;
  }

  return answer->next;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      24      |

## 고생한 점
