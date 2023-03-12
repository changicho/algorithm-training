#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dijkstra
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  struct Status {
    Axis axis;
    int time;

    bool operator<(const Status &b) const { return time > b.time; }
  };

 public:
  int minimumTime(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid.front().size();

    if (grid[1][0] > 1 && grid[0][1] > 1) return -1;

    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
    priority_queue<Status> q;

    q.push({{0, 0}, 0});

    while (!q.empty()) {
      Status cur = q.top();
      q.pop();

      Axis axis = cur.axis;

      if (dp[axis.y][axis.x] <= cur.time) continue;
      dp[axis.y][axis.x] = cur.time;

      for (Axis &dir : dirs) {
        Axis next = {axis.y + dir.y, axis.x + dir.x};

        if (next.x < 0 || next.x >= cols || next.y < 0 || next.y >= rows)
          continue;

        if (grid[next.y][next.x] - 1 <= cur.time) {
          q.push({next, cur.time + 1});
        } else {
          // find minimum 2*x time that needed time to reach next cell
          int diff = (grid[next.y][next.x] - cur.time) / 2 * 2;

          q.push({next, cur.time + diff + 1});
        }
      }
    }

    return dp[rows - 1][cols - 1] == INT_MAX ? -1 : dp[rows - 1][cols - 1];
  }
};