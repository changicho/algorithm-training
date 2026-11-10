# 3693. Climbing Stairs II

[링크](https://leetcode.com/problems/climbing-stairs-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

동적 계획법을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 index에 대해 동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

연이은 4개의 값에 대한 dp만 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

각 index에서 다음 +1, +2, +3에 대한 동적 계획법 값을 갱신한다.

이후 이를 0부터 순차적으로 순회하며 답을 갱신 후 마지막 n번째 값을 반환한다.

```cpp
int climbStairs(int n, vector<int>& costs) {
  int dp[4] = {0, INT_MAX, INT_MAX, INT_MAX};

  int answer = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      if (i + j > n) break;

      int diff = j * j;
      dp[j] = min(dp[j], dp[0] + costs[i + j - 1] + diff);
    }

    if (i == n) return dp[0];

    // shift
    for (int i = 0; i <= 2; i++) {
      dp[i] = dp[i + 1];
    }
    dp[3] = INT_MAX;
  }

  return -1;
}
```

## 고생한 점
