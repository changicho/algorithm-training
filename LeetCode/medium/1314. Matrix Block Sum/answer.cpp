#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int rows = mat.size();
    int cols = mat.front().size();

    // dp[y][x]; // 0,0부터 y,x까지 모든 값들의 합
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int fromUp = y < 1 ? 0 : dp[y - 1][x];
        int fromLeft = x < 1 ? 0 : dp[y][x - 1];
        int duplicated = x > 0 && y > 0 ? dp[y - 1][x - 1] : 0;

        dp[y][x] = fromUp + fromLeft - duplicated + mat[y][x];
      }
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int toY = min(y + k, rows - 1);
        int toX = min(x + k, cols - 1);
        int fromY = y - k - 1;
        int fromX = x - k - 1;

        mat[y][x] = dp[toY][toX];
        if (fromY >= 0) mat[y][x] -= dp[fromY][toX];  // fromUp
        if (fromX >= 0) mat[y][x] -= dp[toY][fromX];  // fromLeft
        if (fromY >= 0 && fromX >= 0) mat[y][x] += dp[fromY][fromX];
      }
    }

    return mat;
  }
};