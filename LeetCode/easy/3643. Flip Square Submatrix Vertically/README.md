# 3643. Flip Square Submatrix Vertically

[링크](https://leetcode.com/problems/flip-square-submatrix-vertically/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 크기를 R \* C, 입력받은 수를 K라 하자.

K^2크기의 공간을 위아래로 뒤집는 작업에 O(K^2)의 시간 복잡도가 소요된다.

### 공간 복잡도

입력받은 공간을 그대로 사용할 경우 O(1)의 공간 복잡도가 소요된다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(K^2)    |    O(1)     |

특정 K^2 구간을 위아래로 뒤집으면 된다.

입력받은 시작 위치에서부터 순회하며 K^2 구간을 뒤집는다.

```cpp
vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y,
                                      int k) {
  int cols = grid.size(), rows = grid[0].size();

  for (int i = 0; i < k / 2; i++) {
    for (int j = 0; j < k; j++) {
      int r = x + k - i - 1;
      swap(grid[x + i][y + j], grid[r][y + j]);
    }
  }

  return grid;
}
```

## 고생한 점
