# 3567. Minimum Absolute Difference in Sliding Submatrix

[링크](https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 순회하는데 O(RC \* K^2)의 시간 복잡도를 사용한다.

각 경우마다 정렬을 사용하는데 O(K^2 \* log(K^2))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(RC \* K^2 \* log(K^2))이다.

### 공간 복잡도

정렬에 O(K^2)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |       시간 복잡도        | 공간 복잡도 |
| :----------: | :----------------------: | :---------: |
|      15      | O(RC \* K^2 \* log(K^2)) |   O(K^2)    |

모든 y,x쌍을 순회하며 해당 좌표를 top-left로 하는 K^2 크기의 정사각형을 순회한다.

해당 값들을 모두 배열에 저장 후, 서로 다른 값의 차이 중 가장 작은 차이를 구한다.

만약 모든 수가 같은 경우 0을 반환한다.

```cpp
vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
  int rows = grid.size(), cols = grid[0].size();

  vector<vector<int>> answer;
  for (int y = 0; y <= rows - k; y++) {
    vector<int> answerRow;
    for (int x = 0; x <= cols - k; x++) {
      vector<int> nums;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          nums.push_back(grid[y + i][x + j]);
        }
      }

      int cur = INT_MAX;
      sort(nums.begin(), nums.end());
      int size = nums.size();
      for (int i = 0; i < size - 1; i++) {
        if (nums[i] == nums[i + 1]) continue;
        int diff = abs(nums[i] - nums[i + 1]);

        cur = min(cur, diff);
      }

      if (cur == INT_MAX) cur = 0;

      answerRow.push_back(cur);
    }

    answer.push_back(answerRow);
  }
  return answer;
}
```

## 고생한 점
