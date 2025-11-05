# 3350. Adjacent Increasing Subarrays Detection II

[링크](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이분 탐색을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     225      |    O(N)     |    O(1)     |

배열을 왼쪽부터 순회하며 증가하는 구간의 길이를 count로 저장한다.

만약 현재 숫자에서 증가하지 않는 경우, 직전 증가하는 구간의 길이를 before에 저장하고 현재 증가하는 구간의 길이를 초기화 후 다시 증가시킨다.

각 순회지점마다 before와 count의 최솟값, 혹은 count / 2의 최댓값을 answer에 갱신한다.

count / 2의 경우는 현재 구간에서 증가하는 subArray를 두 개로 나누는 경우를 고려한 것이다.

```cpp
int maxIncreasingSubarrays(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;

  int before = 0;
  int count = 1;
  for (int i = 1; i < size; i++) {
    if (nums[i - 1] >= nums[i]) {
      before = count;
      count = 0;
    }

    count++;

    answer = max({answer, min(before, count), count / 2});
  }

  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     272      | O(N \* log_2(N)) |    O(1)     |

`3349. Adjacent Increasing Subarrays Detection I` 문제와 유사하게 풀이한다.

subArray의 크기를 이분 탐색으로 찾으며, 각 경우마다 두 개의 subArray가 존재하는지 확인한다.

```cpp
bool check(vector<int>& nums, int k) {
  int size = nums.size();

  int count1 = 0, count2 = 0;
  for (int i = 0, j = k; j < size; i++, j++) {
    if (i - 1 >= 0 && nums[i - 1] >= nums[i]) {
      count1 = 0;
    }

    if (j >= 0 && nums[j - 1] >= nums[j]) {
      count2 = 0;
    }

    count1++;
    count2++;

    if (count1 >= k && count2 >= k) return true;
  }

  return false;
}

int maxIncreasingSubarrays(vector<int>& nums) {
  int size = nums.size();

  int left = 1, right = size;
  int answer = 0;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (check(nums, mid)) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
