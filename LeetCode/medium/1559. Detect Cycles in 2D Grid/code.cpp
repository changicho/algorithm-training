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

// dfs
// time : O(RC)
// space : O(RC)
class Solution {
 private:
  bool answer = false;

  pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  bool visited[501][501] = {
      0,
  };

  void dfs(int y, int x, int py, int px, vector<vector<char>>& grid) {
    if (answer) return;
    int rows = grid.size(), cols = grid[0].size();
    visited[y][x] = true;

    for (int d = 0; d < 4; d++) {
      int yd = dirs[d].first;
      int xd = dirs[d].second;

      int ny = y + yd;
      int nx = x + xd;

      if (ny == py && nx == px) continue;
      if (nx < 0 || nx >= cols || ny < 0 || ny >= rows) continue;
      if (grid[ny][nx] != grid[y][x]) continue;
      if (visited[ny][nx]) {
        answer = true;
        return;
      }

      dfs(ny, nx, y, x, grid);
    }
  };

 public:
  bool containsCycle(vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (visited[y][x]) continue;

        dfs(y, x, y, x, grid);
      }
    }

    return answer;
  }
};