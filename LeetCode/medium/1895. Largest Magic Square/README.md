# 1895. Largest Magic Square

[링크](https://leetcode.com/problems/largest-magic-square/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

가능한 정사각형의 크기는 min(R, C)까지 존재할 수 있다.

각 조합마다 prefix sum을 이용해 행, 열, 대각선의 합을 O(min(R, C))에 구할 수 있다.

이를 모든 조합쌍에 대해 판단할 경우 O(R \* C \* min(R, C)^2)의 시간 복잡도를 가진다.

### 공간 복잡도

prefix sum을 계산하는 데 O(R \* C)의 공간 복잡도를 사용한다.

### prefix sum & 완전 탐색

| 내 코드 (ms) |       시간 복잡도        | 공간 복잡도 |
| :----------: | :----------------------: | :---------: |
|      37      | O(R \* C \* min(R, C)^2) |  O(R \* C)  |

정사각형의 특정 길이 L에 대해 prefix sum을 이용해 주어진 조건을 만족하는지 검사하는데 O(L)의 시간이 걸린다.

이를 가능한 조합들에 대해 탐색하는데 O(R \* C \* L)의 시간 복잡도를 사용한다.

여기서 L은 최대 min(R, C)까지 가능하다.

```cpp
int largestMagicSquare(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();
  int maxLength = min(rows, cols);

  vector<vector<int>> rowPrefixes(rows + 1, vector<int>(cols + 1, 0));
  vector<vector<int>> colPrefixes(rows + 1, vector<int>(cols + 1, 0));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      rowPrefixes[y + 1][x + 1] = rowPrefixes[y + 1][x] + grid[y][x];
      colPrefixes[y + 1][x + 1] = colPrefixes[y][x + 1] + grid[y][x];
    }
  }

  function<bool(int, int, int)> check = [&](int y, int x, int length) {
    int sum = rowPrefixes[y + 1][x + length] - rowPrefixes[y + 1][x];

    for (int i = 0; i < length; i++) {
      int rowSum =
          rowPrefixes[y + 1 + i][x + length] - rowPrefixes[y + 1 + i][x];
      int colSum =
          colPrefixes[y + length][x + 1 + i] - colPrefixes[y][x + 1 + i];
      if (rowSum != sum) return false;
      if (colSum != sum) return false;
    }

    int diagonal1 = 0, diagonal2 = 0;
    for (int i = 0; i < length; i++) {
      diagonal1 += grid[y + i][x + i];
      diagonal2 += grid[y + length - 1 - i][x + i];
    }
    if (diagonal1 != sum || diagonal2 != sum) return false;
    return true;
  };

  int answer = 1;
  for (int length = 2; length <= maxLength; length++) {
    for (int y = 0; y <= rows - length; y++) {
      for (int x = 0; x <= cols - length; x++) {
        bool result = check(y, x, length);
        if (result) {
          answer = length;
        }
      }
    }
  }

  return answer;
}
```

## 고생한 점
