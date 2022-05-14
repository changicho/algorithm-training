#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// time : O(N * M + Q)
// space : O(N * M)
int main() {
  std::ios_base::sync_with_stdio(false);

  // freopen("./input.txt", "r", stdin);

  int rows, cols, queries;
  int iconSize = 0;

  cin >> rows >> cols >> queries;

  vector<string> board(rows);
  for (int y = 0; y < rows; y++) {
    cin >> board[y];

    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '*') iconSize++;
    }
  }

  string line = "";
  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      line += board[y][x];
    }
  }

  int fillLeft = count(line.begin(), line.begin() + iconSize, '.');
  for (int i = 0; i < queries; i++) {
    int y, x;
    cin >> y >> x;
    x--, y--;

    int index = y + x * rows;

    if (line[index] == '.') {
      line[index] = '*';
      if (index < iconSize) {
        fillLeft--;
      }
      iconSize++;
      // check last axis
      if (line[iconSize - 1] == '.') {
        fillLeft++;
      }
    } else {
      line[index] = '.';
      if (index < iconSize) {
        fillLeft++;
      }
      iconSize--;
      // check last over axis
      if (line[iconSize] == '.') {
        fillLeft--;
      }
    }

    cout << fillLeft << "\n";
  }

  return 0;
}