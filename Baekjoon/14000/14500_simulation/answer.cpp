#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

vector<Axis> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
Axis limit;
int map[501][501];
bool visited[501][501];
int answer = 0;

void dfs(int index, Axis cur, int count) {
  if (index == 4) {
    answer = max(answer, count);
    return;
  }

  int dir = 0;
  if (index == 0) {
    dir += 1;
  }

  for (; dir < 4; dir++) {
    Axis next = cur;
    next.x += dirs[dir].x;
    next.y += dirs[dir].y;

    if (next.x < 0 || next.x >= limit.x || next.y < 0 || next.y >= limit.y) {
      continue;
    }
    if (visited[next.y][next.x]) {
      continue;
    }

    visited[next.y][next.x] = true;
    dfs(index + 1, next, count + map[next.y][next.x]);
    visited[next.y][next.x] = false;
  }
};

void checkT(Axis cur) {
  if (cur.x + 3 < limit.x) {
    int line =
        map[cur.y][cur.x] + map[cur.y][cur.x + 1] + map[cur.y][cur.x + 2];

    if (cur.y - 1 >= 0) {
      int temp = line + map[cur.y - 1][cur.x + 1];
      answer = max(answer, temp);
    }

    if (cur.y + 1 < limit.y) {
      int temp = line + map[cur.y + 1][cur.x + 1];
      answer = max(answer, temp);
    }
  }

  if (cur.y + 3 < limit.y) {
    int line =
        map[cur.y][cur.x] + map[cur.y + 1][cur.x] + map[cur.y + 2][cur.x];

    if (cur.x - 1 >= 0) {
      int temp = line + map[cur.y + 1][cur.x - 1];
      answer = max(answer, temp);
    }

    if (cur.x + 1 < limit.x) {
      int temp = line + map[cur.y + 1][cur.x + 1];
      answer = max(answer, temp);
    }
  }
}

void solution() {
  cin >> limit.y >> limit.x;

  for (int y = 0; y < limit.y; y++) {
    for (int x = 0; x < limit.x; x++) {
      cin >> map[y][x];
    }
  }

  for (int y = 0; y < limit.y; y++) {
    for (int x = 0; x < limit.x; x++) {
      Axis cur = {y, x};

      dfs(0, cur, 0);
      checkT(cur);
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