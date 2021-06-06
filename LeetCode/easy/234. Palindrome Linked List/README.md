# 234. Palindrome Linked List

[링크](https://leetcode.com/problems/palindrome-linked-list/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

각 요소들을 한번씩 순회해야 하므로 outer 시간 복잡도는 O(N)이다.

연결리스트이므로 비교 대상을 찾기 위해 별도의 저장 공간을 사용하거나 토끼와 거북이 탐색을 이용한다.

이 경우 비교 대상을 찾는데 O(1)의 시간 복잡도가 소요되므로 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

순서대로 방문한 여부를 모두 저장하는 경우 O(N)의 공간 복잡도가 필요하다.

토끼와 거북이 알고리즘을 이용하는 경우 O(1)의 공간 복잡도가 필요하다.

### 방문 노드 저장

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     200      |    O(N)     |    O(N)     |

방문 노드들의 값을 순서대로 저장한 뒤 팰린드롬 여부를 판별한다.

```cpp
bool isPalindrome(ListNode* head) {
  vector<int> array;

  while (head) {
    array.push_back(head->val);
    head = head->next;
  }

  int size = array.size();
  for (int i = 0; i < size / 2; i++) {
    if (array[i] != array[size - 1 - i]) return false;
  }
  return true;
}
```

### 토끼와 거북이 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     204      |    O(N)     |    O(1)     |

토끼와 거북이 알고리즘을 이용해 중앙점을 찾은 뒤, 중앙점 이후부터 순서를 뒤집는다.

이후 시작점과 중간점의 요소들을 하나하나 비교하며 다를 경우 false를 반환한다.

```cpp
bool isPalindrome(ListNode* head) {
  if (head == NULL || head->next == NULL) return true;
  ListNode *slow = head, *fast = head;

  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  slow->next = reverse(slow->next);
  ListNode* half = slow->next;

  while (half != NULL) {
    if (head->val != half->val) return false;
    head = head->next;
    half = half->next;
  }

  return true;
}

ListNode* reverse(ListNode* node) {
  ListNode *pre = NULL, *next = NULL;

  while (node != NULL) {
    next = node->next;
    node->next = pre;
    pre = node;
    node = next;
  }

  return pre;
}
```

## 고생한 점
