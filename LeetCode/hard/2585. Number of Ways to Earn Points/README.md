# 2585. Number of Ways to Earn Points

[링크](https://leetcode.com/problems/number-of-ways-to-earn-points/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

types의 크기를 N, target을 M이라 하자. (N <= 50, M <= 10^3)

모든 경우를 직접 탐색할 경우 이는 매우 크므로 제한시간 내에 불가능하다.

만들 수 있는 값에 대해 탐색할 경우, 이전에 사용한 type들에 대한 정보를 같이 넘겨줘야 하므로 이를 모두 넘길 경우 O(2^N \* M)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

각 type에 대한 동적 계획법을 이용해 이전의 연산 결과를 재사용한다.

이 경우 현재까지에 대해 값을 갱신하는 데 O(M^2), 이를 총 N번 반복하므로 O(N \* M^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N \* M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     199      | O(N \* M^2) |  O(N \* M)  |

각 type에 대해 순회하며, 현재 type까지 사용할 수 있을 때의 각 점수에 대한 경우의 수를 구한다.

현재 type에 도달했을 때 각 점수에 대한 아래 두 가지 경우의 수를 더한다.

- 현재 type만 사용해 구성 가능한 경우
- 이전에 만든 결과에 현재 type을 더해 구성 가능한 경우

이 경우 다음과 같은 dp식을 생성할 수 있다.

```cpp
// definition
int dp[index][score]; // until index, case of make score

// initialize
dp[i][score] = 1; // if we can make score with only i type

// update
dp[i][score] = dp[i-1][score] + dp[i-1][score - diff] + // (for all diff) ...
```

즉 현재 type으로 만들 수 있는 점수들에 대해, 이전에 만들어진 경우의 수가 존재하는 경우 이를 더한다.

이를 구현하면 다음과 같다.

```cpp
const int MOD = 1e9 + 7;

int waysToReachTarget(int target, vector<vector<int>>& types) {
  // dp[index][score]; // until index, case of make score
  // dp[i][score] = dp[i-1][score] + dp[i-1][score - s] + (cur s count) ...

  int size = types.size();
  int dp[51][1001] = {
      0,
  };

  for (int i = 0; i < size; i++) {
    for (int score = 1; score <= target; score++) {
      int curMax = types[i][0] * types[i][1];

      if (score <= curMax && (score % types[i][1]) == 0) {
        dp[i][score] = 1;
      }

      // ignore invalid case
      for (int diff = 0; i - 1 >= 0 && diff <= min(curMax, score);
            diff += types[i][1]) {
        dp[i][score] += dp[i - 1][score - diff];
        dp[i][score] %= MOD;
      }
    }
  }

  return dp[size - 1][target];
}
```

## 고생한 점
