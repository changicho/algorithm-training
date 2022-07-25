# Maximum Gain (7pts, 11pts)

[링크](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caea6/0000000000b76fae)

## 설계

### 시간 복잡도

배열 A의 크기를 N, B의 크기를 M이라하자.

K개의 숫자를 골랐을 때 최적의 값을 찾기 위해 동적 계획법을 사용할 수 있다.

이 경우 A와 B에 대해 동적 계획법을 이용해 최적의 경우를 구할 경우 O(N^2 + M^2)의 시간 복잡도를 사용한다.

이후 K에 대해 순회하며 A, B에서 고르는 갯수를 순회할 경우 O(K)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^2 + M^2 + K)이다.

### 공간 복잡도

A, B에 대해 동적 계획법을 사용할 경우 O(N + M)의 공간 복잡도를 사용한다.

### 동적 계획법

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(N^2 + M^2 + K) |  O(N + M)   |

K개의 수 중에서 A에서 고르는 수를 x라고 할 경우 B에서 고르는 갯수는 K-x가 된다.

따라서 A, B에서 x개를 골랐을 때 가장 큰 점수를 미리 계산해 놓을 경우 x에 대해 순회해 정답을 구할 수 있다.

A, B에서 x개를 골랐을 때의 최대값은 dp를 이용할 수 있다.

배열 A에 대해서 다음과 같은 dp값을 사용한다고 하자.

```cpp
// definition
long long dp[n];  // n개의 값을 골랐을 때 최대 점수

// init
dp[0] = 0;

// update
for (int left = 0; left <= i; left++) {
  int right = i - left;
  long long cur = pickLeftN[left] + pickRightN[right];

  dp[i] = max(dp[i], cur);
}
```

x개의 값을 골랐을 때 현재 dp값은 이 또한 왼쪽, 오른쪽에서 합쳐서 x개를 고르는 경우 중 최대값이 된다.

따라서 배열의 길이를 N이라고 했을 때 dp값을 갱신하는 데 시간 복잡도는 O(N^2)가 된다.

여기서 pickLeftN, pickRightN을 빠르게 구하기 위해 prefixSum을 사용한다. 이 경우 O(1)의 시간복잡도로 구할 수 있다.

이를 A, B에 대해서 모든 dp값을 구하고 K에 대해서 순회하며 정답을 갱신한다.

이 때 x, (K-x)개를 각각 A, B에서 고를 때 최대 갯수를 넘는 경우에 주의한다.

```cpp
long long solution(int n, int m, vector<int>& a, vector<int>& b, int k) {
  long long answer = 0;

  vector<long long> prefix1(n + 1, 0);
  vector<long long> dp1(n + 1, 0);  // pick n number, maximum val
  for (int i = 0; i < n; i++) {
    prefix1[i + 1] = prefix1[i] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int left = 0; left <= i; left++) {
      int right = i - left;
      long long cur = prefix1[left] + (prefix1[n] - prefix1[n - (right)]);

      dp1[i] = max(dp1[i], cur);
    }
  }

  vector<long long> prefix2(m + 1, 0);
  vector<long long> dp2(m + 1, 0);  // pick m number, maximum val
  for (int i = 0; i < m; i++) {
    prefix2[i + 1] = prefix2[i] + b[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int left = 0; left <= i; left++) {
      int right = i - left;
      long long cur = prefix2[left] + (prefix2[m] - prefix2[m - (right)]);

      dp2[i] = max(dp2[i], cur);
    }
  }

  for (int i = 0; i <= k; i++) {
    if (i > n) continue;
    if (k - i > m) continue;
    long long cur = dp1[i] + dp2[k - i];

    answer = max(answer, cur);
  }

  return answer;
}
```

## 고생한 점
