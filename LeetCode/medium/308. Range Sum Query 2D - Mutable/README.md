# 308. Range Sum Query 2D - Mutable

[링크](https://leetcode.com/problems/range-sum-query-2d-mutable/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

완전 탐색으로 구현할 경우 query에 O(RC)의 시간 복잡도를 사용한다.

1차원 prefix sum을 사용할 경우 갱신에 O(C), 쿼리에 O(R)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 각 행마다 구성하는데 O(RC)의 공간 복잡도를 사용한다.

### 1D prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      | O(C), O(R)  |    O(RC)    |

각 행마다의 prefix sum을 생성 후 값이 갱신될 때 해당 행의 prefix sum을 갱신한다.

이후 쿼리에 행마다 순회하며 정답을 갱신한다.

```cpp
class NumMatrix {
 private:
  vector<vector<int>> rowPrefix;
  vector<vector<int>> matrix;

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    this->matrix = matrix;
    int rows = matrix.size(), cols = matrix[0].size();

    rowPrefix.resize(rows, vector<int>(cols + 1));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        rowPrefix[y][x + 1] = rowPrefix[y][x] + matrix[y][x];
      }
    }
  }

  void update(int row, int col, int val) {
    int rows = matrix.size(), cols = matrix[0].size();

    matrix[row][col] = val;
    for (int x = 0; x < cols; x++) {
      rowPrefix[row][x + 1] = rowPrefix[row][x] + matrix[row][x];
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;

    for (int y = row1; y <= row2; y++) {
      sum += rowPrefix[y][col2 + 1] - rowPrefix[y][col1];
    }
    return sum;
  }
};
```

## 고생한 점
