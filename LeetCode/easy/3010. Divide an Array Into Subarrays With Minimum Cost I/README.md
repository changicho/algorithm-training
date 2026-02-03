# 3010. Divide an Array Into Subarrays With Minimum Cost I

[링크](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

완전 탐색을 수행할 경우 O(N^2)의 시간 복잡도를 사용한다.

한번의 순회로 최솟값과 두번째 최솟값을 찾을 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

배열을 3개의 구간으로 나누며 각 구간의 가장 첫번째 값을 더한 값을 최소화하는 문제이다.

첫번째 구간의 첫번째 값은 `nums[0]`으로 고정되어 있다.

따라서 남은 두 구간을 정할 때 가장 작은값과 두번째로 작은값을 선택하면 된다.

이를 한번의 순회로 찾는다.

```cpp
int minimumCost(vector<int>& nums) {
  int size = nums.size();

  int first = min(nums[1], nums[2]);
  int second = max(nums[1], nums[2]);
  for (int i = 3; i < size; i++) {
    if (first >= nums[i]) {
      second = first;
      first = nums[i];
    } else if (second >= nums[i]) {
      second = nums[i];
    }
  }

  return nums[0] + first + second;
}
```

## 고생한 점
