# 4039. Sum of Decoded Numbers

[링크](https://leetcode.com/problems/sum-of-decoded-numbers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 가장 큰 값을 M이라 하자.

특정 값에 대해서 구간별로 수를 분해하는데 O(log_10(M))의 시간 복잡도를 사용한다.

이후 pow연산을 수행하는 데 O(log_2(M))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* (log_2(M) + log_10(M))) 이다.

### 공간 복잡도

pow연산을 수행하는 데 O(log_2(M))의 시간 복잡도를 사용한다.

### custom pow

| 내 코드 (ms) |          시간 복잡도           | 공간 복잡도 |
| :----------: | :----------------------------: | :---------: |
|      75      | O(N \* (log_2(M) + log_10(M))) | O(log_2(M)) |

특정 수를 부위별로 분할하기 위해 log10과 pow연산을 이용해 몫과 나머지를 사용한다.

이후 두 수를 만든 경우 custom pow 함수를 구현해 각 값을 계산한다.

이 때 pow를 분할정복 기법으로 구현해 불필요한 연산을 줄인다.

```cpp
const int MOD = 1e9 + 7;

long long myPow(long long x, long long y) {
  if (y == 0) return 1LL;
  if (y == 1) return x;
  long long ret = 1;

  if (y % 2 == 1) {
    ret *= x;
    y--;
  }

  long long half = myPow(x, y / 2);

  ret *= half;
  ret %= MOD;
  ret *= half;
  ret %= MOD;

  return ret;
}

int sumDecoded(vector<long long>& nums) {
  long long answer = 0;

  for (long long& num : nums) {
    long long w = num % 10;
    long long d = num / 10;

    long long digit = pow(10, (int)log10(d) - (w - 1));

    long long x = d / digit;
    long long y = d % digit;

    answer += myPow(x, y);
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
