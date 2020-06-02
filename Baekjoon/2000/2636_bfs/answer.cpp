#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

array<Axis, 4> dirs = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

bool map[100][100];
bool visited[100][100];

void solution() {
  int Y, X;
  int day = 0;
  int answer;

  queue<Axis> q;
  queue<Axis> melts;

  cin >> Y >> X;

  for (int y = 0; y < Y; y++) {
    for (int x = 0; x < X; x++) {
      cin >> map[y][x];
    }
  }

  while (true) {
    memset(visited, 0, sizeof(visited));
    q.push({0, 0});

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (next.x < 0 || next.x >= X || next.y < 0 || next.y >= Y) {
          continue;
        }
        if (visited[next.y][next.x]) {
          continue;
        }

        visited[next.y][next.x] = 1;

        if (!map[next.y][next.x]) {
          q.push(next);
        } else {
          melts.push(next);
        }
      }
    }

    if (melts.empty()) {
      break;
    }

    answer = melts.size();

    while (!melts.empty()) {
      Axis cur = melts.front();
      melts.pop();
      map[cur.y][cur.x] = 0;
    }

    day += 1;
  }

  cout << day << "\n";
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}