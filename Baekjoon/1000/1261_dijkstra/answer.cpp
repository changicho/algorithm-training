#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define MAX 100000

using namespace std;

struct Axis {
  int y;
  int x;
};

Axis moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int board[100][100];
int dist[100][100];

struct Status {
  Axis axis;
  int dist;

  bool operator<(const Status &b) const {
    return dist > b.dist;
  }
};

void dijkstra(Axis destination) {
  priority_queue<Status> pq;

  dist[0][0] = 0;
  pq.push({{0, 0}, dist[0][0]});

  while (!pq.empty()) {
    Status cur = pq.top();
    Axis axis = cur.axis;
    pq.pop();

    if (axis.y == destination.y && axis.x == destination.x) return;

    for (Axis move : moves) {
      Axis next = axis;
      next.y += move.y;
      next.x += move.x;

      if (next.y < 0 || next.y > destination.y || next.x < 0 || next.x > destination.x) continue;

      int new_dist = dist[axis.y][axis.x] + board[next.y][next.x];

      if (new_dist < dist[next.y][next.x]) {
        dist[next.y][next.x] = new_dist;
        pq.push({next, new_dist});
      }
    }
  }
}

void solution() {
  int N, M;

  cin >> N >> M;

  for (int y = 0; y < M; y++) {
    string line;
    cin >> line;
    for (int x = 0; x < N; x++) {
      board[y][x] = line[x] - '0';
      dist[y][x] = MAX;
    }
  }

  dijkstra({M - 1, N - 1});

  cout << dist[M - 1][N - 1] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}