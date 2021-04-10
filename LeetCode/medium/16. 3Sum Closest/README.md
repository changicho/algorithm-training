# 16. 3Sum Closest

[링크](https://leetcode.com/problems/3sum-closest/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자 배열의 크기는 10^3이다. 브루트 포스 방법을 이용할 경우 시간 내에 불가능하다 따라서 다음 두가지 방법을 이용한다.

- 투 포인터
- 이분 탐색

투 포인터의 시간 복잡도는 O(N^2) 이다.

이분탐색의 시간 복잡도는 O(N^2 \* log(N)) 이다.

### 공간 복잡도

정렬 알고리즘에 들어가는 공간 복잡도 최대 O(N)이 소요된다

### 투 포인터

> 4ms

first, second, third 세 숫자를 골라야한다.

오름차순으로 정렬 후 first를 고정시킨 후, second와 third를 이동시키며 정답을 갱신한다.

이 때, target과의 차이의 절대값을 이용해 비교연산을 수행한다.

```cpp
int threeSumClosest(vector<int>& nums, int target) {
  int answer = 20000;
  int size = nums.size();

  sort(nums.begin(), nums.end());

  for (int index = 0; index < size - 2 && answer != target; index++) {
    if (index > 0 && nums[index] == nums[index - 1]) continue;

    int start = index + 1;
    int end = size - 1;

    while (start < end) {
      int sum = nums[index] + nums[start] + nums[end];

      if (abs(answer - target) > abs(sum - target)) {
        answer = sum;
      }
      if (sum > target) {
        end--;
      } else {
        start++;
      }
    }
  }

  return answer;
}
```

### 이분탐색

> 20ms

first와 second를 탐색하며 third를 이분탐색을 통해 탐색할 수 있다.

sum = first + second + third 이므로 반대로 찾아야 하는 third를 이분탐색으로 찾는다.

이 때 third를 필요한 값으로 정확히 찾는 경우와 찾지 못하는 경우가 존재할 수 있다.

만약 찾지 못하는 경우를 위해 third 위치 바로 앞의 값을 이용해 비교한다.

이 때 third가 될 수 있는 값이 second보다 이후에 나타나야 함에 유의한다.

```cpp
int threeSumClosest(vector<int>& nums, int target) {
  int answer = 20000;
  int size = nums.size();
  sort(nums.begin(), nums.end());

  for (int first = 0; first < size - 2 && answer != target; first++) {
    for (int second = first + 1; second < size - 1; second++) {
      int diff = target - nums[first] - nums[second];
      int end = upper_bound(nums.begin() + second + 1, nums.end(), diff) - nums.begin();
      int start = end - 1;

      // index range safe check
      if (end < size && abs(nums[first] + nums[second] + nums[end] - target) < abs(answer - target)) {
        answer = nums[first] + nums[second] + nums[end];
      }
      if (start > second && abs(nums[first] + nums[second] + nums[start] - target) < abs(answer - target)) {
        answer = nums[first] + nums[second] + nums[start];
      }
    }
  }
  return answer;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
