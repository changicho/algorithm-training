# 3446. Sort Matrix by Diagonals

[링크](https://leetcode.com/problems/sort-matrix-by-diagonals/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 한 행의 크기를 N이라 하자.

대각선 원소들을 순회 후 정렬하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이를 모든 대각선에 대해 수행하는데 총 O(N^2 \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      11      | O(N^2 \* log_2(N)) |    O(N)     |

하위 삼각형과 상위 삼각형을 별도로 순회하며 대각선 원소를 정렬후 변환한다.

```cpp
vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  for (int y = 0; y < rows; y++) {
    vector<int> nums;
    for (int i = 0; i < cols - y; i++) {
      nums.push_back(grid[y + i][i]);
    }

    sort(nums.begin(), nums.end(), greater<int>());

    for (int i = 0; i < cols - y; i++) {
      grid[y + i][i] = nums[i];
    }
  }

  for (int x = 1; x < cols; x++) {
    vector<int> nums;
    for (int i = 0; i < rows - x; i++) {
      nums.push_back(grid[i][x + i]);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < rows - x; i++) {
      grid[i][x + i] = nums[i];
    }
  }

  return grid;
}
```

## 고생한 점
