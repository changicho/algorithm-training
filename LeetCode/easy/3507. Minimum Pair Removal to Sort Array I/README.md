# 3507. Minimum Pair Removal to Sort Array I

[링크](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

시뮬레이션을 사용해 모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

배열을 조작하는데 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(N)     |

각 경우마다 정렬이 되어있는지 확인하며, 정렬되어있지 않은 경우 문제 조건에 맞춰 배열을 갱신한다.

```cpp
bool isSorted(vector<int>& nums) {
  int size = nums.size();
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] > nums[i + 1]) return false;
  }
  return true;
}

int minimumPairRemoval(vector<int>& nums) {
  int answer = 0;
  while (!isSorted(nums)) {
    int target = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[target] + nums[target + 1] > nums[i] + nums[i + 1]) {
        target = i;
      }
    }

    nums[target] = nums[target] + nums[target + 1];
    nums.erase(nums.begin() + target + 1);

    answer++;
  }

  return answer;
}
```

## 고생한 점
