# 2371. Minimize Maximum Value in a Grid

[링크](https://leetcode.com/problems/minimize-maximum-value-in-a-grid/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열 grid의 크기를 N이라 하자. (R \* C == N)

각 값들 중에서 작은 순서대로 탐색을 진행하며 값을 바꿀 수 있다.

이 경우 정렬을 수행하는데 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

각 행과 열의 정보를 저장하는 데 O(R + C)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     146      | O(N \* log_2(N)) |    O(N)     |

grid의 각 원소는 중복되지 않는 숫자들이다.

각 행과 열에 대해서 각 값들의 대소관계는 유지되어야 한다.

이 때 값을 줄이며 탐색을 진행해야 하므로 각 원소들을 작은 순서부터 탐색한다.

각 행과 열마다 현재까지 최대값을 저장하며, 현재 값은 최대값보다 큰 값으로 설정한다.

각 탐색을 진행하며 현재 좌표의 행, 열 중 순서가 큰 값에 맞춰 값을 갱신한다.

```cpp
vector<vector<int>> minScore(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<vector<int>> nums;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      nums.push_back({grid[y][x], y, x});
    }
  }

  vector<int> rowVals(rows, 1);
  vector<int> colVals(cols, 1);

  sort(nums.begin(), nums.end());

  for (vector<int>& line : nums) {
    int val = line[0], y = line[1], x = line[2];

    val = max(rowVals[y], colVals[x]);
    grid[y][x] = val;
    rowVals[y] = colVals[x] = val + 1;
  }

  return grid;
}
```

## 고생한 점
