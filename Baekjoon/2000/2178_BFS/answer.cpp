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
  Axis axis;
  int depth;
};

int N;
string board[100];
Axis limit;
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isSafe(Axis cur) {
  if (cur.y < 0 || cur.y >= limit.y || cur.x < 0 || cur.x >= limit.x) return false;
  return true;
}

void solution() {
  bool visited[100][100] = {
      false,
  };
  int N, M;
  int answer = 0;
  cin >> N >> M;

  limit = {N, M};

  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  queue<Status> q;
  q.push({{0, 0}, 1});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (visited[cur.axis.y][cur.axis.x]) continue;
    visited[cur.axis.y][cur.axis.x] = true;

    if (cur.axis.y == N - 1 && cur.axis.x == M - 1) {
      answer = cur.depth;
      break;
    }

    for (Axis dir : dirs) {
      Status next = {cur.axis, cur.depth + 1};
      next.axis.y += dir.y;
      next.axis.x += dir.x;

      if (!isSafe(next.axis)) continue;
      if (board[next.axis.y][next.axis.x] == '0') continue;

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