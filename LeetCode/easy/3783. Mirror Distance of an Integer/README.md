# 3783. Mirror Distance of an Integer

[링크](https://leetcode.com/problems/mirror-distance-of-an-integer/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

수를 변환하는데 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

수를 변환하는데 O(1)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(log_10(N)) |    O(1)     |

수를 변환 후 원본값과 차이를 구한다.

```cpp
int mirrorDistance(int n) {
  int origin = n;
  int r = 0;
  while (n > 0) {
    r = r * 10 + n % 10;
    n /= 10;
  }

  return abs(origin - r);
}
```

## 고생한 점
