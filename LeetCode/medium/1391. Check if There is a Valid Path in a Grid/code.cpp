#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// DFS
// time : O(RC)
// space : O(RC)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  // U R D L
  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  string streets[7] = {"", "LR", "UD", "LD", "RD", "LU", "RU"};

  bool isConnected(vector<vector<int>>& grid, int ay, int ax, int by, int bx) {
    string streetA = streets[grid[ay][ax]], streetB = streets[grid[by][bx]];

    // U
    if ((by + 1) == ay) {
      if (streetA.contains('U') && streetB.contains('D')) return true;
    }
    // R
    else if ((bx - 1) == ax) {
      if (streetA.contains('R') && streetB.contains('L')) return true;
    }
    // D
    else if ((by - 1) == ay) {
      if (streetA.contains('D') && streetB.contains('U')) return true;
    }
    // L
    else if ((bx + 1) == ax) {
      if (streetA.contains('L') && streetB.contains('R')) return true;
    }
    return false;
  }

  bool answer = false;
  bool visited[301][301] = {
      false,
  };

  void dfs(vector<vector<int>>& grid, Axis cur) {
    if (answer) return;
    int rows = grid.size(), cols = grid[0].size();

    if (cur.y == rows - 1 && cur.x == cols - 1) {
      answer = true;
      return;
    }

    for (Axis& dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;
      if (!isConnected(grid, cur.y, cur.x, next.y, next.x)) continue;

      visited[next.y][next.x] = true;

      dfs(grid, next);
    }
  }

 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    visited[0][0] = true;
    dfs(grid, {0, 0});
    return answer;
  }
};
