#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(R * C * 4^G)
// space : O(R * C + G)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  struct Status {
    Axis a;
    int s;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int search(vector<vector<int>> &grid, Axis start) {
    int rows = grid.size(), cols = grid[0].size();
    bool visited[16][16] = {false};

    int ret = 0;

    function<void(Axis, int)> recursive = [&](Axis cur, int sum) {
      ret = max(ret, sum);

      for (Axis &dir : dirs) {
        Axis next = {dir.y + cur.y, dir.x + cur.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[next.y][next.x]) continue;
        if (grid[next.y][next.x] == 0) continue;

        visited[next.y][next.x] = true;

        recursive(next, sum + grid[next.y][next.x]);

        visited[next.y][next.x] = false;
      }
    };

    visited[start.y][start.x] = true;
    recursive(start, grid[start.y][start.x]);

    return ret;
  }

 public:
  int getMaximumGold(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;

        int cur = search(grid, {y, x});
        answer = max(answer, cur);
      }
    }
    return answer;
  }
};