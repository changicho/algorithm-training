# 33. Search in Rotated Sorted Array

[링크](https://leetcode.com/problems/search-in-rotated-sorted-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums배열의 크기를 N이라 하자. N은 최대 5000이다.

브루트 포스 방법을 사용할 경우 시간 복잡도는 O(N)이다.

배열이 정렬 되어있으므로 이분 탐색을 이용할 수 있다.

이 경우 시간 복잡도는 O(log_2(N)) 이다.

### 공간 복잡도

브루트 포스 방법을 사용할 경우 공간 복잡도는 별도의 공간이 필요하지 않아 O(1)이다.

이분 탐색을 사용할 경우에도 별도의 공간이 필요하지 않다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     0ms      | O(log_2(N)) |    O(1)     |

오름차순으로 정렬된 nums는 두 파트로 나눌 수 있다.

```javascript
nums = [...B, ...A];

sorted = [...A, ...B];
```

- A : x보다 큰 수부터 제일 큰 수까지 오름차순으로
- B : 제일 작은 수부터 x까지 오름차순으로 정렬되어있는 수열

검색하려는 구간의 범위를 left ~ right로 나타낸다.

현재 숫자의 index가 mid이고, 찾으려는 숫자가 target이라고 할 때 다음의 경우가 존재한다.

mid = (left + right) / 2

- 현재 숫자가 target인 경우
- left ~ mid까지 정렬된 경우
  - left < target < mid 구조인 경우 (왼쪽 구간에 정답)
  - left < mid < target 구조인 경우 (오른쪽 구간에 정답)
- left ~ mid까지 정렬되지 않은경우 (left > mid)
  - mid < target < right 구조인 경우 (오른쪽 구간에 정답)
  - target < mid, right < target인 경우 (왼쪽 구간에 정답)

이를 이용해 이분 탐색을 적용할 수 있다.

```cpp
int search(vector<int>& nums, int target) {
  int size = nums.size();

  int left = 0, right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) return mid;

    // left ~ mid is sorted
    if (nums[left] <= nums[mid]) {
      if (target < nums[mid] && nums[left] <= target) {
        // pick left part
        right = mid - 1;
      } else {
        // pick right part
        left = mid + 1;
      }
    } else {
      if (nums[mid] < target && target <= nums[right]) {
        // pick right part
        left = mid + 1;
      } else {
        // pick left part
        right = mid - 1;
      }
    }
  }

  return -1;
}
```

## 고생한 점
