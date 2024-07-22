# 1605. Find Valid Matrix Given Row and Column Sums

[링크](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

탐욕 알고리즘을 사용해 각 좌표마다 최적의 값을 찾아야 한다.

이 때 모든 좌표를 방문해야 하므로 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 O(R \* C)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      38      |  O(R \* C)  |  O(R \* C)  |

각 좌표마다 y, x에 대해 rowSum과 colSum에 영향을 끼친다.

각 값마다 할당할 수 있는 최대값을 할당하고, rowSum과 colSum에서 빼준다.

이를 모든 좌표에 대해 반복하며 정답을 구한다.

```cpp
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
  int rows = rowSum.size(), cols = colSum.size();

  vector<vector<int>> matrix(rows, vector<int>(cols, 0));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int cur = min(rowSum[y], colSum[x]);

      rowSum[y] -= cur;
      colSum[x] -= cur;

      matrix[y][x] = cur;
    }
  }

  return matrix;
}
```

## 고생한 점
