#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use priority queue
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  int MOD = 1e9 + 7;

  struct Axis {
    int y, x;
  };

  struct Data {
    Axis axis;
    int val;

    bool operator<(const Data &b) const { return val > b.val; }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int countPaths(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    int dp[1000][1000] = {
        0,
    };

    priority_queue<Data> pq;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        dp[y][x] = 1;
        pq.push({{y, x}, grid[y][x]});
      }
    }

    while (!pq.empty()) {
      Data cur = pq.top();
      pq.pop();

      for (Axis &dir : dirs) {
        Axis next = {cur.axis.y + dir.y, cur.axis.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (grid[next.y][next.x] <= cur.val) continue;
        dp[next.y][next.x] += dp[cur.axis.y][cur.axis.x];
        dp[next.y][next.x] %= MOD;
      }
    }

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer += dp[y][x];
        answer %= MOD;
      }
    }
    return answer;
  }
};

// use DFS with memoization
// time : O(N)
// space : O(N)
class Solution {
 private:
  int MOD = 1e9 + 7;

  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int memo[1001][1001];

  // find ways of decreasing path from cur (prev -> cur)
  int recursive(vector<vector<int>> &grid, Axis cur) {
    int rows = grid.size(), cols = grid[0].size();

    if (memo[cur.y][cur.x] != -1) return memo[cur.y][cur.x];

    int ret = 1;
    for (Axis &dir : dirs) {
      Axis prev = {cur.y + dir.y, cur.x + dir.x};
      if (prev.y < 0 || prev.y >= rows || prev.x < 0 || prev.x >= cols)
        continue;
      if (grid[prev.y][prev.x] >= grid[cur.y][cur.x]) continue;

      ret += recursive(grid, prev);
      ret %= MOD;
    }

    return memo[cur.y][cur.x] = ret;
  }

 public:
  int countPaths(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    memset(memo, -1, sizeof(memo));

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer += recursive(grid, {y, x});
        answer %= MOD;
      }
    }
    return answer;
  }
};