# 69. Sqrt(x)

[링크](https://leetcode.com/problems/sqrtx/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

x의 최대값은 2^31 - 1 이다.

직접 i를 증가시키며 수행할 경우, 최대값의 루트인 46341번 까지 수행해야 한다.

이분 탐색으로 탐색할 경우 31번 내에 수행 가능하다.

### 공간 복잡도

숫자는 int형으로만 주어진다. 제곱 후 연산시 int형 범위를 벗어나지 않도록 주의한다.

### 이분 탐색

정확한 소수를 구하지 않아도 되므로 이분 탐색을 통해 구현할 수 있다.

```cpp
int mySqrt(int x) {
  int start = 0;
  int end = 46341;

  while (start + 1 < end) {
    int mid = (start + end) / 2;
    int cur = mid * mid;

    if (cur > x) {
      end = mid;
    } else {
      start = mid;
    }
  }

  return start;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
