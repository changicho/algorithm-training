# 3345. Smallest Divisible Digit Product I

[링크](https://leetcode.com/problems/smallest-divisible-digit-product-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 수를 N, T라 하자.

N부터 값을 증가시키며 만족하는 수를 찾는 완전 탐색을 수행할 수 있다.

이 경우 O(N \* log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 과정마다 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      0       | O(N \* log_10(N)) |    O(1)     |

```cpp
int convert(int num) {
  int ret = 1;
  while (num > 0 && ret > 0) {
    ret *= num % 10;
    num /= 10;
  }
  return ret;
}

int smallestNumber(int n, int t) {
  int num = n;
  while (true) {
    int c = convert(num);

    if (c % t == 0) break;

    num++;
  }
  return num;
}
```

## 고생한 점
