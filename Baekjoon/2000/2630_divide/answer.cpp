#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct axis {
  int y, x;
};

bool map[128][128];
int answer_white = 0;
int answer_blue = 0;

bool check(axis from, axis to) {
  bool target = map[from.y][from.x];

  for (int y = from.y; y < to.y; y++) {
    for (int x = from.x; x < to.x; x++) {
      if (map[y][x] != target) {
        return false;
      }
    }
  }
  if (target) {
    answer_blue += 1;
  } else {
    answer_white += 1;
  }
  return true;
}

// from : UP LEFT
// to : DOWN RIGHT
// N : length of square
void divide(axis from, axis to, int N) {
  if (N == 0) {
    return;
  }
  axis center = {from.y + N / 2, from.x + N / 2};

  if (!check(from, center)) {
    divide(from, center, N / 2);
  }
  if (!check(center, to)) {
    divide(center, to, N / 2);
  }

  if (!check({from.y, center.x}, {center.y, to.x})) {
    divide({from.y, center.x}, {center.y, to.x}, N / 2);
  }
  if (!check({center.y, from.x}, {to.y, center.x})) {
    divide({center.y, from.x}, {to.y, center.x}, N / 2);
  }
}

void solution() {
  int N;

  cin >> N;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> map[y][x];
    }
  }

  if (!check({0, 0}, {N, N})) {
    divide({0, 0}, {N, N}, N);
  }

  cout << answer_white << "\n" << answer_blue << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}