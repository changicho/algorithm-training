# 2439. Minimize Maximum of Array

[링크](https://leetcode.com/problems/minimize-maximum-of-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

현재 배열에 대해 특정 수에 대해 주어진 연산을 수행했을 때 가능한지 판단하는 데 O(N)의 시간 복잡도를 사용한다.

가능한 범위에 대해 이를 이분 탐색으로 판단할 경우 O(N \* log_2(10^9))의 시간 복잡도가 소요된다.

### 공간 복잡도

주어진 숫자의 범위가 10^9 까지이며 N이 최대 10^5 이므로 int형을 초과할 수 있다.

따라서 int를 초과하는 범위의 배열을 선언한다.

이 경우 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     400      | O(N \* (log_2(10^9))) |    O(N)     |

특정 숫자에 대해서 현재 배열로 구성할 수 있는지 판단을 다음과 같이 할 수 있다.

- i번째 수를 X만큼 감소시키면 i-1번째 수를 X만큼 증가시킨다.
- 맨 오른쪽 수부터 특정 숫자보다 큰 만큼 감소시킨다.
- 이를 맨 왼쪽 수 까지 반복하며 첫번째 수가 특정 수보다 큰지 판단한다.

위 과정은 O(N)의 시간 복잡도로 구현 가능하다.

특정 숫자를 이분 탐색으로 구하면 O(N \* log_2(10^9))의 시간 복잡도로 구현 가능하다.

```cpp
bool calc(vector<long> nums, long long target) {
  int size = nums.size();
  for (int i = size - 1; i > 0; i--) {
    if (nums[i] > target) {
      long diff = nums[i] - target;
      nums[i] -= diff;
      nums[i - 1] += diff;
    }
  }
  if (nums[0] > target) return false;
  return true;
}

int minimizeArrayValue(vector<int>& nums) {
  int left = 0, right = 1e9 + 1;

  vector<long> arr(nums.begin(), nums.end());
  int answer = right;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (calc(arr, mid)) {
      // pick left
      right = mid;
      answer = min(answer, mid);
    } else {
      // pick right
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
