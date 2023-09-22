# 1063. Number of Valid Subarrays

[링크](https://leetcode.com/problems/number-of-valid-subarrays/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 5 \* 10^4)

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

이는 제한시간 내에 불가능하다.

모노토닉 스택을 이용해 O(N)의 시간 복잡도로 풀이할 수 있다.

### 공간 복잡도

모노토닉 스택에 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      65      |    O(N)     |    O(N)     |

subArray의 맨 왼쪽 수가 가장 작은 모든 subArray의 경우의 수를 세야한다.

모노토닉 스택에 top으로 갈 수록 숫자가 작아지도록 만든다.

이후 숫자를 순회하며 현재 숫자보다 큰 값들은 모두 스택에서 뺀 뒤 현재 숫자를 push해 모노토닉함을 유지한다.

이 때 스택에서 뺀 숫자들은 현재 숫자보다 큰 값들이므로 직전까지 해당 숫자를 가장 왼쪽으로 하는 subArray의 경우의 수를 구할 수 있다.

따라서 매 경우마다 stack에서 숫자가 빠질 때 정답에 더한다.

```cpp
int validSubarrays(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;

  stack<int> stk;
  for (int i = 0; i < size; i++) {
    // pop
    while (!stk.empty() && nums[i] < nums[stk.top()]) {
      answer += (i - stk.top());
      stk.pop();
    }

    stk.push(i);
  }

  while (!stk.empty()) {
    answer += (nums.size() - stk.top());
    stk.pop();
  }

  return answer;
}
```

## 고생한 점
