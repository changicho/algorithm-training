#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS & dijkstra
// time : O(N^2 * log_2(N^2))
// space : O(N^2)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  struct Status {
    int y, x, cost;

    bool operator<(const Status &b) const { return cost < b.cost; }
  };

 public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<int>> costs(rows, vector<int>(cols, INT_MAX));

    queue<Axis> q;
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

        if (costs[cur.y][cur.x] != INT_MAX) continue;
        costs[cur.y][cur.x] = step;

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (costs[next.y][next.x] != INT_MAX) continue;
          q.push(next);
        }
      }

      step++;
    }

    priority_queue<Status> pq;
    int visited[401][401] = {
        0,
    };
    pq.push({0, 0, costs[0][0]});
    visited[0][0] = costs[0][0];
    while (!pq.empty()) {
      Status cur = pq.top();
      pq.pop();

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;

        int nextCost = min(cur.cost, costs[next.y][next.x]);
        if (nextCost <= visited[next.y][next.x]) continue;
        visited[next.y][next.x] = nextCost;
        pq.push({next.y, next.x, nextCost});
      }
    }

    return visited[rows - 1][cols - 1];
  }
};