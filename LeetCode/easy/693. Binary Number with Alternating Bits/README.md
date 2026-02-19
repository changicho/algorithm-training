# 693. Binary Number with Alternating Bits

[링크](https://leetcode.com/problems/binary-number-with-alternating-bits/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

비트별로 순회하며 이전 비트와 비교할 경우 O(log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

비교에 필요한 변수만 사용할 경우 O(1)의 공간 복잡도를 가진다.

### 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

직전 비트와 현재 비트를 비교하며 순회한다.

값이 다른 경우 다음 비트로 넘어가고, 값이 같은 경우 false를 반환한다.

```cpp
bool hasAlternatingBits(int n) {
  bool before = n % 2;
  n /= 2;

  while (n > 0) {
    bool cur = n % 2;
    n /= 2;

    if (before == cur) return false;
    before = cur;
  }
  return true;
}
```

## 고생한 점
