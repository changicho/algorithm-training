# 2304. Minimum Path Cost in a Grid

[링크](https://leetcode.com/problems/minimum-path-cost-in-a-grid/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 M \* N이라 하자.

모든 경우를 직접 탐색할 경우 경우의 수는 N^(M \* N)가지 경우의 수를 모두 탐색해야 한다.

이는 제한시간 내에 불가능하므로 동적 계획법을 이용한다.

이 경우 O(M \* N)크기의 배열을 각 index를 순회하며 채워넣으면 된다.

이 때 한 노드에서 다음 row의 노드로 가는 경우의 수는 N가지 이므로, 다음 값을 갱신할 때 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(M \* N^2)이다.

### 공간 복잡도

동적 계획법에 O(M \* N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     525      | O(M \* N^2) |  O(M \* N)  |

다음과 같은 dp를 생성한다.

```cpp
dp[y][x]; // y, x 좌표까지 도달하는 경로의 최소값

// 일반식
int idx = grid[y][x];

for (int next = 0; next < cols; next++) {
  dp[y + 1][next] = min(dp[y + 1][next], dp[y][x] + moveCost[idx][next] + grid[y][x]);
}

// 초기값
dp[0][x] = 0;
```

이를 이용해 각 좌표를 순회하며 각 좌표마다 다음 row의 좌표들로 연결된 path의 경로들을 갱신한다.

이를 구현하면 다음과 같다.

```cpp
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
  int rows = grid.size(), cols = grid.front().size();

  vector<vector<long>> dp(rows, vector<long>(cols, INT_MAX));
  for (int x = 0; x < cols; x++) {
    dp[0][x] = 0;
  }

  for (int y = 0; y < rows - 1; y++) {
    for (int x = 0; x < cols; x++) {
      // y, x
      int idx = grid[y][x];

      for (int next = 0; next < cols; next++) {
        dp[y + 1][next] =
            min(dp[y + 1][next], dp[y][x] + moveCost[idx][next] + grid[y][x]);
      }
    }
  }
  for (int x = 0; x < cols; x++) {
    dp[rows - 1][x] += grid[rows - 1][x];
  }

  int answer = dp[rows - 1][cols - 1];
  for (int x = 0; x < cols; x++) {
    answer = min(answer, (int)dp[rows - 1][x]);
  }
  return answer;
}
```

## 고생한 점
