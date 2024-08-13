# 840. Magic Squares In Grid

[링크](https://leetcode.com/problems/magic-squares-in-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행과 열의 크기를 R, C라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

정답의 개수를 세기 위한 변수를 선언해야 한다.

이에 필요한 공간 복잡도는 O(1)이다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |  O(R \* C)  |    O(1)     |

각 좌표를 시작점으로 모두 탐색하며 해당 좌표에서 3x3의 정사각형이 magic square인지 판별한다.

```cpp
bool isValid(int y, int x, vector<vector<int>>& grid) {
  int counts[16] = {
      0,
  };
  int rowSums[3] = {
      0,
  };
  int colSums[3] = {
      0,
  };

  int first = 0;
  int second = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      counts[grid[y + i][x + j]]++;
      rowSums[i] += grid[y + i][x + j];
      colSums[j] += grid[y + i][x + j];

      if (i == j) first += grid[y + i][x + j];
      if (i == 2 - j) second += grid[y + i][x + j];
    }
  }

  for (int num = 1; num <= 9; num++) {
    if (counts[num] != 1) return false;
  }

  if (first != second) return false;
  for (int i = 0; i < 2; i++) {
    if (rowSums[i] != rowSums[i + 1] || colSums[i] != colSums[i + 1])
      return false;
  }
  if (rowSums[0] != colSums[0] || rowSums[0] != first) return false;
  return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid.size();
  int answer = 0;
  for (int y = 0; y <= rows - 3; y++) {
    for (int x = 0; x <= cols - 3; x++) {
      if (isValid(y, x, grid)) answer++;
    }
  }

  return answer;
}
```

## 고생한 점
