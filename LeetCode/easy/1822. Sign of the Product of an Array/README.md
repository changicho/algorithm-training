# 1822. Sign of the Product of an Array

[링크](https://leetcode.com/problems/sign-of-the-product-of-an-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

모든 원소를 순회하며 정답이 1, 0, -1이 되는 경우를 구한다.

순회에 O(N)의 시간 복잡도를 사용하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 배열을 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |    O(N)     |    O(1)     |

모든 원소를 순회하며 양수, 음수, 0인 경우에 대해서 곱한다.

이 때 절대값은 1으로만 곱한다.

```cpp
int arraySign(vector<int>& nums) {
  int ret = 1;

  for (int& n : nums) {
    if (n > 0) {
      ret *= 1;
    } else if (n < 0) {
      ret *= -1;
    } else {
      ret *= 0;
    }
  }

  return ret;
}
```

## 고생한 점
