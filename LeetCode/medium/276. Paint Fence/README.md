# 276. Paint Fence

[링크](https://leetcode.com/problems/paint-fence/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

울타리의 수를 N, 색상의 수를 K라고 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(K^N)이 되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 이전 값을 재사용해 시간복잡도를 줄인다.

이 경우 시간 복잡도는 울타리의 수 만큼 탐색을 지속한 값이 된다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

울타리의 개수별 값을 모두 저장할 경우 공간 복잡도는 O(N)이다.

현재 값을 갱신할 때 필요한 값은 1단계 전, 2단계 전 값이다.

따라서 총 3단계의 값만 사용할 경우 공간 복잡도는 O(1)이다.

### bottom-up

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

k가 주어진 상황에서 n에 따라 경우의 수를 찾는 함수를 f(n)라 하자.

n = 1 일 경우 경우의 수는 k이다.

n = 2 일 경우 경우의 수는 k^2이다.

n = 3일 경우 n = 2, n = 1일때의 값을 이용해 구할 수 있다.

n = 2인 직전에 쓴 color 하나를 제외한 값 만큼 경우의 수가 발생하므로 (k - 1) \* f(n - 1)이 된다.

또한 n = 1인 상황에서도 마찬가지로 직전에 쓴 color 하나를 제외한 값만큼 경우의 수가 발생하므로 (k - 1) \* f(n - 2)가 된다.

(n-1번째 색이 1이라고 할 때 현재 가능한 경우는 x10이고 n-2번째 색이 1이라고 할 경우 현재 가능한 경우는 1x0이기 때문)

따라서 일반식은 다음과 같다.

```cpp
dp[n] = (k - 1) * (dp[n - 1] + dp[n-2]);
```

초기값은 다음과 같다.

```cpp
dp[1] = k;
dp[2] = k^2;
```

따라서 정답은 다음과 같다.

```cpp
int numWays(int n, int k) {
  if (n == 1) return k;
  if (n == 2) return k * k;

  vector<int> dp(n + 1);
  dp[1] = k;
  dp[2] = k * k;

  for (int i = 3; i <= n; i++) {
    dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
  }
  return dp[n];
}
```

여기서 1번째 전 값, 2번째 전 값만을 사용하므로 다음과 같이 공간 복잡도를 최적화 할 수 있다.

```cpp
int numWays(int n, int k) {
  if (n == 1) return k;
  if (n == 2) return k * k;

  int dp[3] = {
      k,
      k * k,
  };

  for (int i = 3; i <= n; i++) {
    dp[2] = (k - 1) * (dp[1] + dp[0]);
    dp[0] = dp[1];
    dp[1] = dp[2];
  }
  return dp[2];
}
```

### top-down

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

이를 재귀호출로 top-down방식으로 구할 경우 다음과 같다.

```cpp
unordered_map<int, int> dp;

int recursive(int i, int k) {
  if (i == 1) return k;
  if (i == 2) return k * k;

  if (dp.find(i) != dp.end()) {
    return dp[i];
  }

  return dp[i] = (k - 1) * (recursive(i - 1, k) + recursive(i - 2, k));
}

int numWays(int n, int k) {
  return recursive(n, k);
}
```

## 고생한 점
