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

using ll = long long;

// dijkstra
// time : O(RC * log_@(RC))
// space : O(RC)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  struct Status {
    Axis a;
    int h;

    bool operator<(const Status& b) const { return h < b.h; }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int rows = grid.size(), cols = grid[0].size();

    priority_queue<Status> q;
    q.push({{0, 0}, health -= grid[0][0]});

    bool visited[51][51] = {
        false,
    };
    visited[0][0] = true;
    while (!q.empty()) {
      Status curS = q.top();
      q.pop();
      Axis cur = curS.a;

      for (Axis& d : dirs) {
        Axis next = {cur.y + d.y, cur.x + d.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[next.y][next.x]) continue;

        int nextH = curS.h - grid[next.y][next.x];
        if (nextH <= 0) continue;

        visited[next.y][next.x] = true;
        q.push({next, nextH});
      }
    }

    return visited[rows - 1][cols - 1];
  }
};