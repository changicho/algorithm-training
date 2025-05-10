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
  struct Status {
    int y, x, cost;

    bool operator<(const Status &b) const { return cost > b.cost; }
  };

  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int minTimeToReach(vector<vector<int>> &moveTime) {
    int rows = moveTime.size(), cols = moveTime[0].size();

    vector<vector<int>> costs(rows, vector<int>(cols, INT_MAX));

    priority_queue<Status> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
      Status cur = pq.top();
      pq.pop();

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};
        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        int nextCost = max(moveTime[next.y][next.x], cur.cost) + 1;

        if (costs[next.y][next.x] <= nextCost) continue;
        costs[next.y][next.x] = nextCost;

        pq.push({next.y, next.x, nextCost});
      }
    }

    return costs[rows - 1][cols - 1];
  }
};