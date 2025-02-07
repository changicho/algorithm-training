#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

/**
 * # : black
 * . : white
 * ? : unknown
 */
bool solution(int rows, int cols, vector<string> &board) {
  Axis topLeft = {INT_MAX, INT_MAX};
  Axis bottomRight = {INT_MIN, INT_MIN};

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] != '#') continue;

      topLeft.y = min(topLeft.y, y);
      topLeft.x = min(topLeft.x, x);

      bottomRight.y = max(bottomRight.y, y);
      bottomRight.x = max(bottomRight.x, x);
    }
  }

  for (int y = topLeft.y; y <= bottomRight.y; y++) {
    for (int x = topLeft.x; x <= bottomRight.x; x++) {
      if (board[y][x] == '.') return false;
    }
  }

  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W;
  cin >> H >> W;

  vector<string> board(H);

  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }

  bool answer = solution(H, W, board);

  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}