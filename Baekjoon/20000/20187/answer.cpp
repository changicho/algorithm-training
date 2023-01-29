#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 1e9 + 1;

// 0 1
// 2 3
int solution(int size, vector<char> &folds, int hole) {
  bool isRowReversed = false, isColReversed = false;

  for (char &f : folds) {
    if (f == 'D' && !isRowReversed) {
      isRowReversed = true;
    } else if (f == 'U' && isRowReversed) {
      isRowReversed = false;
    } else if (f == 'R' && !isColReversed) {
      isColReversed = true;
    } else if (f == 'L' && isColReversed) {
      isColReversed = false;
    }
  }

  int ret = hole;
  int y = hole / 2;
  int x = hole % 2;

  if (isRowReversed) {
    y += 1;
    y %= 2;
  }
  if (isColReversed) {
    x += 1;
    x %= 2;
  }

  return y * 2 + x;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int K, H;
  cin >> K;

  vector<char> folds(2 * K);
  for (int i = 0; i < 2 * K; i++) {
    cin >> folds[i];
  }

  cin >> H;

  // number of 0,0
  int answer = solution(K, folds, H);

  int size = 1 << K;
  int start = answer;

  int board[1 << 8][1 << 8] = {-1};
  board[0][0] = start;

  for (int y = 0; y < size; y++) {
    if (y > 0) {
      board[y][0] = (board[y - 1][0] + 2) % 4;
    }
    for (int x = 1; x < size; x++) {
      board[y][x] =
          board[y][x - 1] % 2 == 0 ? board[y][x - 1] + 1 : board[y][x - 1] - 1;
    }
  }

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      cout << board[y][x] << " ";
    }
    cout << "\n";
  }

  // cout << answer << "\n";

  return 0;
}
