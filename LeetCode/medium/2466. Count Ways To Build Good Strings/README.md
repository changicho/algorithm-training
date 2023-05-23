# 2466. Count Ways To Build Good Strings

[링크](https://leetcode.com/problems/count-ways-to-build-good-strings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 high를 N이라 하자.

동적 계획법을 이용해 각 경우마다 0을 붙일때, 1을 붙일 때의 경우의 수를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(N)     |

각 경우마다 맨 뒤에 0, 1을 붙일 수 있다.

따라서 현재 길이에 대해, 뒤에 0을 붙일 때, 1을 붙일 때의 경우의 수를 갱신한다.

이후 low ~ high 까지의 경우의 수를 더한다.

```cpp
int countGoodStrings(int low, int high, int zero, int one) {
  int dp[100001] = {
      0,
  };

  dp[zero] += 1;
  dp[one] += 1;

  for (int i = 1; i <= high; i++) {
    if (i + zero <= high) {
      dp[i + zero] += dp[i];
      dp[i + zero] %= MOD;
    }
    if (i + one <= high) {
      dp[i + one] += dp[i];
      dp[i + one] %= MOD;
    }
  }

  int answer = 0;
  for (int i = low; i <= high; i++) {
    answer += dp[i];
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
