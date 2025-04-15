# 1922. Count Good Numbers

[링크](https://leetcode.com/problems/count-good-numbers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. N은 최대 10^15 이다.

문제의 짝수부와 홀수부의 갯수를 센 뒤 분할 정복을 이용해 제곱을 빠르게 구할 수 있다.

이 경우 시간 복잡도는 O(log_2(N)) 이다.

### 공간 복잡도

재귀 호출로 구현할 경우 O(log_2(N)) 의 공간 복잡도를 가진다.

순회로 구할 경우 O(1) 의 공간 복잡도를 가진다.

### 분할 정복 (순회)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

N자리 숫자를 만들 때 홀수부와 짝수부의 갯수를 셀 수 있다. (짝수, 홀수 index의 갯수)

짝수는 5가지, 홀수는 4가지 의 숫자를 가질 수 있다.

따라서 정답은 다음과 같다.

- 짝수부의 갯수 : E
- 홀수부의 갯수 : O
- 5^E \* 4^O가지 경우의 수가 가능

이 때 제곱의 수가 매우 크므로 분할 정복을 이용해 정답을 빠르게 구한다.

```cpp
const int MOD = 1e9 + 7;

int myPow(int a, long long b) {
  int ret = 1, mul = a;
  while (b > 0) {
    if (b % 2 == 1) {
      ret = (long long)ret * mul % MOD;
    }
    mul = (long long)mul * mul % MOD;
    b /= 2;
  }
  return ret;
}

int countGoodNumbers(long long n) {
  int even = 5, odd = 4;

  long long evenCount = (n / 2) + n % 2, oddCount = n / 2;

  long long answer = 1;
  answer *= myPow(5, evenCount);
  answer %= MOD;

  answer *= myPow(4, oddCount);
  answer %= MOD;

  return answer;
}
```

## 고생한 점
