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

// use brute force with BFS
// time : O((R * C)^2)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int getIslands(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int island = 0;

    function<void(int, int)> checkVisited = [&](int y, int x) {
      queue<Axis> q;
      q.push({y, x});
      visited[y][x] = true;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (visited[next.y][next.x]) continue;
          if (grid[next.y][next.x] == 0) continue;

          visited[next.y][next.x] = true;
          q.push(next);
        }
      }
    };

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;
        if (visited[y][x]) continue;

        island++;

        checkVisited(y, x);
      }
    }

    return island;
  }

 public:
  int minDays(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    if (getIslands(grid) != 1) return 0;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;

        grid[y][x] = 0;

        if (getIslands(grid) != 1) return 1;

        grid[y][x] = 1;
      }
    }

    return 2;
  }
};