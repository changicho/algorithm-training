# 704. Binary Search

[링크](https://leetcode.com/problems/binary-search/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

배열은 정렬되어 있으므로 이분 탐색을 이용해 target이 존재하는지 여부를 알 수 있다.

이 경우 시간 복잡도는 O(log_2(N))이다.

### 공간 복잡도

별도의 공간 복잡도가 필요하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### upper_bound, lower_bound

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      | O(log_2(N)) |    O(1)     |

upper_bound는 x를 초과하는 첫번째 값의 위치를,

lower_bound는 x이상의 첫번째 값의 위치를 찾는다.

이를 이용해 x가 배열에 존재하는지 알 수 있다.

(upper_bound, lower_bound한 값이 같은 위치인 경우 x는 존재하지 않음)

```cpp
int search(vector<int>& nums, int target) {
  auto it = lower_bound(nums.begin(), nums.end(), target);

  if (*it == target) return it - nums.begin();

  return -1;
}
```

### binary search

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      | O(log_2(N)) |    O(1)     |

이분 탐색을 이용해 값을 구한다.

```cpp
int search(vector<int>& nums, int target) {
  int size = nums.size();
  int left = 0, right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) return mid;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}
```

## 고생한 점
