# 2464. Minimum Subarrays in a Valid Split

[링크](https://leetcode.com/problems/minimum-subarrays-in-a-valid-split/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

동적 계획법을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     126      |   O(N^2)    |    O(N)     |

다음과 같은 dp식을 생성한다.

```cpp
int dp[i]; // i번째 까지 나눌 수 있는 최소횟수

dp[0] = 1;

// left ~ right 구간을 분리할 수 있는 경우
dp[right] = min(dp[right], dp[left - 1] + 1);
```

이를 이용해 왼쪽부터 dp식을 갱신하며 정답을 구한다.

```cpp
int validSubarraySplit(vector<int>& nums) {
  int size = nums.size();

  vector<long long> dp(size, INT_MAX);

  for (int right = 0; right < size; right++) {
    for (int left = 0; left <= right; left++) {
      if (gcd(nums[left], nums[right]) == 1) continue;

      long long before = (left - 1) < 0 ? 0 : dp[left - 1];
      dp[right] = min(dp[right], before + 1);
    }
  }

  if (dp.back() == INT_MAX) return -1;
  return dp.back();
}
```

## 고생한 점
