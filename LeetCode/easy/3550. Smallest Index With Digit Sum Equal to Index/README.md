# 3550. Smallest Index With Digit Sum Equal to Index

[링크](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 배열 안의 최대값을 M이라 하자.

각 값의 자리 수를 더하는데 O(log_10(M))의 시간 복잡도를 사용하며 이를 모든 수에 대해 수행할 경우 O(N \* log_10(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

덧셈에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      0       | O(N \* log_10(M)) |    O(1)     |

```cpp
int smallestIndex(vector<int>& nums) {
  int size = nums.size();
  for (int i = 0; i < size; i++) {
    int sum = 0;
    while (nums[i] > 0) {
      sum += nums[i] % 10;
      nums[i] /= 10;
    }
    if (sum == i) return i;
  }
  return -1;
}
```

## 고생한 점
