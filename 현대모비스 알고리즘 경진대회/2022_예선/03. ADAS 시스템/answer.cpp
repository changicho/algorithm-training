#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Point {
  Axis axis;
  int rank;  // E:4, P:3, normal:2

  bool operator<(const Point &b) const {
    // compare rank
    if (rank != b.rank) {
      return rank < b.rank;
    }
    if (axis.y != b.axis.y) {
      return axis.y > b.axis.y;
    }
    return axis.x > b.axis.x;
  }
};

int getRank(char c) {
  if (c == 'E') return 4;
  if (c == 'P') return 3;
  return 2;
}

int getDangerScore(vector<string> &board, Axis axis) {
  int rows = board.size(), cols = board[0].size();

  char target = board[axis.y][axis.x];
  if (target == 'S' || target == 'E') return 0;

  int ret = 0;
  for (int y = -1; y <= 1; y++) {
    for (int x = -1; x <= 1; x++) {
      if (y == 0 && x == 0) continue;

      Axis cur = {axis.y + y, axis.x + x};
      if (cur.y < 0 || cur.y >= rows || cur.x < 0 || cur.x >= cols) continue;
      if (board[cur.y][cur.x] == 'P') {
        ret++;
      }
    }
  }
  if (target == 'P') ret -= 3;
  return ret;
}

long long solution(vector<string> &board) {
  int rows = board.size(), cols = board[0].size();
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  long long ret = 0;
  Axis start = {-1, -1};
  for (int y = 0; y < rows && start.y == -1; y++) {
    for (int x = 0; x < cols && start.x == -1; x++) {
      if (board[y][x] == 'S') {
        start = {y, x};
        break;
      }
    }
  }

  priority_queue<Point> pq;
  pq.push({start, -1});

  while (!pq.empty()) {
    Point cur = pq.top();
    pq.pop();

    if (visited[cur.axis.y][cur.axis.x]) continue;
    visited[cur.axis.y][cur.axis.x] = true;

    ret += getDangerScore(board, cur.axis);

    if (board[cur.axis.y][cur.axis.x] == 'E') break;

    for (Axis &dir : dirs) {
      Axis next = {cur.axis.y + dir.y, cur.axis.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x] == true) continue;

      pq.push({next, getRank(board[next.y][next.x])});
    }
  }

  return max(ret, 0LL);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int W, H;
  cin >> W >> H;

  vector<string> board(W);
  for (int y = 0; y < W; y++) {
    cin >> board[y];
  }

  long long answer = solution(board);
  cout << answer << "\n";
  return 0;
}