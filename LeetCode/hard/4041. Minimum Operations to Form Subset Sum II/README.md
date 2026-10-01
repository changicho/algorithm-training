# 4041. Minimum Operations to Form Subset Sum II

[링크](https://leetcode.com/problems/minimum-operations-to-form-subset-sum-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 크기를 N, 만들어야 하는 합을 S, 원소의 최대값을 M이라 하자.

배낭 문제(Knapsack)이므로 동적 계획법을 사용할 경우 O(N \* S)의 시간 복잡도를 기본적으로 사용한다.

이 때 각 과정마다 2로 나누고 곱하는 과정을 모두 탐색할 수 있다.

2로 나누는 경우의 수는 O(log_2(M)) 개 이며 여기서 2를 곱하는 모든 경우를 탐색하는데 O(log_2(S))의 시간 복잡도를 사용한다.

이는 O(log_2(M) \* log_2(S)) 이며 O(log_2(M + S))이다.

따라서 총 시간 복잡도는  O(N \* S \* log_2(M + S))이다.

### 공간 복잡도

동적 계획법에 O(S)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |        시간 복잡도        | 공간 복잡도 |
| :----------: | :-----------------------: | :---------: |
|     451      | O(N \* S \* log_2(M + S)) |    O(S)     |

[4040. Minimum Operations to Form Subset Sum I](https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/description/) 에서 조건이 추가된 문제

각 원소를 순회하며, 이전까지 만들었던 값들을 사용해 현재 원소를 추가했을 때의 식을 갱신한다.

이 때 현재 원소를 2로 나눈 경우마다 다시 2를 곱해갈 경우 새로운 값을 만들 수 있다.

이 경우들을 모두 탐색해 최소 비용을 갱신한다.

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

      for (int desc = num, count = 0; desc >= 1; desc >>= 1, count++) {
        if ((before + desc) > sum) continue;
        newDp[before + desc] = min(newDp[before + desc], dp[before] + count);

        for (int inc = desc, incCount = count; inc <= sum; inc <<= 1, incCount++) {
          if ((before + inc) > sum) break;
          newDp[before + inc] = min(newDp[before + inc], dp[before] + incCount);
        }
      }
    }

    swap(dp, newDp);
  }

  return dp[sum] == INT_MAX ? -1 : dp[sum];
}
```

## 고생한 점
