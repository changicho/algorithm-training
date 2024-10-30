# 1671. Minimum Number of Removals to Make Mountain Array

[링크](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

LIS 알고리즘을 사용할 경우 O(N^2), O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

LIS 알고리즘을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### LIS

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      2       | O(N \* log_2(N)) |    O(N)     |

각 index마다 왼쪽에서의 LIS와 오른쪽에서의 LIS를 구한다.

이후 각 index에서의 LIS를 더한 값이 가장 큰 경우를 찾는다.

이 때 문제 조건을 만족하기 위해 LIS값이 2 이상인 경우만 고려한다.

```cpp
vector<int> getLIS(vector<int>& nums) {
  int size = nums.size();
  vector<int> lis;
  vector<int> lengths(size, 1);

  for (int i = 0; i < size; i++) {
    int target = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

    if (target == lis.size()) {
      lis.push_back(nums[i]);
    } else {
      lis[target] = nums[i];
    }
    lengths[i] = lis.size();
  }

  return lengths;
}

int minimumMountainRemovals(vector<int>& nums) {
  int size = nums.size();

  vector<int> inc = getLIS(nums);
  reverse(nums.begin(), nums.end());
  vector<int> desc = getLIS(nums);

  reverse(desc.begin(), desc.end());

  int answer = size;
  for (int i = 1; i < size - 1; i++) {
    if (inc[i] > 1 && desc[i] > 1) {
      int cur = inc[i] + desc[i];

      answer = min(answer, size - cur + 1);
    }
  }
  return answer;
}
```

## 고생한 점
