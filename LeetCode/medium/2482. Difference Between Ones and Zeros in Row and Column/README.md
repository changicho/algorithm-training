# 2482. Difference Between Ones and Zeros in Row and Column

[링크](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 행렬의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 행과 열마다의 1의 갯수, 0의 갯수를 미리 구할 수 있다. 이 순회에 O(R \* C)의 시간 복잡도가 소요된다.

이후 각 좌표마다 미리 구한 행마다의 1의 갯수, 0의 갯수를 이용해 정답을 구할 수 있다. 이에 O(R \* C)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 행, 열마다의 1의 갯수, 0의 갯수를 미리 구할 수 있다. 이는 O(R + C)의 공간 복잡도가 필요하다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     190      |  O(R \* C)  |  O(R + C)   |

각 행, 열마다의 1과 0의 갯수를 센 뒤 각 좌표마다의 정답을 구한다.

```cpp
vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<int> oneRows(rows, 0), oneCols(cols, 0);
  vector<int> zeroRows(rows, 0), zeroCols(cols, 0);

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 1) {
        oneRows[y]++;
        oneCols[x]++;
      } else {
        zeroRows[y]++;
        zeroCols[x]++;
      }
    }
  }

  vector<vector<int>> answer(rows, vector<int>(cols));
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer[y][x] = oneRows[y] + oneCols[x] - zeroRows[y] - zeroCols[x];
    }
  }
  return answer;
}
```

## 고생한 점
