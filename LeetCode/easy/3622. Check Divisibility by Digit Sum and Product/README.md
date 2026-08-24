# 3622. Check Divisibility by Digit Sum and Product

[링크](https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. 각 자리수를 순회하는데 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 자리수의 합과 곱을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(log_10(N)) |    O(1)     |

```cpp
bool checkDivisibility(int n) {
  int origin = n;
  int sum = 0;
  int multi = 1;

  while (n > 0) {
    int cur = n % 10;

    sum += cur;
    multi *= cur;

    n /= 10;
  }

  int target = sum + multi;

  return origin % target == 0;
}
```

## 고생한 점
