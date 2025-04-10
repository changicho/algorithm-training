# 2033. Minimum Operations to Make a Uni-Value Grid

[링크](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 셀의 갯수를 N이라 하자.

각 값들 중에서 최소 operation을 수행하기 위해 중앙값을 찾는다.

이에 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬을 위한 공간 복잡도는 O(N)이다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      51      | O(N \* log_2(N)) |    O(N)     |

x로 나누어 떨어지는 값이 다른 종류가 존재하는 경우 정답으로 불가능한 경우이므로 무시한다.

각 값을 x로 나눈 몫으로 치환한 뒤 해당 값들을 정렬 후 중앙값을 찾는다.

이후 중앙값을 기준으로 모든 값들을 중앙값으로 맞추기 위해 필요한 연산의 수를 구한다.

```cpp
int minOperations(vector<vector<int>> &grid, int x) {
  int rows = grid.size(), cols = grid[0].size();
  unordered_set<int> mods;

  vector<int> nums;

  for (vector<int> &row : grid) {
    for (int &num : row) {
      mods.insert(num % x);
      nums.push_back(num);
    }
  }

  if (mods.size() >= 2) return -1;

  sort(nums.begin(), nums.end());

  int target = nums[nums.size() / 2];
  int answer = 0;
  for (vector<int> &row : grid) {
    for (int &num : row) {
      answer += abs(target - num) / x;
    }
  }

  return answer;
}
```

## 고생한 점
