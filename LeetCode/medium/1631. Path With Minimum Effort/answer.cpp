#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(M))
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  bool check(vector<vector<int>> &heights, int target) {
    int rows = heights.size(), cols = heights[0].size();

    queue<Axis> q;
    bool visited[101][101] = {
        false,
    };
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (cur.y == rows - 1 && cur.x == cols - 1) {
        return true;
      }

      for (Axis &dir : dirs) {
        int ny = cur.y + dir.y, nx = cur.x + dir.x;
        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
        if (visited[ny][nx]) continue;

        int diff = abs(heights[ny][nx] - heights[cur.y][cur.x]);
        if (diff <= target) {
          visited[ny][nx] = true;
          q.push({ny, nx});
        }
      }
    }
    return false;
  }

 public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int left = 0, right = 1000000;
    int answer = right;
    while (left <= right) {
      int mid = (left + right) / 2;

      if (check(heights, mid)) {
        answer = min(answer, mid);
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return answer;
  }
};

// use dijkstra
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  struct Status {
    int y, x, cost;

    bool operator<(const Status &other) const { return cost > other.cost; }
  };

  Axis dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int dp[105][105] = {
      0,
  };

 public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int rows = heights.size(), cols = heights[0].size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        dp[y][x] = INT_MAX;
      }
    }

    priority_queue<Status> pq;
    pq.push({0, 0, 0});
    dp[0][0] = 0;

    while (!pq.empty()) {
      Status cur = pq.top();
      pq.pop();

      int y = cur.y, x = cur.x;

      if (y == rows - 1 && x == cols - 1) continue;

      for (Axis &dir : dirs) {
        int ny = y + dir.y, nx = x + dir.x;

        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;

        int diff = abs(heights[y][x] - heights[ny][nx]);
        int cost = max(dp[y][x], diff);

        if (cost < dp[ny][nx]) {
          dp[ny][nx] = cost;
          pq.push({ny, nx, cost});
        }
      }
    }
    return dp[rows - 1][cols - 1];
  }
};