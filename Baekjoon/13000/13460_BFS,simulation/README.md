# 13460. 구슬 탈출 2

[링크](https://www.acmicpc.net/problem/13460)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   25.586    |       2       |

## 설계

### 시간 복잡도

판의 크기는 최대 10^2 이다. 최대 10번 까지 4방향에 대해 탐색을 수행하므로 탐색의 횟수는 최대 4^10 이다.

각 탐색의 경우마다 구슬이 이동하는데 들어가는 시간 복잡도는 최대 O(10) 이다.

따라서 최악의 경우 모든 경우를 탐색 할 때의 시간 복잡도는 O(4^10 \* 10) = O(10,485,760) 이므로 제한시간 2초 내에 충분하다.

### 공간 복잡도

정답은 10 이내이므로 int형으로 관리한다.

### 공의 이동

공을 이동시킬 때는 다음 경우를 고려해야 한다.

- 공이 벽에 부딛힘
- 공이 구멍에 빠짐
- 공이 다른 공에 부딛힘

이 때 빨간공과 파란공은 동시에 움직여야한다.

이를 동시에 전부 처리하는 것보다 하나의 공을 2번 이동시키는 방법을 사용한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  vector<vector<char>> board;
  int step;
  Axis redBall, blueBall;
  bool redFall, blueFall;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isSafe(Axis a, int width, int height) {
  return !(a.y < 0 || a.y >= height || a.x < 0 || a.x >= width);
}
```

```cpp
Axis move_ball(vector<vector<char>> &board, Axis dir, Axis ball, Axis otherBall) {
  int height = board.size(), width = board[0].size();

  while (true) {
    Axis next = ball;
    next.y += dir.y;
    next.x += dir.x;

    if (!isSafe(next, width, height)) break;
    if (board[next.y][next.x] == '#') break;
    if (next.y == otherBall.y && next.x == otherBall.x) break;
    if (board[next.y][next.x] == 'O') {
      ball = {-1, -1};
      break;
    }
    ball = next;
  }

  return ball;
}
```

```cpp
Status move_board(vector<vector<char>> &board, Axis dir, int step, Axis redBall, Axis blueBall) {
  Status ret = {board, step + 1, redBall, blueBall, false, false};
  int height = board.size(), width = board[0].size();

  redBall = move_ball(board, dir, redBall, blueBall);
  blueBall = move_ball(board, dir, blueBall, redBall);
  redBall = move_ball(board, dir, redBall, blueBall);

  ret.redBall = redBall, ret.blueBall = blueBall;
  if (ret.redBall.y == -1 && ret.redBall.x == -1) ret.redFall = true;
  if (ret.blueBall.y == -1 && ret.blueBall.x == -1) ret.blueFall = true;

  return ret;
}
```

### 너비우선 탐색

이전에 방문한 경우 (두 공의 좌표) 탐색을 더이상 진행하지 않는다.

또한 파란 공이 빠진 경우에는 더이상 탐색을 진행하지 않는다.

```cpp
queue<Status> q;
q.push({board, 0, redBall, blueBall, false, false});
int answer = -1;

while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.step > 10) {
    answer = -1;
    break;
  }
  if (visited[cur.blueBall.y][cur.blueBall.x][cur.redBall.y][cur.redBall.x]) continue;
  if (cur.blueFall) continue;
  if (cur.redFall) {
    answer = cur.step;
    break;
  }
  visited[cur.blueBall.y][cur.blueBall.x][cur.redBall.y][cur.redBall.x] = true;

  for (Axis dir : dirs) {
    Status next = move_board(cur.board, dir, cur.step, cur.redBall, cur.blueBall);

    q.push(next);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
