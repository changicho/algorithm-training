# 259. 3Sum Smaller

[링크](https://leetcode.com/problems/3sum-smaller/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자의 갯수를 N이라 하자.

브루트 포스로 3개의 수를 고르는 경우는 O(N^3)의 시간 복잡도가 필요하며 이는 제한시간을 초과한다.

하나의 숫자를 고정하고 나머지 2개의 숫자를 찾는 방법으로 문제를 바꿔 생각하자.

이 경우 하나의 숫자를 고정하는데 O(N)의 outer 시간 복잡도가 소요된다.

이후 내부적으로 두개의 숫자를 고르는 방법은 이분탐색, 투 포인터를 이용해 구현할 수 있다.

두 방법 모두 정렬을 해야 하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이분탐색에서는 하나의 숫자를 더 고정한 뒤 이분탐색이 가능하므로 시간 복잡도는 O(N \* log_2(N))이다.

따라서 최종 시간 복잡도는 O(N^2 \* log_2(N))이다.

투 포인터를 사용할 경우 숫자 하나가 고정되어 있을 때 다른 수를 탐색하는 시간 복잡도는 O(N)이므로 최종적으로 O(N^2)가 된다.

### 공간 복잡도

정렬의 방법에 따라 O(N)의 공간 복잡도가 필요할 수도 있다.

이분 탐색과 투 포인터의 경우 별도의 공간 복잡도가 필요하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      57      |   O(N^2)    |    O(1)     |

먼저 숫자를 정렬해 투 포인터를 사용할 수 있도록 구성한다.

이후 하나의 숫자를 고정한 뒤 그 숫자 오른쪽에 있는 모든 숫자들에 대해서 투 포인터를 진행한다.

이 때 현재 3개의 index에 있는 합이 target 미만인 경우는 제일 오른쪽에 있는 숫자보다 왼쪽에 있는 모든 숫자들에 대해서 합이 target보다 작음이 만족한다.

(정렬되어 있기 때문)

따라서 이 경우에 해당 경우 모두를 정답으로 더하고 왼쪽 index를 증가시킨다.

그 외의 경우는 오른쪽 index를 감소시킨다.

```cpp
int threeSumSmaller(vector<int>& nums, int target) {
  int size = nums.size();
  if (size < 3) return 0;

  sort(nums.begin(), nums.end());

  int answer = 0;
  for (int i = 0; i < size - 2; i++) {
    // 현재 숫자를 고정함
    int cur = nums[i];

    // index는 겹치면 안되므로 다음과 같이 설정
    int left = i + 1, right = size - 1;

    while (left < right) {
      int curSum = cur + nums[left] + nums[right];
      // 현재 합이 target 미만인 경우
      if (curSum < target) {
        // right'가 left + 1 ~ right인 경우 모두 만족
        answer += right - left;
        left += 1;
      } else {
        // right를 감소해 합을 감소시킴
        right -= 1;
      }
    }
  }

  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     600      | O(N^2 \* log_2(N)) |    O(1)     |

이분 탐색을 하기 위해 수를 정렬한다.

두개의 숫자를 고정할 경우 나머지 하나의 숫자는 이분 탐색을 이용해 빠르게 찾을 수 있다.

이 때 세 수의 합이 target보다 작은 가장 큰 값을 찾는다.

이 값보다 작은 값들이 모두 정답이 될 수 있다.

```cpp
int threeSumSmaller(vector<int>& nums, int target) {
  int size = nums.size();
  if (size < 3) return 0;

  sort(nums.begin(), nums.end());

  int answer = 0;
  for (int i = 0; i < size - 2; i++) {
    for (int j = i + 1; j < size - 1; j++) {
      // 두 수를 고정하고 남은 하나의 수를 이분 탐색을 이용해 찾는다.
      // 이 때 세 수의 합이 target보다 작은 가장 큰 값을 찾는다.
      int k = lower_bound(nums.begin() + j + 1, nums.end(), target - nums[i] - nums[j]) - nums.begin();
      // k'가 j + 1 ~ k인 경우 모두 만족
      answer += k - (j + 1);
    }
  }

  return answer;
}
```

lower bound가 아니라 직접 이분탐색을 구현할 경우 다음과 같이 구현할 수 있다.

```cpp
int threeSumSmaller(vector<int>& nums, int target) {
  int size = nums.size();
  if (size < 3) return 0;

  sort(nums.begin(), nums.end());

  int answer = 0;
  for (int i = 0; i < size - 2; i++) {
    for (int j = i + 1; j < size - 1; j++) {
      int left = j + 1, right = size;
      while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] + nums[i] + nums[j] < target) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      answer += right - (j + 1);
    }
  }

  return answer;
}
```

## 고생한 점
