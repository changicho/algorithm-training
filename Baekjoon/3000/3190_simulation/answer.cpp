#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define APPLE 2
#define BODY 1

using namespace std;

struct Axis {
  int y, x;
};

struct Snake {
  queue<Axis> body;
  int direction;
};

struct Move {
  int time, change;
};

int board[101][101];
Axis dirs[4] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};

void solution() {
  int N, K, L;
  long long time = 0;
  Snake snake;
  queue<Move> moves;

  snake.body.push({0, 0});
  board[0][0] = BODY;
  snake.direction = 0;

  cin >> N >> K;

  for (int apple = 0; apple < K; apple++) {
    int y, x;
    cin >> y >> x;

    board[y - 1][x - 1] = APPLE;
  }

  cin >> L;

  for (int move = 0; move < L; move++) {
    Move cur;
    int X;
    char C;

    cin >> X >> C;
    cur.time = X;
    cur.change = C == 'L' ? -1 : +1;

    moves.push(cur);
  }

  while (true) {
    time += 1;

    Axis next = snake.body.back();
    next.x += dirs[snake.direction].x;
    next.y += dirs[snake.direction].y;

    // 벽과 부딛히면 게임 끝
    if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N) {
      break;
    }

    // 자기 자신과 부딛히면 게임 끝
    if (board[next.y][next.x] == BODY) {
      break;
    }

    if (board[next.y][next.x] == APPLE) {
      board[next.y][next.x] = 0;
    } else {
      board[snake.body.front().y][snake.body.front().x] = 0;
      snake.body.pop();
    }

    // 몸 길이 증가
    snake.body.push(next);
    board[next.y][next.x] = BODY;

    if (time == moves.front().time) {
      snake.direction += moves.front().change + 4;
      snake.direction %= 4;
      moves.pop();
    }
  }

  cout << time << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}