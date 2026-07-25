# 3536. Maximum Product of Two Digits

[링크](https://leetcode.com/problems/maximum-product-of-two-digits/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 자리수를 순회하는데 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 자리수 중 가장 큰 두 수를 찾아야한다.

이를 비교연산으로 찾을 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      3       | O(log_10(N)) |    O(1)     |

각 자리수를 순회하며 가장 큰 2개의 값을 찾고 해당 곱을 구한다.

```cpp
int maxProduct(int n) {
  int first = 0, second = 0;

  while (n > 0) {
    int cur = n % 10;
    n /= 10;

    if (cur > first) {
      second = first;
      first = cur;
    } else {
      second = max(cur, second);
    }
  }
  return first * second;
}
```

## 고생한 점
