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

using ll = long long;

// dynamic programming
// time : O(RC * B)
// space : O(RC * B)
class Solution {
 public:
  int minCost(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<vector<bool>>> dp(
        rows, vector<vector<bool>>(cols, vector<bool>(1024, false)));
    dp[0][0][grid[0][0]] = true;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int cur = grid[y][x];

        if (y - 1 >= 0) {
          for (int before = 0; before < 1024; before++) {
            if (!dp[y - 1][x][before]) continue;

            dp[y][x][cur ^ before] = true;
          }
        }

        if (x - 1 >= 0) {
          for (int before = 0; before < 1024; before++) {
            if (!dp[y][x - 1][before]) continue;

            dp[y][x][cur ^ before] = true;
          }
        }
      }
    }

    for (int before = 0; before < 1024; before++) {
      if (!dp[rows - 1][cols - 1][before]) continue;
      return before;
    }
    return -1;
  }
};