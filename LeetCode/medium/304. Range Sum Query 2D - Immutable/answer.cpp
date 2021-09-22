#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class NumMatrix {
 private:
  int dp[201][201] = {
      0,
  };

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int fromUp = y > 0 ? dp[y - 1][x] : 0;
        int fromLeft = x > 0 ? dp[y][x - 1] : 0;
        int duplicated = y > 0 && x > 0 ? dp[y - 1][x - 1] : 0;

        dp[y][x] = fromUp + fromLeft - duplicated + matrix[y][x];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int all = dp[row2][col2];
    int fromUp = row1 > 0 ? dp[row1 - 1][col2] : 0;
    int fromLeft = col1 > 0 ? dp[row2][col1 - 1] : 0;
    int duplicated = row1 > 0 && col1 > 0 ? dp[row1 - 1][col1 - 1] : 0;

    return all - fromUp - fromLeft + duplicated;
  }
};

// use dynamic programming (zero)

class NumMatrix {
 private:
  int dp[201][201] = {
      0,
  };

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    for (int y = 0; y < rows; ++y)
      for (int x = 0; x < cols; ++x) {
        dp[y + 1][x + 1] =
            dp[y][x + 1] + dp[y + 1][x] - dp[y][x] + matrix[y][x];
      }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] +
           dp[row1][col1];
  }
};