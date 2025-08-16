# 326. Power of Three

[링크](https://leetcode.com/problems/power-of-three/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

순회를 이용해 N이 3의 제곱수인지 판단한다.

이에 O(log_3(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       | O(log_3(N)) |    O(1)     |

1부터 순회하며 3제곱이 N이 되는지 확인한다.

```cpp
bool isPowerOfThree(int n) {
  if (n <= 0) return false;

  for (long long cur = 1; cur <= INT_MAX; cur *= 3) {
    if (cur == n) return true;
  }
  return false;
}
```

## 고생한 점
