#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use full dynamic programming
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();

    int dp[101][101] = {
        0,
    };
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (obstacleGrid[y][x] == 1) continue;

        dp[y][x] += y - 1 < 0 ? 0 : dp[y - 1][x];
        dp[y][x] += x - 1 < 0 ? 0 : dp[y][x - 1];
      }
    }

    return dp[rows - 1][cols - 1];
  }
};

// use minimum dynamic programming
// time : O(R * C)
// space : O(R)
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