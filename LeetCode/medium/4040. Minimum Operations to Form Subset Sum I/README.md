# 4040. Minimum Operations to Form Subset Sum I

[링크](https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 만들어야 하는 합을 S, 배열 원소의 최대값을 M이라 하자.

배낭 문제(Knapsack)이므로 동적 계획법을 사용할 경우 O(N \* S)의 시간 복잡도를 기본적으로 사용한다.

각 과정마다 현재 값을 이용해 2로 나누거나 곱하는 탐색을 수행하는데 O(log_2(M))의 시간 복잡도를 사용한다.

따라서 총 O(N \* S \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(S)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     131      | O(N \* S \* log_2(M)) |    O(S)     |

각 원소를 순회하며, 이전까지 만들었던 값들을 사용해 현재 원소를 추가했을 때의 식을 갱신한다.

이 때 현재 값을 2로 나누어가는 경우와 2를 곱해가는 경우를 탐색한다.

```cpp
int minOperations(vector<int>& nums, int sum) {
  int size = nums.size();

  vector<int> dp(sum + 1, INT_MAX);
  dp[0] = 0;
  for (int& num : nums) {
    vector<int> newDp(sum + 1, INT_MAX);
    if (num <= sum) newDp[num] = 0;

    for (int before = 0; before <= sum; before++) {
      if (dp[before] == INT_MAX) continue;
      newDp[before] = min(newDp[before], dp[before]);

      for (int cur = num, count = 0; cur >= 1; cur /= 2, count++) {
        if ((before + cur) > sum) continue;
        newDp[before + cur] = min(newDp[before + cur], dp[before] + count);
      }
      for (int cur = num, count = 0; cur <= sum; cur *= 2, count++) {
        if ((before + cur) > sum) break;
        newDp[before + cur] = min(newDp[before + cur], dp[before] + count);
      }
    }

    swap(dp, newDp);
  }

  return dp[sum] == INT_MAX ? -1 : dp[sum];
}
```

## 고생한 점
