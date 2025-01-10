# D - Snaky Walk

[링크](https://atcoder.jp/contests/abc387/tasks/abc387_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 크기를 W * H라 하자.

각 칸마다 BFS를 수행하며 탐색할 경우 시간 복잡도는 O(W \* H) 이다.

이 때 하나의 좌표에 진입 방향 4가지 상태가 존재함에 유의한다.

### 공간 복잡도

BFS에 O(W \* H)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     222      |  O(W \* H)  |  O(W \* H)  |

snake는 현재 바라보는 방향에서 90도 회전한 방향으로만 이동할 수 있다.

따라서 BFS를 수행할 때 현재 방향에서 90도 회전한 방향으로만 이동할 수 있도록 구현한다.

이 때 각 좌표와 진입 방향에 대해 dp를 이용해 최소 이동 횟수를 저장한다.

이후 목적지의 각 방향별로 최소 이동 횟수를 구해 정답을 구한다.

```cpp
struct Axis {
  int x, y;

  Axis operator+(const Axis &a) const { return {x + a.x, y + a.y}; }
};

struct Status {
  Axis a;
  int dir;
  int step = 0;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int solution(vector<string> &board, int rows, int cols) {
  vector<vector<vector<int>>> dp(
      rows, vector<vector<int>>(cols, vector<int>(4, INT_MAX)));

  Axis start = {-1, -1}, goal = {-1, -1};

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'S') {
        start = {x, y};
      } else if (board[y][x] == 'G') {
        goal = {x, y};
      }
    }
  }

  queue<Status> q;
  for (int dir = 0; dir < 4; dir++) {
    q.push({start, dir, 0});
    dp[start.y][start.x][dir] = 0;
  }

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.a.x == goal.x && cur.a.y == goal.y) {
      dp[cur.a.y][cur.a.x][cur.dir] = cur.step;
      continue;
    }

    vector<int> nextDirs;
    if (cur.dir == 0 || cur.dir == 2) {
      nextDirs = {1, 3};
    } else {
      nextDirs = {0, 2};
    }

    for (int &dir : nextDirs) {
      Axis next = cur.a + dirs[dir];
      if (next.x < 0 || next.x >= cols || next.y < 0 || next.y >= rows)
        continue;
      if (board[next.y][next.x] == '#') continue;

      int nextStep = cur.step + 1;
      if (dp[next.y][next.x][dir] <= nextStep) {
        continue;
      }

      dp[next.y][next.x][dir] = nextStep;
      q.push({next, dir, nextStep});
    }
  }

  int answer = INT_MAX;
  for (int dir = 0; dir < 4; dir++) {
    answer = min(answer, dp[goal.y][goal.x][dir]);
  }
  return answer == INT_MAX ? -1 : answer;
}
```

## 고생한 점
