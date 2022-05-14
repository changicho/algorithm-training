#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dp dfs with backtracking
// time : O(R * C * (R + C))
// space : O(R * C * (R + C))
class Solution {
 private:
  struct Axis {
    int y, x;
  };
  Axis dirs[2] = {{0, 1}, {1, 0}};  // only right, down

  bool isAppear[101][101][201];

  void dfs(Axis axis, vector<vector<char>> &grid, int openCount) {
    int rows = grid.size(), cols = grid.front().size();

    if (grid[axis.y][axis.x] == '(') {
      openCount++;
    } else {
      openCount--;
    }

    if (openCount < 0) return;
    if (isAppear[axis.y][axis.x][openCount]) return;
    isAppear[axis.y][axis.x][openCount] = true;

    for (Axis &d : dirs) {
      Axis next = {axis.y + d.y, axis.x + d.x};
      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;

      dfs(next, grid, openCount);
    }
  }

 public:
  bool hasValidPath(vector<vector<char>> &grid) {
    int rows = grid.size(), cols = grid.front().size();

    dfs({0, 0}, grid, 0);

    return isAppear[rows - 1][cols - 1][0];
  }
};

// use dp
// time : O(R * C * (R + C))
// space : O(R * C * (R + C))
class Solution {
 public:
  bool hasValidPath(vector<vector<char>> &grid) {
    int rows = grid.size(), cols = grid.front().size();
    // edge case
    if (grid[0][0] == ')') return false;

    // need to initialize for all test case
    // isAppear[y][x][openCount]
    bool isAppear[101][101][201] = {
        false,
    };
    isAppear[0][0][1] = true;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int cur = grid[y][x] == '(' ? 1 : -1;

        for (int before = 0; before <= 200; before++) {
          if (before + cur < 0) continue;
          // from up
          if (y - 1 >= 0 && isAppear[y - 1][x][before]) {
            isAppear[y][x][before + cur] = true;
          }
          // from left
          if (x - 1 >= 0 && isAppear[y][x - 1][before]) {
            isAppear[y][x][before + cur] = true;
          }
        }
      }
    }

    return isAppear[rows - 1][cols - 1][0];
  }
};