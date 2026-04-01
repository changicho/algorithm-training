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

// dynamic programming
// time : O(RC)
// space : O(RC)
class Solution {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    const int MOD = 1e9 + 7;
    int rows = grid.size(), cols = grid[0].size();

    // 0 : minus, 1 : plus
    long long dp[16][16][2];
    dp[0][0][0] = dp[0][0][1] = grid[0][0];

    for (int y = 1; y < rows; y++) {
      dp[y][0][0] = dp[y][0][1] = dp[y - 1][0][1] * grid[y][0];
    }
    for (int x = 1; x < cols; x++) {
      dp[0][x][0] = dp[0][x][1] = dp[0][x - 1][1] * grid[0][x];
    }

    for (int y = 1; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        long long cur = grid[y][x];

        if (cur >= 0) {
          dp[y][x][0] = min(dp[y - 1][x][0], dp[y][x - 1][0]) * cur;
          dp[y][x][1] = max(dp[y - 1][x][1], dp[y][x - 1][1]) * cur;
        } else {
          dp[y][x][0] = max(dp[y - 1][x][1], dp[y][x - 1][1]) * cur;
          dp[y][x][1] = min(dp[y - 1][x][0], dp[y][x - 1][0]) * cur;
        }
      }
    }
    int answer = dp[rows - 1][cols - 1][1] % MOD;
    if (answer < 0) return -1;
    return answer;
  }
};