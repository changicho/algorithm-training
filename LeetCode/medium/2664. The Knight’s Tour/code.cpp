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

// use DFS with backtracking
// time : O(8^(R * C))
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[8] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1},
                  {-1, 2},  {1, 2},  {-2, 1},  {2, 1}};

  bool findAnswer = false;

  void recursive(vector<vector<int>> &board, int index, Axis a) {
    int rows = board.size(), cols = board[0].size();

    if (index == rows * cols - 1) {
      findAnswer = true;
      return;
    }

    for (Axis &dir : dirs) {
      Axis next = {a.y + dir.y, a.x + dir.x};
      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] != -1) continue;

      board[next.y][next.x] = index + 1;
      recursive(board, index + 1, next);
      if (findAnswer) return;

      board[next.y][next.x] = -1;
    }
  }

 public:
  vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
    vector<vector<int>> board(m, vector<int>(n, -1));

    board[r][c] = 0;

    recursive(board, 0, {r, c});

    return board;
  }
};