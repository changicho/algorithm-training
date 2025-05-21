# 73. Set Matrix Zeroes

[링크](https://leetcode.com/problems/set-matrix-zeroes/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 갯수를 R, 열의 갯수를 C이라고 하자.

모든 배열의 원소를 한번씩은 순회해야 하므로 최소로 들어가는 시간 복잡도는 O(R \* C)이다.

원소를 순회해며 0을 찾을때마다 갱신할 경우 O(R + C)번의 시간 복잡도가 소요되며 이 경우 최종 시간 복잡도는 O(R \* C \* (R + C))이다.

0인 위치들을 찾고 한꺼번에 행렬을 갱신할 경우 O(R \* C)의 시간 복잡도가 소요된다.

### 공간 복잡도

똑같은 크기의 2차원 배열을 만들 경우 O(R \* C)의 공간 복잡도가 필요하다.

0이 되야하는 행과 열을 별도의 hash set으로 관리할 경우 O(R + C)의 공간 복잡도가 필요하다.

이 방법을 응용해 matrix 자체에서 0이 되어야 하는 행과 열을 표시할 경우 O(1)의 공간 복잡도가 필요하다.

### mark 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O(R \* C)  |  O(R + C)   |

matrix를 순회하며 0이 되어야하는 행과 열의 번호를 set에 저장한다.

이후 다시 matrix를 순회하며 0이 되어야하는 좌표를 0으로 갱신한다.

```cpp
void setZeroes(vector<vector<int>>& matrix) {
  int row_size = matrix.size();
  int col_size = matrix.front().size();
  unordered_set<int> rows;
  unordered_set<int> cols;

  for (int y = 0; y < row_size; y++) {
    for (int x = 0; x < col_size; x++) {
      if (matrix[y][x] != 0) continue;

      rows.insert(y);
      cols.insert(x);
    }
  }

  for (int y = 0; y < row_size; y++) {
    for (int x = 0; x < col_size; x++) {
      if (rows.find(y) != rows.end() || cols.find(x) != cols.end()) {
        matrix[y][x] = 0;
      }
    }
  }
}
```

### inPlace mark

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(R \* C)  |    O(1)     |

위 방법을 응용해 matrix에 직접 0이 되어야 하는 부분을 표시한다.

이를 matrix의 첫번째 행과 첫번째 열에 표시한다.

이 경우 첫번째 행과 열에 0이 있는 경우를 미리 구분해줘야 한다.

이를 위해 별도의 boolean 값을 선언한다.

이후 matrix를 순회하며 0이 되어야 하는 행과 열을 matrix의 첫번째 행과 열에 표시한 뒤

나머지 0을 모두 갱신한다.

```cpp
void setZeroes(vector<vector<int>>& matrix) {
  int rows = matrix.size(), cols = matrix[0].size();

  // check first row and first column
  bool firstCol = false;
  bool firstRow = false;
  for (int x = 0; x < cols; x++) {
    if (matrix[0][x] == 0) {
      firstRow = true;
    }
  }
  for (int y = 0; y < rows; y++) {
    if (matrix[y][0] == 0) {
      firstCol = true;
    }
  }

  // check and mark zero at first row and first column
  for (int y = 1; y < rows; y++) {
    for (int x = 1; x < cols; x++) {
      if (matrix[y][x] == 0) {
        matrix[0][x] = matrix[y][0] = 0;
      }
    }
  }

  // set zero to the rest of the matrix
  for (int y = 1; y < rows; y++) {
    for (int x = 1; x < cols; x++) {
      if (matrix[0][x] == 0 || matrix[y][0] == 0) {
        matrix[y][x] = 0;
      }
    }
  }
  if (firstRow) {
    for (int x = 0; x < cols; x++) {
      matrix[0][x] = 0;
    }
  }
  if (firstCol) {
    for (int y = 0; y < rows; y++) {
      matrix[y][0] = 0;
    }
  }
}
```

## 고생한 점
