# 962. Maximum Width Ramp

[링크](https://leetcode.com/problems/maximum-width-ramp/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

완전 탐색을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

suffix maximum과 투 포인터를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

모노토닉 스택을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

각 index마다 index까지 suffix의 최대값들을 저장해야 한다. 이에 O(N)의 공간 복잡도를 사용한다.

모노토닉 스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 투 포인터 & suffix maximum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      53      |    O(N)     |    O(N)     |

각 index마다 (N-1)부터 index까지 최대값을 저장한다. 이를 suffix maximum이라 하자.

이후 left, right 투 포인터를 이용한다.

이 때 left값이 현재 right에서의 suffix maximum보다 큰 경우 left를 증가시킨다.

이후 right가 해당 maximum까지 도달할 때 까지 left값은 변하지 않는다. 이 때 left와 right의 차이가 최대값 중 하나이다.

```cpp
int maxWidthRamp(vector<int>& nums) {
  int size = nums.size();
  vector<int> suffixMaximums(size);

  for (int i = size - 1; i >= 0; i--) {
    suffixMaximums[i] = max(i == (size - 1) ? 0 : suffixMaximums[i + 1], nums[i]);
  }

  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    while (left < right && nums[left] > suffixMaximums[right]) {
      left++;
    }
    answer = max(answer, right - left);
  }

  return answer;
}
```

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      54      |    O(N)     |    O(N)     |

왼쪽부터 순회하며 모노토닉 스택에 감소하는 순으로 index를 저장한다.

이후 오른쪽부터 순회하며 모노토닉 스택에서 현재 값 이하의 작은 값들의 index들을 pop하며 최대값을 갱신한다.

```cpp
int maxWidthRamp(vector<int>& nums) {
  int size = nums.size();
  stack<int> stk;

  // decreasing stack
  for (int i = 0; i < size; i++) {
    if (stk.empty() || nums[stk.top()] > nums[i]) {
      stk.push(i);
    }
  }

  int answer = 0;
  for (int i = size - 1; i >= 0; i--) {
    while (!stk.empty() && nums[stk.top()] <= nums[i]) {
      answer = max(answer, i - stk.top());

      stk.pop();
    }
  }

  return answer;
}
```

## 고생한 점
