# 1171. Remove Zero Sum Consecutive Nodes from Linked List

[링크](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

링크드 리스트의 노드의 수를 N이라 하자.

각 노드마다 이후 노드들을 모두 순회하며 sum이 0인 경우 삭제할 수 있다. 이 경우 O(N^2)의 시간 복잡도를 사용한다.

hash map을 이용해 순회하며 sum을 저장하고, 이후 중복된 sum이 나오는 경우 중간의 노드들을 삭제할 수 있다.

이 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

완전 탐색을 이용할 경우 별도의 공간이 필요하지 않다.

hash map을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |   O(N^2)    |    O(1)     |

노드의 시작부터 끝까지 순회하며, 각 노드를 시작점으로 하는 prefix sum을 구한다.

sum이 0이 되는 경우 해당 구간을 삭제한다.

```cpp
ListNode *removeZeroSumSublists(ListNode *head) {
  ListNode *dummy = new ListNode(0, head);
  ListNode *cur = dummy;

  while (cur) {
    int sum = 0;
    ListNode *next = cur->next;

    while (next) {
      sum += next->val;
      if (sum == 0) {
        cur->next = next->next;
      }
      next = next->next;
    }

    cur = cur->next;
  }
  return dummy->next;
}
```

### prefix

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

시작 노드부터 prefix sum을 구하며 hash map에 다음과 같이 저장한다.

- key : prefix sum
- val : 노드

이후 현재 prefix sum이 hash map에 존재하는 경우 해당 노드부터 현재 노드까지의 구간을 삭제한다.

이 때 삭제하는 구간의 prefix sum 또한 hash map에서 삭제한다.

```cpp
ListNode *removeZeroSumSublists(ListNode *head) {
  int sum = 0;
  ListNode *dummy = new ListNode();
  dummy->next = head;
  ListNode *cur = head;
  ListNode *before = dummy;

  unordered_map<int, ListNode *> um;
  um[0] = before;

  while (cur) {
    sum += cur->val;

    if (um.count(sum) > 0) {
      ListNode *target = um[sum];

      // erase from map
      ListNode *temp = target->next;
      int tempSum = sum + temp->val;
      while (tempSum != sum) {
        um.erase(tempSum);
        temp = temp->next;
        tempSum += temp->val;
      }

      target->next = cur->next;
    } else {
      um[sum] = cur;
    }

    before = cur;
    cur = cur->next;
  }

  return dummy->next;
}
```

## 고생한 점
