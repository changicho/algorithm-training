# 2074. Reverse Nodes in Even Length Groups

[링크](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 리스트의 원소의 갯수를 N이라 하자.

배열을 이용할 경우 우선 한번 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

이후 뒤집는데 들어가는 총 연산의 시간 복잡도는 O(N)이다.

포인터를 이용해 순서를 뒤집을 수 있다. 이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

배열을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

포인터를 사용할 경우 상수 공간 복잡도를 사용한다.

### 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1475     |    O(N)     |    O(N)     |

배열에 먼저 모든 값을 저장한다.

이후 뒤집어야 되는 부분을 뒤집는다.

이 때 현재 그룹이 갯수가 모자란 경우는 별도로 처리해준다.

```cpp
ListNode* reverseEvenLengthGroups(ListNode* head) {
  ListNode* cur = head;

  vector<int> arr;
  while (cur) {
    arr.push_back(cur->val);

    cur = cur->next;
  }

  int size = arr.size();
  for (int i = 0, step = 1; i < size; i += step, step++) {
    int curSize = i + step < size ? step : size - i;
    if (curSize % 2 == 0) {
      reverse(arr.begin() + i, arr.begin() + i + curSize);
    }
  }

  ListNode* dummy = new ListNode();
  cur = dummy;
  for (int& num : arr) {
    cur->next = new ListNode(num);
    cur = cur->next;
  }

  return dummy->next;
}
```

## 고생한 점
