# 2320. Count Number of Ways to Place Houses

[링크](https://leetcode.com/problems/count-number-of-ways-to-place-houses/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

한쪽의 길이가 N일때의 가능한 배치의 갯수를 찾고, 이 수를 제곱한 수를 정답으로 반환한다.

이 때 길이가 N일때의 배치의 갯수를 동적 계획법을 이용해 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

윗쪽, 아랫쪽 두가지 경우가 존재하며, 한쪽에서 배치 가능한 경우의 수를 X라고 할 때, 윗쪽 배치와 아랫쪽 배치의 조합은 독립되므로 X^2가지 경우의 수가 발생한다.

따라서 한쪽에서 배치 가능한 경우의 수를 동적 계획법을 이용해 구한다.

이 경우 일반 식은 다음과 같다.

```cpp
// 정의
dp[i]; // 길이가 i일때의 경우의 수

// 일반식
dp[i] = dp[i - 2] + dp[i - 1];

// 초기값
dp[0] = 0;
dp[1] = 2;
dp[2] = 3;
```

각 과정마다 숫자가 매우 커질 수 있으므로 나머지 연산을 이용해 나눠준다.

이를 구현하면 다음과 같다.

```cpp
int countHousePlacements(int n) {
  int dp[10002] = {
      0,
  };

  dp[0] = 0;
  dp[1] = 2;
  dp[2] = 3;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
    dp[i] %= MOD;
  }

  long long target = dp[n];
  long long answer = (long long)dp[n] * dp[n];
  answer %= MOD;

  return answer;
}
```

## 고생한 점
