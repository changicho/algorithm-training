# 3676. Count Bowl Subarrays

[링크](https://leetcode.com/problems/count-bowl-subarrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

모노토닉 스택을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모노토닉 스택에 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      22      |    O(N)     |    O(N)     |

모노토닉 스택에 top으로 갈 수록 감소하는 방향으로 쌓는다.

이 때 현재 숫자보다 모노토닉 스택의 top에 해당하는 숫자가 작은 경우,

해당 top에 존재하던 숫자의 index와 현재 숫자의 index의 범위에 해당하는 부분이 조건을 만족하는 부분배열이 된다.

따라서 해당 부분배열의 크기가 3 이상인 경우 정답을 증가시킨다.

이후 top을 pop해 모노토닉 스택의 조건을 만족시킨다.

```cpp
long long bowlSubarrays(vector<int>& nums) {
  int size = nums.size();

  stack<int> stk;
  long long answer = 0;

  for (int i = 0; i < size; i++) {
    while (!stk.empty() && nums[stk.top()] <= nums[i]) {
      if (i - stk.top() + 1 >= 3) answer++;
      stk.pop();
    }

    if (!stk.empty() && i - stk.top() + 1 >= 3) {
      answer++;
    }

    stk.push(i);
  }

  return answer;
}
```

## 고생한 점
