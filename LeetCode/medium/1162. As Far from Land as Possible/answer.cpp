#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int maxDistance(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();

    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

    queue<Axis> q;

    int answer = -1;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 1) q.push({y, x});
      }
    }

    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        Axis cur = q.front();
        q.pop();

        if (dp[cur.y][cur.x] <= step) continue;
        dp[cur.y][cur.x] = step;

        for (Axis& dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (grid[next.y][next.x] == 1) continue;

          q.push(next);
        }
      }
      step++;
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (dp[y][x] == INT_MAX) continue;
        if (grid[y][x] == 1) continue;

        answer = max(dp[y][x], answer);
      }
    }

    return answer;
  }
};

// use dynamic programming (space optimized)
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();
    const int MAX_DISTANCE = rows + cols + 1;

    // First pass: check for left and top neighbours
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 1) {
          grid[y][x] = 0;
        } else {
          grid[y][x] = MAX_DISTANCE;

          grid[y][x] =
              min(grid[y][x], min(y > 0 ? grid[y - 1][x] + 1 : MAX_DISTANCE,
                                  x > 0 ? grid[y][x - 1] + 1 : MAX_DISTANCE));
        }
      }
    }

    // Second pass: check for right and bottom neighbours.
    int ans = INT_MIN;
    for (int y = rows - 1; y >= 0; y--) {
      for (int x = cols - 1; x >= 0; x--) {
        grid[y][x] = min(grid[y][x],
                         min(y < rows - 1 ? grid[y + 1][x] + 1 : MAX_DISTANCE,
                             x < cols - 1 ? grid[y][x + 1] + 1 : MAX_DISTANCE));
        ans = max(ans, grid[y][x]);
      }
    }

    return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
  }
};