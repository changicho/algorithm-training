# 4081. Prime Subset Selection II

[링크](https://leetcode.com/problems/prime-subset-selection-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 숫자를 N, 만들어야 하는 합을 S, N까지의 소수의 수를 P라 하자.

에라토스테네스의 채를 사용해 소수들을 구하는데 O(N \* log_2(log_2(N)))의 시간 복잡도를 사용한다.

이후 배낭문제와 같이 가능한 경우를 탐색하는데 O(SP), 결과에 따라 정답을 생성하는데 O(SP)의 시간 복잡도를 사용한다.

### 공간 복잡도

에라토스테네스의 체를 사용해 소수를 구하는데 O(N + P)의 시간 복잡도를 사용한다.

이후 동적 계획법을 사용할 경우 O(SP)의 공간 복잡도를 사용한다.

### 에라토스테네스의 체 & 배낭 문제

| 내 코드 (ms) |         시간 복잡도          |   공간 복잡도   |
| :----------: | :--------------------------: | :-------------: |
|     181      | O(N \* log_2(log_2(N)) + SP) | O(P \* (N + S)) |

에라토스테네스의 체를 이용해 N까지의 소수들을 구한다.

이후 배낭문제를 이용해 i번째 소수까지 이용했을 때 특정 합(S)를 만들 경우 필요한 최소 원소의 수를 동적 계획법에 저장한다.

이후 만들 수 있는 합을 최대한 큰 순서부터 순회하며 가능한 경우에 대해서 기존 동적 계획법 값을 이용해 소수 목록을 복원한다.

```cpp
vector<int> primes;

void init(int n) {
  vector<bool> isNotPrime(n + 1);

  for (int i = 2; i <= n; i++) {
    if (isNotPrime[i]) continue;
    primes.push_back(i);

    for (int j = i * i; j <= n; j += i) {
      isNotPrime[j] = true;
    }
  }
}

int dp[1001][1001] = {
    0,
};

int calc(int i, int sum) {
  if (sum == 0) return 0;
  if (i >= primes.size() || sum < 0) return INT_MAX;
  if (dp[i][sum] != -1) return dp[i][sum];

  // not choose
  int& ret = dp[i][sum];
  ret = calc(i + 1, sum);
  if (primes[i] <= sum) {
    // choose
    int take = calc(i + 1, sum - primes[i]);

    if (take != INT_MAX) {
      ret = min(ret, take + 1);
    }
  }
  return ret;
}

void build(int i, int sum, vector<int>& arr) {
  if (sum == 0 || i >= primes.size()) return;

  int need = calc(i, sum);

  if (primes[i] <= sum) {
    // choose
    int take = calc(i + 1, sum - primes[i]);

    if (take != INT_MAX && take + 1 == need) {
      arr.push_back(primes[i]);
      build(i + 1, sum - primes[i], arr);
      return;
    }
  }
  // not choose
  build(i + 1, sum, arr);
}

vector<int> maxPrimeSubset(int n, int s) {
  // prime
  init(n);

  memset(dp, -1, sizeof(dp));

  for (int sum = s; sum >= 0; sum--) {
    int cur = calc(0, sum);
    if (cur == INT_MAX) {
      continue;
    }

    vector<int> answer;
    build(0, sum, answer);

    return answer;
  }
  return {};
}
```

## 고생한 점
