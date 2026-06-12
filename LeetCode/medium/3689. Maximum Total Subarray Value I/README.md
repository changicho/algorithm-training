# 3689. Maximum Total Subarray Value I

[링크](https://leetcode.com/problems/maximum-total-subarray-value-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

subarray를 중복해서 선택할 수 있으므로 최대값, 최소값이 포함된 것만 반복한다.

최대값, 최소값을 찾는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최대값, 최소값을 찾는데 O(1)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

subarray를 중복해서 선택할 수 있으므로 최대값, 최소값이 포함된 것만 전부 선택한다.

따라서 최대값, 최소값의 차이를 K번 반복해 정답에 더한다.

```cpp
long long maxTotalValue(vector<int>& nums, int k) {
  int maximum = nums[0];
  int minimum = nums[0];

  for (int& num : nums) {
    maximum = max(maximum, num);
    minimum = min(minimum, num);
  }

  return (long long)(maximum - minimum) * k;
}
```

## 고생한 점
