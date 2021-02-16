#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int R, C;
char board[20][20];
int answer = 0;

bool isSafe(Axis cur) {
  return !(cur.y < 0 || cur.y >= R || cur.x < 0 || cur.x >= C);
}

void recursive(Axis cur, bool alpha_visited[], int count) {
  answer = max(answer, count);

  alpha_visited[board[cur.y][cur.x]] = true;
  for (Axis dir : dirs) {
    Axis next = cur;
    next.y += dir.y;
    next.x += dir.x;

    if (!isSafe(next)) continue;
    char alpha = board[next.y][next.x];
    if (alpha_visited[alpha]) continue;

    recursive(next, alpha_visited, count + 1);
  }
  alpha_visited[board[cur.y][cur.x]] = false;
}

void solution() {
  cin >> R >> C;

  Axis start = {0, 0};

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      cin >> board[y][x];
    }
  }

  bool alpha_visited['Z' + 1] = {
      false,
  };
  recursive(start, alpha_visited, 1);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}