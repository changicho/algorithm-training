# 3754. Concatenate Non-Zero Digits and Multiply by Sum I

[링크](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 수를 변환 후 계산하는데 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수의 변환에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(log_10(N)) |    O(1)     |

주어진 조건에 맞춰 수를 변환한다.

```cpp
long long sumAndMultiply(int n) {
  long long answer = 0;

  int sum = 0;
  int remain = 0;
  int digit = 1;

  while (n > 0) {
    int cur = n % 10;
    sum += cur;
    n /= 10;

    if (cur > 0) {
      remain += cur * digit;
      digit *= 10;
    }
  }

  return 1LL * sum * remain;
}
```

## 고생한 점
