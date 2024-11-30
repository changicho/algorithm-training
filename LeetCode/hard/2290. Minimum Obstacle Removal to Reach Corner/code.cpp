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

// use dijkstra
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  struct Edge {
    Axis a;
    int cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

 public:
  int minimumObstacles(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    priority_queue<Edge> pq;
    vector<vector<int>> dp(rows, vector<int>(cols, rows * cols + 1));

    pq.push({{0, 0}, 0});
    dp[0][0] = 0;
    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      for (Axis &dir : dirs) {
        Axis next = {cur.a.y + dir.y, cur.a.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        int nextCost = cur.cost + (grid[next.y][next.x] == 1);

        if (dp[next.y][next.x] <= nextCost) continue;
        dp[next.y][next.x] = nextCost;
        pq.push({next, nextCost});
      }
    }

    return dp[rows - 1][cols - 1];
  }
};