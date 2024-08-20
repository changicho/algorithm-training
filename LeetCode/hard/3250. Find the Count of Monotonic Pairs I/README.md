# 3250. Find the Count of Monotonic Pairs I

[링크](https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

nums의 각 원소의 값은 0 ~ 50 이다.

동적 계획법을 이용해 현재 값과 직전 값에 대해 탐색할 경우 시간 복잡도는 O(N \* 50^2) 이다.

이는 O(N)이다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      73      |    O(N)     |    O(N)     |

현재 index에 대해서 nums의 값을 num, 오름차순 배열의 값이 cur라 하자.

cur이 고정된 경우 현재 내림차순 배열의 값은 num - cur 이다.

직전 오름차순 배열의 값을 before라 하자. 이 또한 내림차순 배열의 값을 구할 수 있다.

따라서 cur과 before에 대해 탐색하며 현재 index와 cur에 대한 값을 갱신한다.

```cpp
const int MOD = 1e9 + 7;

int countOfPairs(vector<int>& nums) {
  int size = nums.size();
  // [index][cur]
  int dp[2001][51] = {
      0,
  };

  for (int cur = 0; cur <= nums[0]; cur++) {
    dp[0][cur] = 1;
  }

  for (int i = 1; i < size; i++) {
    for (int before = 0; before <= nums[i - 1]; before++) {
      int beforeDesc = nums[i - 1] - before;

      if (dp[i - 1][before] == 0) continue;

      for (int cur = before; cur <= nums[i]; cur++) {
        int curDesc = nums[i] - cur;

        if (beforeDesc < curDesc) continue;
        dp[i][cur] += dp[i - 1][before];
        dp[i][cur] %= MOD;
      }
    }
  }

  int answer = 0;
  for (int first = 0; first <= nums[size - 1]; first++) {
    answer += dp[size - 1][first];
    answer %= MOD;
  }
  return answer;
}
```

## 고생한 점
