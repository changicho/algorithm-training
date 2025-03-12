# 2529. Maximum Count of Positive Integer and Negative Integer

[링크](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

배열은 이미 정렬되어 있으므로 이분 탐색을 사용할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도가 필요하다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

이분 탐색을 이용해 음수, 양수의 갯수를 센다.

이 때 0에 대해서 lower_bound, upper_bound를 사용해 해당 갯수를 셀 수 있다.

```cpp
int maximumCount(vector<int>& nums) {
  int size = nums.size();
  int zeroS = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
  int zeroE = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();

  int neg = zeroS;
  int pos = size - zeroE;

  return max(neg, pos);
}
```

## 고생한 점
