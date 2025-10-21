# 2221. Find Triangular Sum of an Array

[링크](https://leetcode.com/problems/find-triangular-sum-of-an-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

시뮬레이션을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션에 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     343      |   O(N^2)    |    O(N)     |

각 경우마다 조건에 맞춰 현재 배열의 크기보다 1이 작은 새 배열을 만들고 이를 배열의 크기가 1이 될 때까지 반복한다.

이후 정답을 반환한다.

```cpp
int triangularSum(vector<int>& nums) {
  while (nums.size() > 1) {
    vector<int> arr;

    while (nums.size() > 1) {
      int cur = nums.back();
      nums.pop_back();
      arr.push_back((cur + nums.back()) % 10);
    }

    swap(nums, arr);
  }
  return nums.back();
}
```

## 고생한 점
