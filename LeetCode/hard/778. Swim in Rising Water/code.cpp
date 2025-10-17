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

// use heap
// time : O(N^2 * log_2(N))
// space : O(N^2)
class Solution {
 private:
  struct Axis {
    int y, x;
  };
  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  struct Status {
    int t;
    Axis a;

    bool operator<(const Status &b) const { return t > b.t; }
  };

 public:
  int swimInWater(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    priority_queue<Status> pq;
    bool visited[50][50] = {
        false,
    };
    pq.push({grid[0][0], {0, 0}});
    visited[0][0] = true;

    int answer = INT_MAX;
    while (!pq.empty()) {
      Status cur = pq.top();
      pq.pop();

      if (cur.a.y == rows - 1 && cur.a.x == cols - 1) {
        answer = min(answer, cur.t);
      }

      for (Axis &dir : dirs) {
        Axis next = {cur.a.y + dir.y, cur.a.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[next.y][next.x]) continue;
        visited[next.y][next.x] = true;

        int cost = max(cur.t, grid[next.y][next.x]);

        pq.push({cost, next});
      }
    }

    return answer;
  }
};