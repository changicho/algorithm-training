# B - Fibonacci Reversed

[링크](https://atcoder.jp/contests/abc421/tasks/abc421_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 수의 최대값을 N이라 하자.

10번째 숫자까지 순회하는데 O(1)의 시간 복잡도를 사용한다.

각 과정에서 자리수를 뒤집는데 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 과정에서 현재값과 직전값을 저장하므로 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      1       | O(log_10(N)) |    O(1)     |

```cpp
long long convert(long long num) {
  long long ret = 0;
  while (num > 0) {
    ret *= 10;
    ret += num % 10;
    num /= 10;
  }
  return ret;
}

auto solution(long long x, long long y) {
  long long before = x;
  long long cur = y;

  for (long long i = 3; i <= 10; i++) {
    long long temp = convert(before + cur);
    before = cur;
    cur = temp;
  }

  return cur;
}
```

## 고생한 점
