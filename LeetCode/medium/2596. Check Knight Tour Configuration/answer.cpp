#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  bool canMove(Axis &from, Axis &to) {
    int yDiff = abs(from.y - to.y), xDiff = abs(from.x - to.x);
    if (yDiff == 2 && xDiff == 1) return true;
    if (yDiff == 1 && xDiff == 2) return true;
    return false;
  }

 public:
  bool checkValidGrid(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid.front().size();
    vector<Axis> moves(rows * cols);

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int idx = grid[y][x];

        moves[idx] = {y, x};
      }
    }

    // check start point is correct
    if (moves[0].y != 0 || moves[0].x != 0) return false;

    for (int i = 0; i < moves.size() - 1; i++) {
      if (!canMove(moves[i], moves[i + 1])) return false;
    }
    return true;
  }
};