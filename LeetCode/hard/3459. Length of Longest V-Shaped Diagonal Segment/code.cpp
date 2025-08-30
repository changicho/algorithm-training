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

// use dynamic programming
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

  // y,x,dir,turn
  int dp[500][500][4][2];

  int dfs(vector<vector<int>>& grid, Axis cur, int dir, bool turn, int target) {
    int rows = grid.size(), cols = grid[0].size();
    Axis next = {cur.y + dirs[dir].y, cur.x + dirs[dir].x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) return 0;
    if (grid[next.y][next.x] != target) return 0;

    if (dp[next.y][next.x][dir][turn] != -1)
      return dp[next.y][next.x][dir][turn];
    int nextTarget = 2 - target;

    int length = dfs(grid, next, dir, turn, nextTarget);
    if (!turn) {
      length = max(length, dfs(grid, next, (dir + 1) % 4, true, nextTarget));
    }

    return dp[next.y][next.x][dir][turn] = length + 1;
  };

 public:
  int lenOfVDiagonal(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    memset(dp, -1, sizeof(dp));

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] != 1) continue;

        for (int dir = 0; dir < 4; dir++) {
          int curLength = dfs(grid, {y, x}, dir, false, 2) + 1;

          answer = max(answer, curLength);
        }
      }
    }

    return answer;
  }
};