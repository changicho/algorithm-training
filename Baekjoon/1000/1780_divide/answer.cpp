#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int answers[3];
int board[2187][2187];

void recursive(Axis from, Axis to) {
  if (from.y + 1 == to.y && from.x + 1 == to.x) {
    answers[board[from.y][from.x] + 1] += 1;
    return;
  }

  int target = board[from.y][from.x];
  bool isSame = true;
  for (int y = from.y; y < to.y; y++) {
    for (int x = from.x; x < to.x; x++) {
      if (target == board[y][x]) continue;
      isSame = false;
      break;
    }
    if (!isSame) break;
  }

  if (isSame) {
    answers[target + 1] += 1;
    return;
  }

  int size = (to.y - from.y) / 3;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      recursive({from.y + size * i, from.x + size * j}, {from.y + size * (i + 1), from.x + size * (j + 1)});
    }
  }
}

void solution() {
  int N;
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  recursive({0, 0}, {N, N});

  for (int answer : answers) {
    cout << answer << "\n";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}