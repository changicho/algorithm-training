# 456. 132 Pattern

[링크](https://leetcode.com/problems/132-pattern/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 원소의 갯수를 N이라 하자.

모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 사용하므로 이는 제한시간 내에 불가능하다.

모노토닉 스택을 이용해 O(N)의 시간 복잡도를 사용해 풀이할 수 있다.

### 공간 복잡도

모노토닉 스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      99      |    O(N)     |    O(N)     |

N이 3 미만인 경우는 132 패턴이 존재하지 않으므로 false를 반환한다.

0 ~ i index까지의 최소값을 저장하는 배열 minArr을 생성한다.

이후 역순으로 순회하며 스택의 top이 커지는 순으로 스택에 쌓는다.

이 때 현재 값이 현재까지 방문한 값들 중 최소값인 경우 스택에 쌓지 않고 비교하지 않고 넘어간다.

이 때 기존 stack의 top이 현재 i까지 minArr의 값보다 이하인 경우 이를 pop한다.

만약 현재 값이 stack의 top보다 큰 경우 132 패턴이 존재하므로 true를 반환한다.

이는 현재 값이 가장 큰 peak가 되고, stack의 top이 두 번째로 큰 값, 가장 작은 값은 minArr과의 비교에서 현재보다 앞에 있음이 보장되기 때문이다.

```cpp
bool find132pattern(vector<int>& nums) {
  size_t size = nums.size();
  if (size < 3) {
    return false;
  }
  stack<int> stk;
  vector<int> minArr(size);  // until i, the min value

  minArr[0] = nums[0];
  for (size_t i = 1; i < size; i++) {
    minArr[i] = min(minArr[i - 1], nums[i]);
  }

  for (size_t i = size - 1; i > 0; i--) {
    if (nums[i] == minArr[i]) continue;

    while (!stk.empty() && stk.top() <= minArr[i]) {
      stk.pop();
    }
    if (!stk.empty() && stk.top() < nums[i]) {
      return true;
    }
    stk.push(nums[i]);
  }
  return false;
}
```

## 고생한 점
