# 3347. Maximum Frequency of an Element After Performing Operations II

[링크](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

원소를 정렬하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

nums의 원소에 대해 이분 탐색을 이용해 범위 내에 속하는 원소의 개수를 구하는데 총 O(N \* log_2(N))의 시간 복잡도를 사용한다.

투 포인터를 사용하는 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

각 숫자를 count하는 해시 맵을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     420      | O(N \* log_2(N)) |    O(N)     |

nums를 정렬한다.

이후 각 nums를 순회하며 다음 2가지 경우에 대해서 정답을 갱신한다.

- 현재 수를 X라 하자.
- (X - K) ~ (X + K) 범위의 수를 이용해 정답을 구함
- X ~ (X + 2 \* K) 범위의 수를 이용해 정답을 구함

수가 정렬되어 있는 경우 범위에 해당하는 수는 이분 탐색을 이용해 구할 수 있다.

해당 범위의 숫자와를 현재 범위의 중앙값의 갯수를 이용해 정답을 갱신한다.

```cpp
int maxFrequency(vector<int>& nums, int k, int numOperations) {
  sort(nums.begin(), nums.end());

  unordered_map<long long, int> count;
  long minimum = nums[0], maximum = nums[0];
  for (int& num : nums) {
    count[num]++;
    minimum = min((long)num, minimum);
    maximum = max((long)num, maximum);
  }

  function<int(long)> calc = [&](long mid) {
    int left = max(minimum, mid - k);
    int right = min(maximum, mid + k);

    int rangeCount = upper_bound(nums.begin(), nums.end(), right) -
                      lower_bound(nums.begin(), nums.end(), left);
    return min(count[mid] + numOperations, rangeCount);
  };

  int answer = 0;

  for (int& num : nums) {
    long target = num;
    answer = max(answer, calc(target + k));
    answer = max(answer, calc(target));
  }

  return answer;
}
```

### 정렬 & 투 포인터

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     191      | O(N \* log_2(N)) |    O(N)     |

위 방법에서 동일하게 (X - K) ~ (X + K) 범위, X ~ (X + 2 \* K) 범위에 대해 투 포인터를 이용해 해당 구간의 수를 구한다.

이후 정답을 갱신한다.

```cpp
int maxFrequency(vector<int>& nums, int k, int numOperations) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  unordered_map<int, int> count;

  for (int i = 0; i < size; i++) {
    count[nums[i]]++;
  }

  int answer = 0;

  // target val is in nums
  for (int i = 0, left = 0, right = 0; i < size; i++) {
    while (left < size && nums[i] - k > nums[left]) {
      left++;
    }
    while (right < size && nums[right] <= nums[i] + k) {
      right++;
    }

    answer = max(answer, min(right - left, numOperations + count[nums[i]]));
  }

  // target val is not in nums
  for (int left = 0, right = 0; right < size; right++) {
    while (nums[right] - nums[left] > (2 * k)) {
      left++;
    }

    answer = max(answer, min(right - left + 1, numOperations));
  }

  return answer;
}
```

## 고생한 점
