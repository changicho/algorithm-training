# 629. K Inverse Pairs Array

[링크](https://leetcode.com/problems/k-inverse-pairs-array/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 두 수를 N, K라 하자.

동적 계획법을 이용해 각 과정마다 직전의 값을 이용해 탐색 경우 O(N \* K)의 시간 복잡도를 사용한다.

각 과정마다 정답을 갱신할 때 순회를 사용할 경우 O(min(N, K))의 시간 복잡도를 사용하며 이 경우 최악의 경우 O(N \* K \* min(N, K))의 시간 복잡도를 사용한다.

이는 제한시간 내에 불가능하다.

직전 값을 이용해 계산할 경우 O(1)의 시간 복잡도로 갱신이 가능하다.

이 경우 총 O(N \* K)의 시간 복잡도가 소요된다.

### 공간 복잡도

동적 계획법에 사용할 dp배열을 선언해 사용할 경우 O(N \* K)의 공간 복잡도가 필요하다.

### 동적 계획법 (bottom up)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      19      |  O(N \* K)  |  O(N \* K)  |

함수의 인자 n, k에 대해서 현재 값에 대한 반환값은 닫음과 같이 구할 수 있다.

```cpp
int kInversePairs(int n, int k) {
  if (n == 0) return 0;
  if (k == 0) return 1;
  if (memo[n][k] != 0) return memo[n][k];

  int val = 0;
  for (int i = 0; i <= min(k, n - 1); i++){
    val += kInversePairs(n - 1, k - i);
    val %= MOD;
  }

  return memo[n][k] = val;
}
```

현재 값을 갱신하기 위해 k가 0 ~ k일 때 까지의 값을 이용해야 한다.

이를 매번 모두 탐색할 경우 시간 복잡도가 매우 커지므로 이전값을 이용해 이를 최적화 할 수 있다.

현재 n,k 쌍에 대해서 값을 구할 때 (n-1, 0~k) 까지의 합은 다음과 같이 구할 수 있다.

```cpp
int val = dp[n - 1][k];
if (k - n >= 0) val -= dp[n - 1][k - n];
```

즉 직전 값에서 이미 각 합들이 누적합으로 더해져 있으므로 이를 이용해 빠르게 구한다.

이를 이용해 다음과 같이 시간 복잡도를 최적화 해 구할 수 있다.

```cpp
int kInversePairs(int n, int k) {
  int dp[1001][1001] = {
      0,
  };

  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      int val = dp[i - 1][j];
      if (j - i >= 0) val -= dp[i - 1][j - i];

      val += MOD;
      val %= MOD;

      dp[i][j] = (dp[i][j - 1] + val) % MOD;
    }
  }

  int answer = dp[n][k];
  if (k > 0) answer -= dp[n][k - 1];
  answer += MOD;
  answer %= MOD;
  return answer;
}
```

## 고생한 점
