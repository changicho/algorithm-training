# 673. Number of Longest Increasing Subsequence

[링크](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

LIS를 이용할 경우 O(N \* log(N)), 혹은 O(N^2)의 시간 복잡도를 사용한다.

여기서 가능한 가장 긴 모든 LIS의 개수를 구해야 한다.

따라서 직전 결과를 모두 이용해 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

LIS 배열을 생성해야 하며 이는 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     132      |   O(N^2)    |    O(N)     |

이전 연산결과를 이용해 LIS를 구하는 방법을 사용한다.

각 index별로 lis의 최대 길이와 해당 index까지 만들 수 있는 lis들의 최대 개수를 같이 저장한다.

이후 lis를 갱신하면서 정답을 같이 갱신한다.

현재 최대 개수를 저장할 수 있는 경우는 다음과 같다.

- 이전상태에서 현재 index에 해당하는 값이 lis에 추가될 수 있는 경우 (더함)
- 현재까지 가능한 lis 길이가 새로운 최대가 되는 경우 (초기화)

이를 이용해 lis의 길이가 갱신되거나, 이전 경우에서 추가할 수 있는 경우 정답을 갱신한다.

```cpp
struct Status {
  int length, count;
};

int findNumberOfLIS(vector<int>& nums) {
  int size = nums.size();

  int maxLength = 0;
  int answer = 0;
  // dp[index] = {maximum LIS length, maximum case}
  vector<Status> dp(size, {1, 1});  // initial value is 1,1

  for (int current = 0; current < size; ++current) {
    for (int before = 0; before < current; ++before) {
      if (nums[before] >= nums[current]) continue;

      if (dp[before].length + 1 == dp[current].length) {
        // from before, can reach current length
        dp[current].count += dp[before].count;
      }

      if (dp[before].length >= dp[current].length) {
        dp[current] = {dp[before].length + 1, dp[before].count};
      }
    }

    if (maxLength == dp[current].length) {
      answer += dp[current].count;
    } else if (maxLength < dp[current].length) {
      maxLength = dp[current].length;
      answer = dp[current].count;
    }
  }

  return answer;
}
```

## 고생한 점
