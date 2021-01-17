#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

bool board[3072 + 1][6144 - 1 + 1];

void recursive(Axis top, Axis bottomLeft, Axis bottomRight) {
  Axis midLeft, midRight, midBottom;

  midBottom = {bottomLeft.y, top.x};
  midLeft = {(bottomLeft.y + top.y) / 2, (bottomLeft.x + midBottom.x - 1) / 2 + 1};
  midRight = {(bottomRight.y + top.y) / 2, (bottomRight.x + midBottom.x + 1) / 2 - 1};

  // cout << top.y << "," << top.x << " " << bottomLeft.y << "," << bottomLeft.x << " " << bottomRight.y << "," << bottomRight.x << endl;

  if (bottomLeft.y - top.y == 2) {
    board[top.y][top.x] = board[top.y + 1][top.x - 1] = board[top.y + 1][top.x + 1] = 1;

    for (int x = bottomLeft.x; x <= bottomRight.x; x++) {
      board[bottomLeft.y][x] = 1;
    }
    return;
  }

  recursive(top, midLeft, midRight);
  recursive({midLeft.y + 1, midLeft.x - 1}, bottomLeft, {midBottom.y, midBottom.x - 1});
  recursive({midRight.y + 1, midRight.x + 1}, {midBottom.y, midBottom.x + 1}, bottomRight);
}

void solution() {
  int N;
  cin >> N;

  int size = N * 2 - 1;
  Axis top = {0, size / 2}, bottomLeft = {N - 1, 0}, bottomRight = {N - 1, size - 1};

  recursive(top, bottomLeft, bottomRight);

  for (int y = 0; y < N; y++) {
    string line;
    line.resize(2 * N - 1, ' ');

    for (int x = 0; x < 2 * N - 1; x++) {
      if (board[y][x] == 1) line[x] = '*';
    }
    cout << line << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}