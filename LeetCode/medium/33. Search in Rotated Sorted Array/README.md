# 33. Search in Rotated Sorted Array

[링크](https://leetcode.com/problems/search-in-rotated-sorted-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums배열의 크기는 최대 5000이다. 브루트 포스 방법을 사용할 경우 시간 복잡도는 O(N)이다.

이분 탐색을 이용할 경우 시간 복잡도는 O(log_2(N)) 이다.

### 공간 복잡도

브루트 포스 방법을 사용할 경우 공간 복잡도는 별도의 공간이 필요하지 않아 O(1)이다.

이분 탐색을 사용할 경우에도 별도의 공간이 필요하지 않다.

### 이분 탐색

> 0ms

- 시간 복잡도 : O(log_2(N))
- 공간 복잡도 : O(1)

오름차순으로 정렬된 nums는 두 파트로 나눌 수 있다.

- A : x보다 큰 수부터 제일 큰 수까지 오름차순으로
- B : 제일 작은 수부터 x까지 오름차순으로 정렬되어있는 수열

따라서 nums는 다음과 같은 형식이다. A 파트 이후에 B파트가 연이어 나타나는 것으로 알 수 있다.

검색하려는 구간의 범위를 start ~ end로 나타낸다.

현재 방문한 숫자의 index가 mid이고, 찾으려는 숫자가 target이라고 할 때 다음의 경우가 존재한다.

mid = (start + end) / 2

- 현재 방문한 숫자가 target인 경우
- 현재 구간의 start에 있는 숫자가 mid에 있는 숫자 이하인 경우 (현재 구간에 A, B가 동시에 있지 않음)
  - 현재 방문한 숫자가 target 초과이고 start에 있는 숫자가 target 이하인 경우 (왼쪽구간에 정답)
  - 현재 방문한 숫자가 target 이하이거나 target이 start에 있는 숫자 초과인경우 (오른쪽 구간에 정답)
- 현재 구간의 start에 있는 숫자가 mid에 있는 숫자 초과인 경우 (현재 구간에 A, B가 동시에 있음)
  - 현재 방문한 숫자가 target 미만이고 end에 있는 숫자가 target 이상인 경우 (오른쪽구간에 정답)
  - 현재 방문한 숫자가 target 미만이거나 target이 end에 있는 숫자 초과인경우 (왼쪽 구간에 정답)

```cpp
int search(vector<int>& nums, int target) {
  int size = nums.size();

  int start = 0;
  int end = size - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (nums[mid] == target) return mid;
    if (nums[start] <= nums[mid]) {
      if (target < nums[mid] && nums[start] <= target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else {
      if (nums[mid] < target && target <= nums[end]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }

  return -1;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
