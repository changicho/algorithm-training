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
  int N;
  int board[100][100];

  cin >> N;

  int minimum = 0, maximum = 100;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
      minimum = min(minimum, board[y][x]);
      maximum = max(maximum, board[y][x]);
    }
  }

  for (int level = minimum; level <= maximum; level++) {
    bool visited[100][100] = {
        false,
    };
    int count = 0;

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        visited[y][x] = board[y][x] >= level ? 0 : 1;
      }
    }

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (visited[y][x]) continue;
        count += 1;

        queue<Axis> q;
        q.push({y, x});

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          if (visited[cur.y][cur.x]) continue;
          visited[cur.y][cur.x] = true;

          for (Axis dir : dirs) {
            Axis next = cur;
            next.x += dir.x;
            next.y += dir.y;

            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N) continue;

            q.push(next);
          }
        }
      }
    }

    answer = max(answer, count);
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