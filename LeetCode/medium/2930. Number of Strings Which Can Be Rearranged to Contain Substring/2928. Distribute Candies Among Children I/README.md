# 2930. Number of Strings Which Can Be Rearranged to Contain Substring

[링크](https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

조합의 경우를 고려해 직접 제곱수를 구하며 풀이할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 제곱을 구현해 정답에 더할 경우 별도의 배열을 사용하지 않는다. O(1)의 공간 복잡도를 사용한다.

### 조합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(log_2(N)) |    O(1)     |

다음 4가지 경우가 존재한다.

- C1 = 0 L (no L present in whole string)
- C2 = 0 T (no T present in whole string)
- C3 = 0 E (no E present in whole string)
- C4 = 1 E (only 1 E present in whole string)

위 경우들은 문제의 정답을 충족하지 못하게 하는 경우이다.

여기서 문제에 주어진 경우를 만족하지 못하는 경우의 수를 구하는 식은 아래와 같다.

singletons − pairs + triplets − quadruples

따라서 위 표현을 실제 식으로 나타낼 경우 아래와 같다.

- badCase : (n+75) \* 25^(n−1) - (2n+72) \* 24^(n−1) + (n+23) \* 23^(n−1)

위 값을 실제 모든 경우의 수에서 뺼 경우 정답을 구할 수 있다.

- goodCase = 26^n - badCase

위 식을 토대로 직접 값을 구할 경우 아래와 같다.

```cpp
const int MOD = 1e9 + 7;

long pow(long x, long n) {
  long result = 1, p = x % MOD;

  while (n) {
    if (n % 2 == 1) {
      result = (result * p) % MOD;
    }
    p = (p * p) % MOD;
    n /= 2;
  }
  return result;
}

int stringCount(int n) {
  long long count = 0;

  count += pow(26, n);
  count %= MOD;

  count -= (n + 75) * pow(25, n - 1);
  count %= MOD;

  count += (2 * n + 72) * pow(24, n - 1);
  count %= MOD;

  count -= (n + 23) * pow(23, n - 1);
  count %= MOD;

  count += MOD;
  count %= MOD;

  return count;
}
```

## 고생한 점
