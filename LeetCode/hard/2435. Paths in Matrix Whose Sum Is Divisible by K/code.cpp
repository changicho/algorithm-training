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

// use dynamic programming
// time : O(R * C * K)
// space : O(R * C * K)
class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    const int MOD = 1e9 + 7;

    int rows = grid.size(), cols = grid[0].size();

    vector<vector<vector<int>>> dp(rows,
                                   vector<vector<int>>(cols, vector<int>(k)));

    dp[0][0][grid[0][0] % k]++;

    for (int x = 1; x < cols; x++) {
      for (int i = 0; i < k; i++) {
        dp[0][x][(i + grid[0][x]) % k] += dp[0][x - 1][i];
        dp[0][x][(i + grid[0][x]) % k] %= MOD;
      }
    }
    for (int y = 1; y < rows; y++) {
      for (int i = 0; i < k; i++) {
        dp[y][0][(i + grid[y][0]) % k] += dp[y - 1][0][i];
        dp[y][0][(i + grid[y][0]) % k] %= MOD;
      }
    }

    for (int y = 1; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        for (int i = 0; i < k; i++) {
          // from top
          dp[y][x][(i + grid[y][x]) % k] += dp[y - 1][x][i];
          dp[y][x][(i + grid[y][x]) % k] %= MOD;
          // from left
          dp[y][x][(i + grid[y][x]) % k] += dp[y][x - 1][i];
          dp[y][x][(i + grid[y][x]) % k] %= MOD;
        }
      }
    }

    return dp[rows - 1][cols - 1][0];
  }
};