# 2595. Number of Even and Odd Bits

[링크](https://leetcode.com/problems/number-of-even-and-odd-bits/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

N을 2진수로 표현할 경우 변환에 O(log_2(N))의 시간 복잡도를 사용한다.

이후 각 비트별로 count할 경우 순회에 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

별도로 2진수 변환한 공간을 사용할 경우 O(log_2(N))의 공간 복잡도를 사용한다.

변환과 동시에 count할 경우 O(1)의 공간 복잡도를 사용한다.

### 2진수 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

변환과 동시에 count를 수행한다.

```cpp
vector<int> evenOddBit(int n) {
  // even, odd
  vector<int> ans = {0, 0};

  int idx = 0;

  while (n > 0) {
    if (n % 2 == 1) {
      ans[idx % 2]++;
    }
    n /= 2;
    idx++;
  }
  return ans;
}
```

## 고생한 점
