#include <algorithm>
#include <iostream>

using namespace std;

struct axis {
  int y, x;
};

axis moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char map[20][20];
int answer, R, C, MAX;
bool visited['Z' - 'A'];

void clear() {
  for (int i = 0; i < 'Z' - 'A'; i++) {
    visited[i] = 0;
  }
  answer = 1, MAX = 0;
}

void dfs(axis current, int count) {
  answer = max(answer, count);

  if (answer > MAX) {
    return;
  }

  visited[map[current.y][current.x] - 'A'] = 1;

  for (int dir = 0; dir < 4; dir++) {
    axis next = current;
    next.x += moves[dir].x;
    next.y += moves[dir].y;

    if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C ||
        visited[map[next.y][next.x] - 'A']) {
      continue;
    }

    dfs(next, count + 1);
  }

  visited[map[current.y][current.x] - 'A'] = 0;
}

void solution(int test_case) {
  clear();
  cin >> R >> C;

  bool alphabets['Z' - 'A'] = {
      0,
  };

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      cin >> map[y][x];
      alphabets[map[y][x] - 'A'] = 1;
    }
  }

  for (bool b : alphabets) {
    b ? MAX += 1 : MAX;
  }

  dfs(axis{0, 0}, 1);

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}