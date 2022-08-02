# 461. Hamming Distance

[링크](https://leetcode.com/problems/hamming-distance/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 숫자 X, Y의 XOR값을 N이라 하자.

N의 비트들을 순회하며 1인 비트의 수를 센다.

이에 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

X, Y의 XOR한 값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### XOR

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       | O(log_2(N)) |    O(1)     |

해밍 거리는 두 문자열에서 다른 글자의 수를 세는것으로 나타낼 수 있다.

이 경우 다른 비트에 대해서 갯수를 세면 되므로 XOR을 사용한다.

```cpp
int hammingDistance(int x, int y) {
  int bits = x ^ y;

  int count = 0;
  while (bits > 0) {
    if (bits % 2 == 1) count++;
    bits /= 2;
  }
  return count;
}
```

## 고생한 점
