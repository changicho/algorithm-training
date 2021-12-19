# 23. Merge k Sorted Lists

[링크](https://leetcode.com/problems/merge-k-sorted-lists/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 개수를 N, 리스트의 길이를 K라 하자.

모든 노드를 배열에 담은 뒤 정렬 후 새로운 연결 리스트를 만드는 경우 시간 복잡도는 O(N \* log_2(N))이다.

혹은 K개의 리스트를 번갈아 순회하며 가장 작은 노드를 연결할 수 있다.

이 경우 N개의 노드를 순회하는데 O(N)의 시간 복잡도가, 다음 노드를 채울 때마다 K개의 리스트를 순회하므로 O(N \* K)의 시간 복잡도를 사용한다.

이 때 우선순위 큐를 이용할 경우 최소값인 노드를 O(log_2(K))의 시간 복잡도로 찾을 수 있다.

따라서 우선순위 큐를 이용해 K개의 리스트를 순회하는 방법을 사용할 경우 O(N \* log_2(K))의 시간 복잡도로 풀이가 가능하다.

K개의 리스트에 대해서 2개씩 리스트를 병합해 모든 리스트를 병합 할 수 있다.

이 때 모든 경우에 대해서 병합할 경우 O(N \* K)의 시간 복잡도를 사용한다.

병합 정렬을 사용할 경우 O(N \* log_2(K))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

정답을 새로 생성할 경우 O(N)의 공간 복잡도를 사용한다.

우선순위 큐를 사용할 경우 우선순위 큐에 O(K)의 공간 복잡도를 사용한다.

병합 정렬을 이용할 경우 2개의 리스트를 합치는 함수에 (call stack) O(1)의 공간 복잡도를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      20      | O(N \* log_2(N)) |    O(N)     |

모든 리스트의 원소의 값을 배열에 담아 정렬한 뒤 새로울 연결리스트를 반환한다.

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
  vector<int> nums;

  for (ListNode* node : lists) {
    while (node) {
      nums.push_back(node->val);
      node = node->next;
    }
  }
  sort(nums.begin(), nums.end());

  ListNode* dummy = new ListNode();
  ListNode* before = dummy;
  for (int num : nums) {
    before->next = new ListNode(num);
    before = before->next;
  }

  return dummy->next;
}
```

### 2개씩 머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     164      |  O(N \* K)  |    O(1)     |

2개의 연결리스트를 머지하는 함수 mergeTwoLists가 있다고 하자.

모든 연결리스트에 대해서 이를 이용해 인접한 연결리스트끼리 머지를 계속 수행할 경우 모든 연결 리스트를 연결할 수 있다.

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode *dummy = new ListNode(0), *before = dummy;

  while (l1 && l2) {
    if (l1->val < l2->val) {
      before->next = l1;
      l1 = l1->next;
    } else {
      before->next = l2;
      l2 = l2->next;
    }
    before = before->next;
  }

  before->next = l1 ? l1 : l2;
  return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  ListNode* ret = NULL;
  for (ListNode* list : lists) {
    ret = mergeTwoLists(list, ret);
  }
  return ret;
}
```

### 병합 정렬 (분할 정복)

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      24      | O(N \* log_2(K)) |    O(K)     |

위 방법에서 매번 옆에 위치한 리스트끼리 머지할 경우 O(K)번을 순회해야 한다.

이를 병합정렬의 아이디어를 따와 분할정복으로 머지할 경우 O(log_2(K))의 시간 복잡도로 풀이가 가능하다.

이는 K개의 연결 리스트를 절반씩 분할해 합치는 방법을 이용한다.

결국엔 모든 연결리스트가 합쳐지게된다.

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode *dummy = new ListNode(0), *before = dummy;

  while (l1 && l2) {
    if (l1->val < l2->val) {
      before->next = l1;
      l1 = l1->next;
    } else {
      before->next = l2;
      l2 = l2->next;
    }
    before = before->next;
  }

  before->next = l1 ? l1 : l2;
  return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
  if (right < left) return NULL;
  if (left == right) return lists[left];
  if (left + 1 == right) return mergeTwoLists(lists[left], lists[right]);

  int mid = left + (right - left) / 2;
  ListNode* leftPart = mergeKLists(lists, left, mid);
  ListNode* rightPart = mergeKLists(lists, mid + 1, right);

  return mergeTwoLists(leftPart, rightPart);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  return mergeKLists(lists, 0, lists.size() - 1);
}
```

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      24      | O(N \* log_2(K)) |    O(1)     |

매번 K개의 연결리스트 중에서 가장 작은값을 연결리스트에 붙이며 모든 노드에 대해 진행할 경우 정렬된 연결 리스트를 구현할 수 있다.

따라서 현재 노드를 붙일 때마다 빠르게 가장 작은 값을 탐색하도록 우선순위 큐를 이용한다.

맨 처음 연결리스트들의 head를 우선순위 큐에 삽입한다.

이후 노드를 하나하나 삽입할 때마다 현재 노드가 삽입될 경우 해당 연결리스트의 head를 이동한 뒤 NULL이 아닐 경우 우선순위 큐에 삽입한다.

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
  if (lists.size() == 0) return NULL;

  auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
  priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

  for (ListNode* list : lists) {
    if (list) pq.push(list);
  }

  ListNode *dummy = new ListNode(), *before = dummy;
  while (!pq.empty()) {
    ListNode* cur = pq.top();
    pq.pop();

    before->next = cur;
    before = before->next;

    if (cur->next) {
      pq.push(cur->next);
    }
  }
  return dummy->next;
}
```

## 고생한 점
