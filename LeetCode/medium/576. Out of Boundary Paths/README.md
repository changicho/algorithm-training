# 576. Out of Boundary Paths

[링크](https://leetcode.com/problems/out-of-boundary-paths/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 좌표의 크기를 M \* N, 이동 횟수를 K라 하자.

모든 경우를 직접 구할 경우 제한시간 내에 불가능하다. 따라서 동적 계획법을 이용한다.

이 경우 각 이동횟수 별 좌표마다의 도달 횟수를 구해야 한다.

각 좌표마다 상,하,좌,우 4가지 방향으로 뻗어나갈 수 있으므로 각 경우마다 O(N \* M)의 시간 복잡도를 사용한다.

이를 K번 반복하므로 시간 복잡도는 O(N \* M \* K)이다.

### 공간 복잡도

동적 계획법에 사용할 dp배열의 크기는 O(N \* M \* K)이다.

### 동적 계획법

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도   |
| :----------: | :------------: | :------------: |
|      3       | O(N \* M \* K) | O(N \* M \* K) |

이동 횟수마다의 각 좌표마다의 도달 횟수를 구할 수 있다.

이 경우 다음 이동 횟수를 갱신할 때 범위를 벗어나는 경우에 대해서 정답에 더할 수 있다.

이 때 좌표당 도달 횟수가 int형을 벗어날 수 있으므로 MOD로 나눠준다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

const int MOD = 1e9 + 7;

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
  // step, y, x;
  int dp[51][51][51] = {
      0,
  };

  int answer = 0;

  dp[0][startRow][startColumn] = 1;

  for (int step = 0; step < maxMove; step++) {
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        if (dp[step][y][x] == 0) continue;

        for (Axis &dir : dirs) {
          Axis next = {y + dir.y, x + dir.x};

          if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n) {
            answer += dp[step][y][x];
            answer %= MOD;

            continue;
          }
          if (step + 1 >= maxMove) continue;
          dp[step + 1][next.y][next.x] += dp[step][y][x];
          dp[step + 1][next.y][next.x] %= MOD;
        }
      }
    }
  }

  return answer;
}
```

## 고생한 점
