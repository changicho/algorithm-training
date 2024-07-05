# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

[링크](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 연결리스트의 길이를 N이라 하자.

각 연결리스트를 순회하며 직전값과 이전값 다음값을 비교하고 정답을 갱신한다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회와 동시에 정답을 갱신할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     156      |    O(N)     |    O(1)     |

현재 노드 이전노드와 다음노드의 값을 알아야 한다.

따라서 현재 순회하는 노드와 직전 노드를 가리키는 포인터를 이용한다.

각 노드를 순서대로 순회하며 정답을 만족하는 경우를 판단한다.

이 때 정답을 만족하는 가장 처음 index와 직전 index를 이용해 정답을 갱신한다.

```cpp
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
  int minimum = INT_MAX, maximum = INT_MIN;

  int beforeI = -1;
  int firstI = -1;
  int i = 1;
  ListNode *cur = head->next, *before = head;

  while (cur->next) {
    cur = cur->next;

    int left = before->val;
    int target = before->next->val;
    int right = cur->val;

    if (left < target && target > right || left > target && target < right) {
      if (beforeI != -1) {
        minimum = min(minimum, i - beforeI);
      }
      if (firstI != -1) {
        maximum = max(maximum, i - firstI);
      }

      if (firstI == -1) firstI = i;
      beforeI = i;
    }

    i++;
    before = before->next;
  }

  if (minimum == INT_MAX || maximum == INT_MIN) {
    return {-1, -1};
  }
  return {minimum, maximum};
}
```

## 고생한 점
