# 1259. Handshakes That Don't Cross

[링크](https://leetcode.com/problems/handshakes-that-dont-cross/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. (N <= 10^3)

모든 경우를 셀 경우 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전 값으로 현재 값을 구할 수 있다.

이 경우 현재 값을 갱신하는데 O(N), 모든 값을 순회하는데 O(N)의 시간 복잡도를 사용한다.

따라서 총 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |   O(N^2)    |    O(N)     |

두 인원 A, B가 존재한다고 하자.

모든 인원은 원형 형태로 존재하며, A와 B가 악수할 경우 A와 B를 연결하는 선으로 인원을 2부분으로 나눌 수 있다.

이 때 남은 각 인원들끼리 악수할 때 손이 꼬이지 않게 악수하는 경우의 수가 존재한다.

이 두 경우의 수를 곱한 값이 현재 A, B의 악수 관계에 대한 경우의 수이다.

여기서 A, B가 악수하는 방법에 따라 두 부분의 인원의 수에 차이가 발생한다. 인원을 나누는 모든 경우의 수를 더한 값이 현재 가능한 경우의 수가 된다.

```cpp
int MOD = 1e9 + 7;

int numberOfWays(int numPeople) {
  // dp[num/2] : number of ways to handshake with num people
  int dp[501] = {
      0,
  };
  dp[0] = 1;

  for (int num = 1; num <= numPeople / 2; num++) {
    for (int left = 0; left < num; left++) {
      int right = num - left - 1;
      dp[num] += (long long)dp[left] * dp[right] % MOD;
      dp[num] %= MOD;
    }
  }

  return dp[numPeople / 2];
}
```

## 고생한 점
