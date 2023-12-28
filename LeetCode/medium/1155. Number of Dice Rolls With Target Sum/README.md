# 1155. Number of Dice Rolls With Target Sum

[링크](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N, K, T라 하자.

모든 경우를 직접 탐색하는 경우 시간 복잡도는 O(K^N) 이며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 중복 계산을 줄일 수 있다. 이 경우 O(N \* K \* T)의 시간 복잡도가 소요된다.

### 공간 복잡도

동적 계획법에 O(N \* T) 크기의 2차원 배열을 사용한다.

직전값에서만 갱신하므로 최적화 할 경우 O(T)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      14      | O(N \* K \* T) |  O(N \* T)  |

다음과 같은 dp 배열을 설정한다.

```cpp
dp[n][target]; // n개의 주사위를 사용했을 때 target을 만들 수 있는 경우의 수
```

n이 1일 때 1~K까지의 초기값은 1이다.

이후 현재 값을 갱신할 때 다음과 같이 계산할 수 있다.

- 현재 나온 주사위의 수를 cur, 이전에 나온 합 target을 before라 하자.
- 현재 cur + target을 만드는 경우의 수에 이전 target을 만드는 경우의 수를 더한다.
- 이 때 cur + target이 T보다 큰 경우는 무시한다.

이를 이용해 다음과 같이 구현할 수 있다.

```cpp
const int MOD = 1e9 + 7;

int numRollsToTarget(int n, int k, int target) {
  // n, k
  int dp[31][1001] = {
      0,
  };

  for (int i = 1; i <= k; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int cur = 1; cur <= k; cur++) {
      for (int before = 1; before <= target; before++) {
        if (cur + before > target) break;
        dp[i][cur + before] += dp[i - 1][before];
        dp[i][cur + before] %= MOD;
      }
    }
  }

  return dp[n][target];
}
```

## 고생한 점
