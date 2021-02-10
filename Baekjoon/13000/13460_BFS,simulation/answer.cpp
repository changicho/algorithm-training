#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

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

void solution() {
  int N, M;
  bool visited[10][10][10][10] = {
      false,
  };
  cin >> N >> M;

  Axis redBall, blueBall;

  vector<vector<char>> board(N, vector<char>(M));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> board[y][x];

      if (board[y][x] == 'R') {
        redBall = {y, x};
        board[y][x] = '.';
      } else if (board[y][x] == 'B') {
        blueBall = {y, x};
        board[y][x] = '.';
      }
    }
  }

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

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}