#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use full dynamic programming

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid.front().size();

    vector<vector<int>> dp(row, vector<int>(col, 0));

    dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    if (dp[0][0] == 0) return 0;

    for (int y = 1; y < row; y++) {
      if (obstacleGrid[y][0] != 0) break;

      dp[y][0] = dp[y - 1][0];
    }

    for (int x = 1; x < col; x++) {
      if (obstacleGrid[0][x] != 0) break;

      dp[0][x] = dp[0][x - 1];
    }

    for (int y = 1; y < row; y++) {
      for (int x = 1; x < col; x++) {
        if (obstacleGrid[y][x]) continue;

        dp[y][x] += dp[y][x - 1] + dp[y - 1][x];
      }
    }

    return dp[row - 1][col - 1];
  }
};

// use minimum dynamic programming

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid.front().size();

    vector<vector<int>> dp(2, vector<int>(col, 0));

    dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

    for (int y = 1; y < min(row, 2); y++) {
      if (obstacleGrid[y][0] != 0) break;

      dp[y][0] = dp[y - 1][0];
    }
    for (int x = 1; x < col; x++) {
      if (obstacleGrid[0][x] != 0) break;

      dp[0][x] = dp[0][x - 1];
    }

    for (int y = 1; y < row; y++) {
      for (int x = 0; x < col; x++) {
        if (obstacleGrid[y][x]) {
          dp[y % 2][x] = 0;
          continue;
        }
        int cur = 0;
        if (x > 0) {
          cur += dp[y % 2][x - 1];
        }
        cur += dp[(y + 1) % 2][x];
        dp[y % 2][x] = cur;
      }
    }

    return dp[(row - 1) % 2][col - 1];
  }
};