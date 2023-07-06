# 209. Minimum Size Subarray Sum

[링크](https://leetcode.com/problems/minimum-size-subarray-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

모든 경우를 브루트 포스로 탐색할 경우 시간 복잡도는 O(N^2)가 되며 이는 제한시간 내에 불가능하다.

따라서 슬라이딩 윈도우를 이용해 O(N)의 시간 복잡도로 풀이한다.

### 공간 복잡도

슬라이딩 윈도우를 이용하기 위한 index를 저장할 공간과 sum을 저장할 공간이 필요하다.

이는 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

left ~ right 구간의 합이 target 이상이 될 때의 최소 길이를 찾아야한다.

이를 위해 left, right 중 한 index만 값을 증가시키며 target 이상이 되는 값을 찾는다.

현재 구간의 합이 target 미만인 경우 새로운 수를 추가해야 하므로 right를 증가시킨다.

현재 구간의 합이 target 이상인 경우 기존의 수를 줄여야 하므로 left를 증가시킨다.

이 때 target 이상이므로 정답을 갱신한다.

이를 left가 유효할 때 까지 반복한다.

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
  int size = nums.size();
  int left = 0, right = 0;
  int answer = size + 1;

  int curSum = 0;
  while (left < size) {
    if (target <= curSum) {
      answer = min(answer, right - left);
    }

    if (curSum < target && right < size) {
      curSum += nums[right];
      right++;
      continue;
    }

    curSum -= nums[left];
    left += 1;
  }

  return answer == size + 1 ? 0 : answer;
}
```

혹은 right를 증가시키며 sum에 현재 right에 위치한 nums의 값을 더한다.

이 때 sum이 target 이상이 되는 경우 left를 증가시키며 sum에서 left에 위치한 nums의 값을 뺀다.

각 과정마다 sum이 target 이상인 경우 정답을 갱신한다.

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
  int size = nums.size();
  int answer = INT_MAX;

  for (int right = 0, left = 0, sum = 0; right < size; right++) {
    sum += nums[right];

    while (left < right && sum - nums[left] >= target) {
      sum -= nums[left];
      left++;
    }

    if (sum >= target) {
      answer = min(answer, right - left + 1);
    }
  }

  return answer == INT_MAX ? 0 : answer;
}
```

## 고생한 점
