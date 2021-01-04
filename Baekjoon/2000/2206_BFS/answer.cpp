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
  int cost;
  bool useBreak;
};

Axis moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M;
bool board[1000][1000];
bool visited[1000][1000][2];
int costs[1000][1000][2];

void solution() {
  int answer = -1;

  cin >> N >> M;

  string line;
  for (int y = 0; y < N; y++) {
    cin >> line;

    for (int x = 0; x < M; x++) {
      board[y][x] = line[x] == '0' ? false : true;
    }
  }

  queue<Status> q;
  q.push({{0, 0}, 1, false});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.axis.y == N - 1 && cur.axis.x == M - 1) {
      answer = cur.cost;
      break;
    }
    if (visited[cur.axis.y][cur.axis.x][cur.useBreak]) continue;
    visited[cur.axis.y][cur.axis.x][cur.useBreak] = true;
    costs[cur.axis.y][cur.axis.x][cur.useBreak] = cur.cost;

    for (Axis move : moves) {
      Status next = cur;
      next.axis.y += move.y;
      next.axis.x += move.x;
      next.cost += 1;

      if (next.axis.y < 0 || next.axis.y >= N || next.axis.x < 0 || next.axis.x >= M) continue;
      if (board[next.axis.y][next.axis.x]) {
        if (next.useBreak) continue;
        next.useBreak = true;
        q.push(next);
        continue;
      }

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