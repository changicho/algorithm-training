# 64. Minimum Path Sum

[링크](https://leetcode.com/problems/minimum-path-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 길이를 N, 열의 길이를 M이라고 하자.

모든 경우를 탐색할 경우 O(2^(N \* M))이므로 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전에 연산한 결과를 이용할 경우 O(N \* M)안에 풀이가 가능하다.

### 공간 복잡도

동적 계획법에서 모든 경로를 저장할 경우 O(N \* M)의 공간 복잡도가 필요하다.

한 칸씩 dp배열을 갱신하는것을 이용해 모든 공간이 아닌 하나의 행만 이용할 경우 O(N)의 시간 복잡도가 필요하다.

### 동적 계획법 (full)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N \* M)  |  O(N \* M)  |

최소한으로 목적지에 도달하기 위해선 한 좌표에서 아래와 오른쪽 으로만 이동이 가능하다.

따라서 현재 좌표의 최솟값은 현재 좌표에서 왼쪽에서 오는 경우, 위에서 오는 경우에서 최솟값인 경우이다.

따라서 일반 식은 다음과 같다.

```cpp
// 여기서 y-1 < 0이거나 x-1 < 0인 경우는 0을 더한다고 가정하자
dp[y][x] = grid[y][x] + min(dp[y - 1][x], dp[y][x - 1]);
```

초기값은 다음과 같다.

```cpp
dp[0][0] = grid[0][0];
for (int y = 1; y < row; y++) {
  dp[y][0] = dp[y - 1][0] + grid[y][0];
}
for (int x = 1; x < col; x++) {
  dp[0][x] = dp[0][x - 1] + grid[0][x];
}
```

위 공식을 이용해 dp 배열을 갱신한다.

```cpp
int minPathSum(vector<vector<int>>& grid) {
  int row = grid.size();
  int col = grid.front().size();

  vector<vector<int>> dp(row, vector<int>(col, 0));

  dp[0][0] = grid[0][0];

  for (int y = 1; y < row; y++) {
    dp[y][0] = dp[y - 1][0] + grid[y][0];
  }
  for (int x = 1; x < col; x++) {
    dp[0][x] = dp[0][x - 1] + grid[0][x];
  }

  for (int y = 1; y < row; y++) {
    for (int x = 1; x < col; x++) {
      dp[y][x] = grid[y][x] + min(dp[y - 1][x], dp[y][x - 1]);
    }
  }

  return dp[row - 1][col - 1];
}
```

### 동적 계획법 (one line)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N \* M)  |  O(N \* M)  |

모든 좌표에 대해 dp값을 구하는 경우를 잘 살펴보면 하나의 dp배열을 갱신하며 문제를 해결할 수 있다.

이는 현재 좌표의 최솟값은 현재 좌표에서 왼쪽에서 오는 경우, 위에서 오는 경우에서 최솟값인 경우만 이기 때문이다.

행에 대해서만 dp를 최적화 한다고하자.

이 경우 초기값은 다음과 같다.

```cpp
dp[0] = grid[0][0];
for (int y = 1; y < row; y++) {
  dp[y] = dp[y - 1] + grid[y][0];
}
```

현재 좌표를 (y, x)라고 하자.

여기서 y번째 행을 탐색할 때 직전 dp는 y-1번째 행까지의 dp이다.

또한 현재 좌표를 탐색할 때 dp는 현재 x-1까지 갱신된 dp이다.

따라서 dp의 값을 다음과 같이 나타낼 수 있다.

```cpp
dpFull[y-1][x] == dp[x]; // 위에서 내려온 값
dpFull[y][x-1] == dp[x-1]; // 왼쪽에서 온 값
```

따라서 일반식은 다음과 같이 나타낼 수 있다.

```cpp
dp[y] = min(dp[y - 1], dp[y]) + grid[y][x];
// x가 0일 때는 위에서 내려온 값만이다.
dp[0] += grid[0][x];
```

```cpp
int minPathSum(vector<vector<int>>& grid) {
  int row = grid.size();
  int col = grid.front().size();

  vector<int> dp(row, 0);

  dp[0] = grid[0][0];
  for (int y = 1; y < row; y++) {
    dp[y] = dp[y - 1] + grid[y][0];
  }

  for (int x = 1; x < col; x++) {
    dp[0] += grid[0][x];

    for (int y = 1; y < row; y++) {
      dp[y] = min(dp[y - 1], dp[y]) + grid[y][x];
    }
  }
  return dp[row - 1];
}
```

## 고생한 점
