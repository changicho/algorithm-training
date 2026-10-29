# 3882. Minimum XOR Path in a Grid

[링크](https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC, 가능한 숫자의 비트를 B라 하자.

각 좌표별로 가능한 비트들을 저장 후 탐색을 이어나갈 수 있다.

이 경우 O(RC \* B)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표마다 비트세트를 저장하는데 O(RC \* B)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     469      | O(RC \* B)  | O(RC \* B)  |

각 좌표별로 가능한 XOR 값의 종류에 대해 방문 여부를 저장한다.

이후 탐색을 진행해가며 이를 갱신한 뒤 마지막 좌표에서 가능한 비트 중 가장 작은 값을 반환한다.

```cpp
int minCost(vector<vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid[0].size();

  vector<vector<vector<bool>>> dp(rows, vector<vector<bool>>(cols, vector<bool>(1024, false)));
  dp[0][0][grid[0][0]] = true;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int cur = grid[y][x];

      if (y - 1 >= 0) {
        for (int before = 0; before < 1024; before++) {
          if (!dp[y - 1][x][before]) continue;

          dp[y][x][cur ^ before] = true;
        }
      }

      if (x - 1 >= 0) {
        for (int before = 0; before < 1024; before++) {
          if (!dp[y][x - 1][before]) continue;

          dp[y][x][cur ^ before] = true;
        }
      }
    }
  }

  for (int before = 0; before < 1024; before++) {
    if (!dp[rows - 1][cols - 1][before]) continue;
    return before;
  }
  return -1;
}
```

## 고생한 점
