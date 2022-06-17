#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(M * N^2)
// space : O(M * N)
class Solution {
 public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int rows = grid.size(), cols = grid.front().size();

    vector<vector<long>> dp(rows, vector<long>(cols, INT_MAX));
    for (int x = 0; x < cols; x++) {
      dp[0][x] = 0;
    }

    for (int y = 0; y < rows - 1; y++) {
      for (int x = 0; x < cols; x++) {
        // y, x
        int idx = grid[y][x];

        for (int next = 0; next < cols; next++) {
          dp[y + 1][next] =
              min(dp[y + 1][next], dp[y][x] + moveCost[idx][next] + grid[y][x]);
        }
      }
    }
    for (int x = 0; x < cols; x++) {
      dp[rows - 1][x] += grid[rows - 1][x];
    }

    int answer = dp[rows - 1][cols - 1];
    for (int x = 0; x < cols; x++) {
      answer = min(answer, (int)dp[rows - 1][x]);
    }
    return answer;
  }
};