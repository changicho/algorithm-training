# 53. Maximum Subarray

[링크](https://leetcode.com/problems/maximum-subarray/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 최대 길이는 3 \* 10^4 이다.

브루트 포스 방법을 사용할 경우 시간 복잡도는 O(N^2) 이므로 제한시간 내에 불가능하다.

따라서 투포인터 방법을 이용해 O(N) 번 이내에 수행한다.

### 공간 복잡도

배열 안의 값의 범위는 -10^5 ~ 10^5 이다.

최악의 경우 절대값은 3 \* 10^9 이며 이는 int형 범위 내에 가능하다.

### 그리디 알고리즘

> 0ms

부분합 A를 다른 부분합 B, C로 나눠서 생각한다고 하자.

A = B + C 로 표현할 수 있다.

이 때 B, C는 음수일 경우 부분합이 최대가 될 수 없다.

따라서 부분합이 음수가 되는 경우에 해당 부분합을 삭제함으로 이를 구현한다.

이 때 부분합 배열을 음수로밖에 만들지 못하는 경우를 위해 정답의 초기값은 nums의 맨 앞으로 설정한다.

(배열의 맨 앞이 정답이며, 이것이 음수인 경우)

```cpp
int answer = nums.front();
int temp = 0;

for (int num : nums) {
  temp += num;
  answer = max(temp, answer);

  if (temp < 0) {
    temp = 0;
  }
}
```

### 분할정복 기법

> 4ms

현재 범위 left ~ right에서 정답이 될 수 있는 경우는 다음 경우이다.

중앙점을 mid라고 하자. (mid = (left + right) / 2)

- 중앙점 mid를 포함한 부분 (현재 부분)
- mid를 포함하지 않은 왼쪽 부분
- mid를 포함하지 않은 오른쪽 부분

중앙점 mid를 포함한 부분은 다음과 같이 계산할 수 있다.

mid를 기준으로 왼쪽으로 연속된 수들의 최대 합 + mid를 기준으로 오른쪽으로 연속된 수들의 최대 합 + mid에 있는 값.

왼쪽 부분과 오른쪽 부분 또한 같은 방법으로 구한다.

이때 시간 복잡도는 O(N \* log_2(N)) 이다.

```cpp
int divide(vector<int>& nums, int left, int right) {
  if (left > right) {
    return INT_MIN;
  }

  int mid = (left + right) / 2;
  int leftSumMax = 0;
  int rightSumMax = 0;

  for (int i = mid - 1, sum = 0; i >= left; i--) {
    sum += nums[i];
    leftSumMax = max(sum, leftSumMax);
  }

  for (int i = mid + 1, sum = 0; i <= right; i++) {
    sum += nums[i];
    rightSumMax = max(sum, rightSumMax);
  }

  int leftMax = divide(nums, left, mid - 1);
  int rightMax = divide(nums, mid + 1, right);

  return max(max(leftMax, rightMax), leftSumMax + rightSumMax + nums[mid]);
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
