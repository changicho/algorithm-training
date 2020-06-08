#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis limit;
bool board[6561][6561];

void req(Axis start, Axis end) {
  if (end.x - start.x == 3 && end.y - start.y == 3) {
    for (int y = start.y; y < end.y; y++) {
      for (int x = start.x; x < end.x; x++) {
        board[y][x] = true;
      }
    }
    board[start.y + 1][start.x + 1] = false;
    return;
  }

  Axis tri = {(end.y - start.y) / 3, (end.x - start.x) / 3};

  for (int y = start.y; y < end.y; y += tri.y) {
    for (int x = start.x; x < end.x; x += tri.x) {
      if (y == start.y + tri.y && x == start.x + tri.x) {
        continue;
      }
      Axis from = {y, x};
      Axis to = {y + tri.y, x + tri.x};

      req(from, to);
    }
  }
}

void solution() {
  cin >> limit.y;
  limit.x = limit.y;

  req({0, 0}, limit);

  for (int y = 0; y < limit.y; y++) {
    for (int x = 0; x < limit.x; x++) {
      cout << (board[y][x] ? "*" : " ");
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}