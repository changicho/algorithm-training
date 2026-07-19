# 1979. Find Greatest Common Divisor of Array

[링크](https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

순회하며 최대, 최소값을 찾은 뒤 gcd를 구하는데 O(N + log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

최대, 최소값 및 gcd를 구하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      0       | O(N + log_2(M)) |    O(1)     |

```cpp
int findGCD(vector<int>& nums) {
  int minimum = nums[0];
  int maximum = nums[0];

  for (int& num : nums) {
    minimum = min(minimum, num);
    maximum = max(maximum, num);
  }

  return gcd(maximum, minimum);
}
```

## 고생한 점
