# 이항 계수 3

[링크](https://www.acmicpc.net/problem/11401)

| 난이도 |
| :----: |
| 골드 I |

## 설계

### 시간 복잡도

입력받은 수를 N, K라 하자. (N, K <= 4,000,000)

N이 매우 크므로 페르마의 소정리를 이용해 이항계수를 구한다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

페르마의 소정리를 이용해 이항계수를 구할 때 O(N)의 공간 복잡도가 소요된다.

### 페르마의 소정리 (이항계수)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

```cpp
typedef long long ll;

ll solution(int n, int k) {
  const int MOD = 1e9 + 7;
  vector<ll> factorial(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }

  function<ll(ll, ll)> myPow = [](ll base, ll expo) {
    ll result = 1;

    while (expo > 0) {
      if (expo % 2 == 1) {
        result *= base;
        result %= MOD;
      }
      base = (base * base) % MOD;
      expo /= 2;
    }
    return result;
  };

  function<ll(ll, ll)> combi = [&](ll n, ll k) {
    if (k > n || k < 0) return 0LL;
    if (k == 0 || k == n) return 1LL;

    ll numer = factorial[n] % MOD;
    ll denom = (factorial[k] * factorial[n - k]) % MOD;

    return numer * myPow(denom, MOD - 2) % MOD;
  };

  ll answer = combi(n, k);

  return answer;
}
```

## 고생한 점
