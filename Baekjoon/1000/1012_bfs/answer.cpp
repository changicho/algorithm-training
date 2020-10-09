#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solution() {
  int answer = 0;
  bool board[50][50]{
      false,
  };
  bool visited[50][50]{
      false,
  };
  int M, N, K;
  cin >> M >> N >> K;

  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    board[y][x] = 1;
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (!board[y][x] || visited[y][x]) continue;

      answer += 1;
      queue<Axis> q;

      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
          if (!board[next.y][next.x]) continue;

          q.push(next);
        }
      }
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T != 0) {
    solution();
    T--;
  }

  return 0;
}