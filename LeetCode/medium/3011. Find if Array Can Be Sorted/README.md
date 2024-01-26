# 3011. Find if Array Can Be Sorted

[링크](https://leetcode.com/problems/find-if-array-can-be-sorted/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

같은 bit가 연이어 있는 경우 해당 subArray는 정렬할 수 있다.

bit가 연속된 배열마다 정렬을 수행할 경우 O(N * log_2(N))의 시간 복잡도를 사용한다.

혹은 이전 subArray의 최대값과 현재 subArray의 최소, 최대값이 정렬되어있는지를 비교할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도가 필요하다.

각 경우마다 min, max를 비교할 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      15      | O(N * log_2(N)) |    O(N)     |

배열 내의 연속된 내부 배열을 subArray라고 하자.

bit가 같은 subArray들을 정렬한다.

이후 실제로 정렬되어 있는지 판단한다.

```cpp
bool canSortArray(vector<int>& nums) {
  int size = nums.size();

  int beforeBit = __builtin_popcount(nums[0]);
  int left = 0;

  for (int i = 1; i < size; i++) {
    int bit = __builtin_popcount(nums[i]);

    if (beforeBit == bit) {
      continue;
    }
    sort(nums.begin() + left, nums.begin() + i);
    beforeBit = bit;
    left = i;
  }

  sort(nums.begin() + left, nums.end());

  for (int i = 0; i < size - 1; i++) {
    if (nums[i] > nums[i + 1]) return false;
  }

  return true;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

배열을 정렬할 수 있는 경우는 이전 subArray의 최대값이 현재 subArray의 최소값보다 작은 경우이다.

이를 이용해 순회하며 bit가 같은 subArray마다의 최대값, 최소값을 갱신한다.

이후 subArray가 바뀔 때 마다 직전 subArray와 비교를 수행한다.

```cpp
bool canSortArray(vector<int>& nums) {
  int size = nums.size();

  int beforeMax = INT_MIN;
  int curBit = __builtin_popcount(nums[0]);
  int curMax = nums[0];
  int curMin = nums[0];

  for (int i = 1; i < size; i++) {
    int bit = __builtin_popcount(nums[i]);

    if (curBit == bit) {
      curMax = max(curMax, nums[i]);
      curMin = min(curMin, nums[i]);
      continue;
    }

    if (curMax < beforeMax) return false;
    if (beforeMax > curMin) return false;

    beforeMax = curMax;
    curMax = nums[i];
    curMin = nums[i];

    curBit = bit;
  }
  if (curMax < beforeMax) return false;
  if (beforeMax > curMin) return false;

  return true;
}
```

## 고생한 점
