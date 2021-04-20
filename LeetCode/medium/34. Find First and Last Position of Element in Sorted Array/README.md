# 34. Find First and Last Position of Element in Sorted Array

[링크](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기는 최대 10^5 이다.

두가지 방법을 풀이가 가능하다

- 브루트포스 : O(N)
- upper_bound, lower_bound (이분 탐색) : O(log_2(N))

### 공간 복잡도

- 브루트 포스 : O(1)
- 이분 탐색 : O(1)

### 이분 탐색

> 4ms

upper_bound는 target보다 큰 숫자가 나타나는 최초의 위치를, lower_bound는 target이상의 숫자가 나타나는 최초의 위치를 반환한다.

정답이 없는 경우에는 두 경우 모두 같은 위치를 반환한다.

이를 이용해 찾고자 하는 숫자의 범위 from, to를 구할 수 있다.

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
  int from = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  int to = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

  if (from > to) {
    from = to = -1;
  }

  return {from, to};
}
```

### lower_bound, upper_bound 구현

직접 구현하는 경우 다음과 같다.

```cpp
int lower_bound(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size();

  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return right;
}

int upper_bound(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size();

  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return right;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
