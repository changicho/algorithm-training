#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(R * C^2)
// space : O(R * C^2)
class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    // dp[y][x1][x2]
    int dp[71][71][71] = {
        0,
    };

    int rows = grid.size(), cols = grid[0].size();

    for (int y = 0; y < rows - 1; y++) {
      for (int x1 = 0; x1 < cols; x1++) {
        for (int x2 = 0; x2 < cols; x2++) {
          dp[y][x1][x2] = INT_MIN;
        }
      }
    }
    dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];

    for (int y = 0; y < rows - 1; y++) {
      for (int x1 = 0; x1 < cols; x1++) {
        for (int x2 = 0; x2 < cols; x2++) {
          // x1 : -1 0 +1
          // x2 : -1 0 +1

          for (int diff1 = -1; diff1 <= 1; diff1++) {
            for (int diff2 = -1; diff2 <= 1; diff2++) {
              int nx1 = x1 + diff1, nx2 = x2 + diff2;
              if (nx1 < 0 || nx1 >= cols || nx2 < 0 || nx2 >= cols) continue;

              if (nx1 == nx2) {
                dp[y + 1][nx1][nx2] =
                    max(dp[y + 1][nx1][nx2], dp[y][x1][x2] + grid[y + 1][nx1]);
              } else {
                dp[y + 1][nx1][nx2] =
                    max(dp[y + 1][nx1][nx2],
                        dp[y][x1][x2] + grid[y + 1][nx1] + grid[y + 1][nx2]);
              }
            }
          }
        }
      }
    }

    int answer = 0;
    for (int x1 = 0; x1 < cols; x1++) {
      for (int x2 = 0; x2 < cols; x2++) {
        answer = max(answer, dp[rows - 1][x1][x2]);
      }
    }
    return answer;
  }
};