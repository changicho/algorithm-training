#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

string recursive(Axis from, Axis to, vector<string> &board) {
  if (from.y + 1 == to.y && from.x + 1 == to.x) {
    string ret = "";
    return ret + board[from.y][from.x];
  }

  char target = board[from.y][from.x];
  bool canCompact = true;
  for (int y = from.y; y < to.y; y++) {
    for (int x = from.x; x < to.x; x++) {
      if (board[y][x] == target) continue;

      canCompact = false;
      break;
    }
    if (!canCompact) break;
  }

  if (canCompact) {
    string ret = "";
    return ret + board[from.y][from.x];
  }

  int mid = abs(to.y - from.y) / 2;

  string upperLeft = recursive(from, {from.y + mid, from.x + mid}, board);
  string upperRight = recursive({from.y, from.x + mid}, {from.y + mid, to.x}, board);
  string lowerLeft = recursive({from.y + mid, from.x}, {to.y, from.x + mid}, board);
  string lowerRight = recursive({from.y + mid, from.x + mid}, to, board);

  return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}

void solution() {
  int N;
  vector<string> board;

  cin >> N;
  board.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  string answer = recursive({0, 0}, {N, N}, board);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}