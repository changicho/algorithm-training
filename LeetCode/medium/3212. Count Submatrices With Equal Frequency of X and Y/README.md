# 3212. Count Submatrices With Equal Frequency of X and Y

[링크](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

2차원 prefix sum을 사용할 경우 O(R \* C) 의 시간 복잡도를 사용한다.

### 공간 복잡도

2차원 prefix sum을 사용할 경우 O(R \* C) 의 공간 복잡도를 사용한다.

### 2D prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     174      |  O(R \* C)  |  O(R \* C)  |

0,0부터 y,x까지의 X의 갯수와 Y의 갯수를 각각 저장하는 2차원 배열을 만든다.

이후 두 구간의  X, Y의 갯수가 같은지 확인하며, 값이 1 이상인지 판단한다.

같은 경우 정답을 증가시킨다.

이를 모든 y, x쌍에 대해 빠르게 구하기 위해 2차원 prefix sum을 사용한다.

```cpp
int numberOfSubmatrices(vector<vector<char>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  int xDp[1001][1001] = {
      0,
  };
  int yDp[1001][1001] = {
      0,
  };

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      xDp[y][x] = (grid[y][x] == 'X');
      yDp[y][x] = (grid[y][x] == 'Y');

      if (x > 0) {
        xDp[y][x] += xDp[y][x - 1];
        yDp[y][x] += yDp[y][x - 1];
      }

      if (y > 0) {
        xDp[y][x] += xDp[y - 1][x];
        yDp[y][x] += yDp[y - 1][x];
      }

      if (x > 0 && y > 0) {
        xDp[y][x] -= xDp[y - 1][x - 1];
        yDp[y][x] -= yDp[y - 1][x - 1];
      }

      int xCount = xDp[y][x];
      int yCount = yDp[y][x];

      if (xCount > 0 && (xCount == yCount)) {
        answer++;
      }
    }
  }

  return answer;
}
```

## 고생한 점
