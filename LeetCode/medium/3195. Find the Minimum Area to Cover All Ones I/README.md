# 3195. Find the Minimum Area to Cover All Ones I

[링크](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 좌표를 순회하며 1의 y, x좌표의 min max를 구할 수 있다.

이에 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 갖는다.

### min max

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     240      |  O(R * C)   |    O(1)     |

1을 모두 커버하기 위해 1이 존재하는 y, x 좌표들의 최대값과 최솟값을 구한다.

이후 해당 값들을 이용해 높이와 너비를 구하고, 이를 곱하여 최소 면적을 구한다.

```cpp
int minimumArea(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  int minY = INT_MAX, maxY = INT_MIN;
  int minX = INT_MAX, maxX = INT_MIN;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 1) {
        minY = min(minY, y);
        maxY = max(maxY, y);

        minX = min(minX, x);
        maxX = max(maxX, x);
      }
    }
  }

  int height = maxY - minY + 1;
  int width = maxX - minX + 1;

  return height * width;
}
```

## 고생한 점
