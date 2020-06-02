#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct Day {
  int day, y, x;
};

Axis dirs[4] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};

bool visited[1001][1001];
int map[1001][1001];

void solution() {
  int N, M;
  int count = 0;
  int day = 0;
  queue<Day> q;

  cin >> M >> N;
  int total = M * N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> map[y][x];

      if (map[y][x] == 1) {
        count += 1;
        q.push({0, y, x});
        visited[y][x] = true;
      }

      if (map[y][x] == -1) {
        total -= 1;
      }
    }
  }

  while (!q.empty()) {
    Day cur = q.front();
    q.pop();
    day = cur.day;

    for (int d = 0; d < 4; d++) {
      Axis next = {cur.y, cur.x};
      next.y += dirs[d].y;
      next.x += dirs[d].x;

      if (next.x < 0 || next.x >= M || next.y < 0 || next.y >= N) {
        continue;
      }
      if (map[next.y][next.x] == -1) {
        continue;
      }
      if (visited[next.y][next.x]) {
        continue;
      }

      q.push({cur.day + 1, next.y, next.x});
      visited[next.y][next.x] = true;
      count += 1;
    }
  }

  if (count != total) {
    cout << "-1\n";
    return;
  }

  cout << day << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}