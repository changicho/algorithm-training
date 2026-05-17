# 154. Find Minimum in Rotated Sorted Array II

[링크](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이분 탐색을 사용할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분탐색, 순회에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

[153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description)

위 문제와 유사하며 배열의 원소에 중복이 존재한다.

특정 구간 left ~ right에 대해서 mid = (left + right) / 2를 구한 뒤 다음을 판단한다.

`nums[mid]` 와 `nums[right]`를 비교하면 다음 3가지 경우가 생긴다.

- `nums[mid]` < `nums[right]` : mid ~ right 까지 정렬되어있으므로 왼쪽 구간을 선택
- `nums[mid]` > `nums[right]` : mid ~ right 구간이 정렬되어있지 않으므로 오른쪽 구간을 선택
- 같은 경우는 판단이 안되므로 right를 감소

```cpp
int findMin(vector<int>& nums) {
  int size = nums.size();

  int left = 0, right = size - 1;
  int answer = nums[0];
  while (left <= right) {
    int mid = left + (right - left) / 2;

    answer = min(answer, nums[mid]);
    if (nums[mid] < nums[right]) {
      right = mid;
    } else if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right -= 1;
    }
  }

  return answer;
}
```

## 고생한 점
