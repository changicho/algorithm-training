# 3033. Modify the Matrix

[링크](https://leetcode.com/problems/modify-the-matrix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

입력받은 matrix를 그대로 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |  O(R \* C)  |    O(1)     |

각 열마다의 최대값을 찾고, 각 열에 있는 -1 값을 최대값으로 바꾼다.

```cpp
vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
  int rows = matrix.size(), cols = matrix[0].size();

  for (int x = 0; x < cols; x++) {
    int maximum = 0;
    for (int y = 0; y < rows; y++) {
      maximum = max(maximum, matrix[y][x]);
    }

    for (int y = 0; y < rows; y++) {
      if (matrix[y][x] == -1) {
        matrix[y][x] = maximum;
      }
    }
  }
  return matrix;
}
```

## 고생한 점
