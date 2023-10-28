# 1220. Count Vowels Permutation

[링크](https://leetcode.com/problems/count-vowels-permutation/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

모든 경우를 직접 구할 경우 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 이전 경우에서 다음 경우를 구할 수 있다.

이 때 시간 복잡도는 O(N)이다.

### 공간 복잡도

직전 dp값만 필요하므로 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

각 알파벳마다 직전 알파벳에서 현재 알파벳으로 오는 경우는 고정되어있다.

따라서 현재 알파벳으로 끝나는 경우의 수를 구할 때 다음과 같이 구할 수 있다.

- 현재 알파벳을 붙일 수 있는 이전 경우의 수를 모두 더한다.

각 알파벳을 끝자리로 하는 경우의 수를 dp로 설정하고 이를 N번 반복한다.

```cpp
int countVowelPermutation(int n) {
  int dp[5] = {0};
  for (int i = 0; i < 5; i++) {
    dp[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    // a e i o u
    int newDp[5] = {
        0,
    };

    // a
    newDp[0] += dp[1];
    newDp[0] %= MOD;

    // e
    newDp[1] += dp[0];
    newDp[1] %= MOD;
    newDp[1] += dp[2];
    newDp[1] %= MOD;

    // i
    newDp[2] += dp[0];
    newDp[2] %= MOD;
    newDp[2] += dp[1];
    newDp[2] %= MOD;
    newDp[2] += dp[3];
    newDp[2] %= MOD;
    newDp[2] += dp[4];
    newDp[2] %= MOD;

    // o
    newDp[3] += dp[2];
    newDp[3] %= MOD;
    newDp[3] += dp[4];
    newDp[3] %= MOD;

    // u
    newDp[4] += dp[0];
    newDp[4] %= MOD;

    for (int j = 0; j < 5; j++) {
      dp[j] = newDp[j];
    }
  }

  int answer = 0;
  for (int i = 0; i < 5; i++) {
    answer += dp[i];
    answer %= MOD;
  }
  return answer;
}
```

## 고생한 점
