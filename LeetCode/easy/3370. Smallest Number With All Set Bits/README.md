# 3370. Smallest Number With All Set Bits

[링크](https://leetcode.com/problems/smallest-number-with-all-set-bits/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 비트를 추가하면서 비교하는데 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

```cpp
int smallestNumber(int n) {
  int cur = 1;
  while (cur < n) {
    cur = (cur << 1) + 1;
  }

  return cur;
}
```

## 고생한 점
