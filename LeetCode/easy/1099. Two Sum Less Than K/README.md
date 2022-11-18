# 1099. Two Sum Less Than K

[링크](https://leetcode.com/problems/two-sum-less-than-k/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 nums의 크기를 N이라 하자. (N <= 100)

모든 경우를 직접 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

nums를 정렬 후 이분탐색을 통해 각 값마다 더할 수 있는 최대 값을 구할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

정렬 후 투 포인터를 이용해 탐색할 수 있다.

이 경우 탐색하는데 O(N)의 시간 복잡도를 사용한다.

범위가 작으므로 카운팅 정렬을 이용해 정렬할 수 있다. 이 경우 범위를 M이라 했을 때 탐색에 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

nums를 정렬할 경우 최대 O(N)의 공간 복잡도를 사용한다.

카운팅 정렬을 사용할 경우 O(M)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(N)) |    O(N)     |

각 값이 정렬되어있다고 가정하자.

현재 값을 num이라 했을 때 k - num 이하인 가장 가까운 값을 이분 탐색을 이용해 찾을 수 있다.

이 경우 이분 탐색에 O(log_2(N))의 시간 복잡도를 사용한다.

```cpp
int twoSumLessThanK(vector<int>& nums, int k) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  int answer = -1;
  for (int i = 0; i < size; i++) {
    int idx =
        lower_bound(nums.begin(), nums.end(), k - nums[i]) - nums.begin();
    idx--;

    if (idx < 0 || idx == i) continue;

    answer = max(answer, nums[i] + nums[idx]);
  }

  return answer;
}
```

### 투 포인터

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      3       | O(N \* log_2(N)) |    O(N)     |

```cpp
int twoSumLessThanK(vector<int>& nums, int k) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  int answer = -1;
  int left = 0, right = size - 1;
  while (left < right) {
    int sum = nums[left] + nums[right];

    if (sum < k) {
      answer = max(answer, sum);
      left++;
    } else {
      right--;
    }
  }

  return answer;
}
```

## 고생한 점
