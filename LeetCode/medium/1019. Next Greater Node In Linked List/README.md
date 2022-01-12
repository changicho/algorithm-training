# 1019. Next Greater Node In Linked List

[링크](https://leetcode.com/problems/next-greater-node-in-linked-list/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

링크드 리스트의 길이를 N이라 하자.

각 index마다 현재 값보다 큰 첫번째 값이 나오는걸 찾아야한다.

이를 모든 경우에 대해서 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

스택을 이용해 현재 index을 정답의 값으로 하는 이전의 노드에 대해 채우는 방식을 사용할 수 있다.

이 경우 모든 순회에서 스택을 사용해 O(N)의 시간 복잡도를 사용하며, 순회에 O(N)의 시간 복잡도를 사용하므로

총 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     212      |    O(N)     |    O(N)     |

연결리스트를 vector로 변환한다.

이후 각 vector의 값을 index 0부터 순차적으로 순회한다.

이후 각 수를 순회하며 현재 숫자가 stack의 top보다 큰 경우를 비교한다.

이는 top에 있는 index의 값보다 큰 경우 index에 해당하는 첫번째 큰 값은 현재 값이 되기 때문이다.

만약 크지 않을 경우 stack에 현재 index를 삽입한다.

이후 큰 숫자가 나오면 stack의 수를 가능할 때 까지 pop하며 정답을 갱신한다.

총 순회에서 스택은 총 N번 push, pop을 수행한다.

여기서 stack이 빈 경우는 첫번째 index를 순회할 때만 이므로 첫번째에 대해선 이미 stack에 삽입 후 이후 index부터 순회한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> nextLargerNodes(ListNode* head) {
  ListNode* cur = head;
  vector<int> nums;
  while (cur) {
    nums.push_back(cur->val);
    cur = cur->next;
  }

  int size = nums.size();
  vector<int> answer(size, 0);

  stack<int> st;
  st.push(0);

  for (int i = 1; i < size; i++) {
    while (!st.empty() && nums[st.top()] < nums[i]) {
      int target = st.top();
      answer[target] = nums[i];
      st.pop();
    }
    st.push(i);
  }

  return answer;
}
```

## 고생한 점
