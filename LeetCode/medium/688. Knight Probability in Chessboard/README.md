# 688. Knight Probability in Chessboard

[링크](https://leetcode.com/problems/knight-probability-in-chessboard/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C, 이동할 횟수를 K라 하자.

모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

각 좌표와 이동 횟수에 대해서 동적 계획법을 사용할 수 있다.

이 경우 O(R \* C \* K)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(R \* C \* K)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도   |
| :----------: | :------------: | :------------: |
|      8       | O(R \* C \* K) | O(R \* C \* K) |

이동 횟수마다 각 좌표에 도달하는 확률은 다음과 같이 구할 수 있다.

- 이전 이동 횟수에서 각 좌표마다의 확률을 알고있다.
- 하나의 좌표에서 다음 좌표로 이동하는 경우는 8가지이다.
- 현재 좌표로 이동 가능한 좌표의 이전 이동 횟수에서의 확률을 더해준다.
- 이 때 해당 확률에서 8을 나눈 값을 더해준다. (8가지 경우 중 한가지 이므로)

이를 이용해 다음과 같이 동적 계획법을 수행한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[8] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

double knightProbability(int n, int k, int row, int column) {
  double dp[26][26][101] = {
      0,
  };

  dp[row][column][0] = 1.0;

  for (int step = 1; step <= k; step++) {
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        if (dp[y][x][step - 1] == 0) continue;

        Axis cur = {y, x};
        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
            continue;
          dp[next.y][next.x][step] += dp[cur.y][cur.x][step - 1] / 8.0;
        }
      }
    }
  }

  double answer = 0;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      answer += dp[y][x][k];
    }
  }
  return answer;
}
```

## 고생한 점

BFS로 좌표별 탐색시 중복좌표를 방문할 수 있으므로, 이를 방지하기 위해 visited 배열을 사용해야 한다.
