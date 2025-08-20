# 3627. Maximum Median Sum of Subsequences of Size 3

[링크](https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬 후 가장 유리한 값을 선택할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N) 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      53      | O(N \* log_2(N)) |    O(N)     |

3개의 원소를 선택할 때 최대, 최소 값이 아닌 중앙값을 선택해야 한다.

따라서 중앙값이 가장 큰 경우들로만 선택한다.

배열의 원소를 정렬 후 가장 큰 값과 가장 작은 값을 선택한다. 이후 남은 숫자들 중 가장 큰 값을 중앙값으로 선택한다.

이를 반복하여 중앙값의 합을 구한다.

```cpp
long long maximumMedianSum(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  long long sum = 0;

  int left = 0, right = size - 1;

  while (left < right) {
    sum += nums[right - 1];
    left++;
    right -= 2;
  }
  return sum;
}
```

## 고생한 점
