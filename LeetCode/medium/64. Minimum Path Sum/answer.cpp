#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid.front().size();

    vector<vector<int>> dp(row, vector<int>(col, 0));

    dp[0][0] = grid[0][0];

    for (int y = 1; y < row; y++) {
      dp[y][0] = dp[y - 1][0] + grid[y][0];
    }
    for (int x = 1; x < col; x++) {
      dp[0][x] = dp[0][x - 1] + grid[0][x];
    }

    for (int y = 1; y < row; y++) {
      for (int x = 1; x < col; x++) {
        dp[y][x] = grid[y][x] + min(dp[y - 1][x], dp[y][x - 1]);
      }
    }

    return dp[row - 1][col - 1];
  }
};

// use one array

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid.front().size();

    vector<int> dp(row, 0);

    dp[0] = grid[0][0];
    for (int y = 1; y < row; y++) {
      dp[y] = dp[y - 1] + grid[y][0];
    }

    for (int x = 1; x < col; x++) {
      dp[0] += grid[0][x];

      for (int y = 1; y < row; y++) {
        dp[y] = min(dp[y - 1], dp[y]) + grid[y][x];
      }
    }
    return dp[row - 1];
  }
};