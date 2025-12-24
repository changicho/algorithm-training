# 1015. Smallest Integer Divisible by K

[링크](https://leetcode.com/problems/smallest-integer-divisible-by-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 K라 하자.

1로만 이루어진 숫자를 K자리까지 만들어가며 K로 나누어떨어지 판단한다.

이에 O(K)의 시간 복잡도를 사용한다.

### 공간 복잡도

K자리의 1로 구성된 숫자를 직접 숫자로 만들 경우 매우 커지므로 제한시간 내에 불가능하다.

나머지만 중요하므로 나머지 값만 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 나머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(K)     |    O(1)     |

1로만 구성된 숫자를 생성해가며 매번 K로 나누어떨어지는지 확인한다.

이후 다음 차례로 넘길 때 K로 나눈 나머지만 저장 후 넘긴다.

```cpp
int smallestRepunitDivByK(int k) {
  int cur = 0;
  for (int i = 1; i <= k; i++) {
    cur = (cur * 10 + 1) % k;
    if (cur == 0) return i;
  }
  return -1;
}
```

## 고생한 점
