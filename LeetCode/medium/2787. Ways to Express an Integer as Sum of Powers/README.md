# 2787. Ways to Express an Integer as Sum of Powers

[링크](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. (N <= 300)

동적 계획법을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도를 사용한다.

공간 최적화를 수행할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      21      |   O(N^2)    |    O(N)     |

다음과 같은 dp식을 생성한다.

```cpp
// 현재 숫자 num의 x제곱값을 사용했을 때 만들 수 있는 합을 다음과 같이 표현하자
long long val = pow(num, x);
long long dp[num][sum];

// 현재 val을 더했을 때 만들 수 있는 합의 경우의 수는 다음과 같이 표현할 수 있다.
dp[num][sum] = dp[num - 1][sum - val];

// base 초기 상태는 다음과 같다.
dp[0][0] = 1;
```

현재 숫자를 중복해서 사용할 수 없으므로, 현재 숫자의 x제곱값으로 특정 sum을 만들 수 있는 경우의 수를 이전 dp값으로 구할 수 있다.

이 때 매번 직전 값을 참조하므로 dp배열을 1차원으로 만들어 최적화 할 수 있다.

```cpp
int numberOfWays(int n, int x) {
  const long long MOD = 1e9 + 7;

  long long dp[301] = {
      0,
  };

  dp[0] = 1;
  for (long long num = 1; num <= n; num++) {
    long long val = pow(num, x);

    for (int sum = n; sum >= val; sum--) {
      dp[sum] += dp[sum - val];
      dp[sum] %= MOD;
    }
  }
  return dp[n];
}
```

## 고생한 점
