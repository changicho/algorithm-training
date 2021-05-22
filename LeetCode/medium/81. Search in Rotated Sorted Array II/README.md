# 81. Search in Rotated Sorted Array II

[링크](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 수를 탐색할 경우 시간 복잡도는 O(N)이 소요된다.

이분 탐색을 이용할 경우 가장 좋은 경우 O(log_2(N))의 시간 복잡도가 필요하다.

최악의 경우는 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

이분탐색, 브루트 포스 모든 경우 상수만큼의 공간이 필요하므로 공간 복잡도는 O(1)이다.

### 이분 탐색 중복 제거

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      0       | O(N), O(log_2(N)) |    O(1)     |

오름차순으로 정렬된 nums는 두 파트로 나눌 수 있다.

- A : 제일 작은 수부터 x까지 오름차순으로 정렬되어있는 수열
- B : x보다 큰 수부터 제일 큰 수까지 오름차순으로

따라서 nums는 다음과 같은 형식이다.

```javascript
[...B, ...A];
```

검색하려는 구간의 범위를 left ~ right로 나타낸다.

현재 방문한 숫자의 index가 mid이고, 찾으려는 숫자가 target이라고 할 때 다음의 경우가 존재한다.

mid = (left + right) / 2

- 현재 방문한 숫자가 target인 경우
- 현재 구간의 left에 있는 숫자가 mid에 있는 숫자 이하인 경우 (현재 구간에 A, B가 동시에 있지 않음)
  - 현재 방문한 숫자가 target 초과이고 left에 있는 숫자가 target 이하인 경우 (왼쪽구간에 정답)
  - 현재 방문한 숫자가 target 이하이거나 target이 left에 있는 숫자 초과인경우 (오른쪽 구간에 정답)
- 현재 구간의 left에 있는 숫자가 mid에 있는 숫자 초과인 경우 (현재 구간에 A, B가 동시에 있음)
  - 현재 방문한 숫자가 target 미만이고 right에 있는 숫자가 target 이상인 경우 (오른쪽구간에 정답)
  - 현재 방문한 숫자가 target 미만이거나 target이 right에 있는 숫자 초과인경우 (왼쪽 구간에 정답)

문제에서 중복된 수가 포함될 수 있다.

따라서 mid값을 찾기 전에 left와 right에서 중복된 index에 대한 처리를 해준다.

이 과정에서 최악의 경우 O(N)의 시간 복잡도가 소요된다.

이 때 left와 right의 값이 역전되지 않도록 주의한다.

```cpp
while (left < right && nums[left] == nums[left + 1]) left++;
while (left < right && nums[right] == nums[right - 1]) right--;
```

```cpp
bool search(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    while (left < right && nums[left] == nums[left + 1]) left++;
    while (left < right && nums[right] == nums[right - 1]) right--;
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) return true;

    if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (nums[mid] < target && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  return false;
}
```

## 고생한 점
