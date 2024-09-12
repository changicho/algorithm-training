# 2220. Minimum Bit Flips to Convert Number

[링크](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 수의 최대 값은 10^9 이다.

이를 2진수로 변환하는데 O(log_2(10^9))의 시간 복잡도를 사용하며 이는 O(1)이다.

두 수의 xor 연산을 구하고 이 값의 비트의 수를 세는데 O(1)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답에 O(1)의 공간 복잡도가 필요하다.

### 비트 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

두 수의 다른 비트의 수를 구해야 한다.

이를 위해 xor 연산을 수행한 뒤 이 값의 비트의 수를 센다.

```cpp
int minBitFlips(int start, int goal) {
  int bit = start ^ goal;

  return __builtin_popcount(bit);
}
```

## 고생한 점
