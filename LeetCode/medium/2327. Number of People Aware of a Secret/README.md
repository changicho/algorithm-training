# 2327. Number of People Aware of a Secret

[링크](https://leetcode.com/problems/number-of-people-aware-of-a-secret/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

주어진 날짜를 N이라 하자.

동적 계획법을 이용해 1일부터 N번째 날짜까지 순회하며 비밀을 아는 사람을 계산할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 날짜마다의 dp값을 저장하는 경우 O(N)의 공간 복잡도를 사용한다.

dp에서 계산할 때 forget값까지만 필요하다. 따라서 필요한 값만을 사용할 경우 O(forget)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

dp값을 다음과 같이 정의한다.

```cpp
// definition
dp[i]; // the number of people who found the secret on i day
share = 0 // current people can share password

// update
share = (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + MOD) % MOD;
dp[i] = share

// init
dp[1] = 1;
share = 0;
```

현재 다른 인원에게 비밀번호를 알려줄 수 있는 인원과 dp값을 이용한다.

이후 N번째 날의 비밀번호를 아는 인원의 총 수를 구해야 하므로 (i - forget + 1) ~ N일 까지의 아는 인원을 모두 구한다.

```cpp
int peopleAwareOfSecret(int n, int delay, int forget) {
  // the number of people who found the secret on i day
  vector<long> dp(n + 1);
  dp[1] = 1;

  int share = 0, answer = 0;
  for (int i = 2; i <= n; i++) {
    share =
        (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + MOD) % MOD;
    dp[i] = share;
  }

  for (int i = n - forget + 1; i <= n; i++) {
    answer = (answer + dp[i]) % MOD;
  }
  return answer;
}
```

## 고생한 점
