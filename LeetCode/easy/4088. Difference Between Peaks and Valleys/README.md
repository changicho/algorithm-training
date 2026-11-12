# 4088. Difference Between Peaks and Valleys

[링크](https://leetcode.com/problems/difference-between-peaks-and-valleys/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회하며 peak, valley의 합을 구하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 합을 구하는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

순회하며 peak, valley인 경우 각 합에 더한다.

이후 정답을 반환한다.

```cpp
int peakValleyDifference(vector<int>& nums) {
  int size = nums.size();
  int peak = 0, valley = 0;

  for (int i = 1; i < size - 1; i++) {
    if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
      peak += nums[i];
    }
    if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
      valley += nums[i];
    }
  }

  return peak - valley;
}
```

## 고생한 점
