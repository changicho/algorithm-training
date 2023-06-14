# 2352. Equal Row and Column Pairs

[링크](https://leetcode.com/problems/equal-row-and-column-pairs/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 N이라 하자. (열의 갯수도 동일)

모든 경우를 직접 비교할 경우 O(N^3)의 시간 복잡도를 사용한다.

미리 각 행, 열에 대해 line을 구해놓고 hash map에 저장후 비교할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 경우를 미리 저장할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 행, 열 미리 구하기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     130      |   O(N^3)    |   O(N^2)    |

각 행과 열에 대한 line을 미리 구해놓는다.

이후 각 y, x의 시작쌍에 대해 같은 line을 비교한다.

```cpp
int equalPairs(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<vector<int>> lineRows(rows), lineCols(cols);
  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      lineRows[y].push_back(grid[y][x]);
      lineCols[x].push_back(grid[y][x]);
    }
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (lineRows[y] == lineCols[x]) answer++;
    }
  }

  return answer;
}
```

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     289      |   O(N^2)    |   O(N^2)    |

각 행에 대한 line을 구하고 hash map에 count한다.

이후 각 열에 대한 line을 구해 같은 갯수를 hash map에서 찾아 정답에 더한다.

```cpp
int equalPairs(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  unordered_map<string, int> counts;
  int answer = 0;
  for (int y = 0; y < rows; y++) {
    string line = "";
    for (int x = 0; x < cols; x++) {
      line += to_string(grid[y][x]) + "/";
    }
    counts[line]++;
  }

  for (int x = 0; x < cols; x++) {
    string line = "";
    for (int y = 0; y < rows; y++) {
      line += to_string(grid[y][x]) + "/";
    }

    answer += counts[line];
  }

  return answer;
}
```

## 고생한 점
