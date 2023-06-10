# 1150. Check If a Number Is Majority Element in a Sorted Array

[링크](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

nums는 정렬되어 있으므로 target의 수를 세는 데 이분탐색을 사용할 수 있다.

이 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

target의 수를 세는 데 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

upper_bound, lower_bound를 이용해 target의 수를 센다.

```cpp
bool isMajorityElement(vector<int>& nums, int target) {
  int count = upper_bound(nums.begin(), nums.end(), target) -
              lower_bound(nums.begin(), nums.end(), target);

  return count > (nums.size() / 2);
}
```

## 고생한 점
