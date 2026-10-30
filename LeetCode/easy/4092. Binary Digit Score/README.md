# 4092. Binary Digit Score

[링크](https://leetcode.com/problems/binary-digit-score/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 수를 A, B라 하자.

각 수의 비트를 세는 데 O(32)의 시간 복잡도를 사용한다. 이를 이용해 정답을 구할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수의 비트갯수를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 비트 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

```cpp
int calculateScore(int a, int b) {
  int d1 = __builtin_popcount(a);
  int d2 = __builtin_popcount(b);
  if (d1 >= d2) return d1 * d2;
  return d2 / d1;
}
```

## 고생한 점
