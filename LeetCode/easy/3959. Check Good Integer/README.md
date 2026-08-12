# 3959. Check Good Integer

[링크](https://leetcode.com/problems/check-good-integer/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 자리수별로 연산을 수행할 경우 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

연산에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(log_10(N)) |    O(1)     |

각 자리수별로 직접 연산을 수행한다.

이 때 중간과정에서 차이가 50이상 벌어지는 경우 더이상 탐색하지 않아도 된다.

```cpp
bool checkGoodInteger(int n) {
  long long a = 0, b = 0;

  while (n > 0) {
    int cur = n % 10;
    n /= 10;

    a += cur;
    b += cur * cur;

    if (b - a >= 50) return true;
  }

  return (b - a) >= 50;
}
```

## 고생한 점
