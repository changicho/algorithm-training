#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

string board[100];
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N;

int BFS(bool isDisabled) {
  bool visited[100][100] = {
      false,
  };
  int count = 0;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (visited[y][x]) continue;

      char color = board[y][x];
      queue<Axis> q;
      q.push({y, x});
      count += 1;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) continue;

          if (!isDisabled) {
            if (board[next.y][next.x] != color) continue;

            q.push(next);
          } else {
            if ((color == 'R' && board[next.y][next.x] == 'G') || (color == 'G' && board[next.y][next.x] == 'R')) {
              q.push(next);

              continue;
            }
            if (board[next.y][next.x] != color) continue;

            q.push(next);
          }
        }
      }
    }
  }

  return count;
}

void solution() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    cin >> board[y];
  }

  cout << BFS(false) << " " << BFS(true) << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}