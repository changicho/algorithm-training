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

// dp
// time : O(RCK)
// space : O(RCK)
class Solution {
 public:
  int maxPathScore(vector<vector<int>>& grid, int k) {
    int rows = grid.size(), cols = grid[0].size();

    // y,x,cost
    vector<vector<int>> dp(cols, vector<int>(k + 1, -1));
    dp[0][0] = 0;

    for (int y = 0; y < rows; y++) {
      vector<vector<int>> newDp(cols, vector<int>(k + 1, -1));

      for (int x = 0; x < cols; x++) {
        for (int cost = 0; cost <= k; cost++) {
          int cur = grid[y][x];

          if (true) {
            int beforeCost = cost - (cur > 0);
            if (beforeCost <= k && beforeCost >= 0 && dp[x][beforeCost] != -1) {
              newDp[x][cost] = max(newDp[x][cost], dp[x][beforeCost] + cur);
            }
          }
          if (x - 1 >= 0) {
            int beforeCost = cost - (cur > 0);
            if (beforeCost <= k && beforeCost >= 0 &&
                newDp[x - 1][beforeCost] != -1) {
              newDp[x][cost] =
                  max(newDp[x][cost], newDp[x - 1][beforeCost] + cur);
            }
          }
        }
      }

      swap(newDp, dp);
    }

    int answer = -1;
    for (int cost = 0; cost <= k; cost++) {
      if (dp[cols - 1][cost] != -1) answer = max(answer, dp[cols - 1][cost]);
    }
    return answer;
  }
};

// dp (in place)
// time : O(RCK)
// space : O(CK)
class Solution {
 public:
  int maxPathScore(vector<vector<int>>& grid, int k) {
    int rows = grid.size(), cols = grid[0].size();

    // y,x,cost
    vector<vector<int>> dp(cols, vector<int>(k + 1, -1));
    dp[0][0] = 0;

    for (int y = 0; y < rows; y++) {
      vector<vector<int>> newDp(cols, vector<int>(k + 1, -1));

      for (int x = 0; x < cols; x++) {
        for (int cost = 0; cost <= k; cost++) {
          int cur = grid[y][x];

          if (true) {
            int beforeCost = cost - (cur > 0);
            if (beforeCost <= k && beforeCost >= 0 && dp[x][beforeCost] != -1) {
              newDp[x][cost] = max(newDp[x][cost], dp[x][beforeCost] + cur);
            }
          }
          if (x - 1 >= 0) {
            int beforeCost = cost - (cur > 0);
            if (beforeCost <= k && beforeCost >= 0 &&
                newDp[x - 1][beforeCost] != -1) {
              newDp[x][cost] =
                  max(newDp[x][cost], newDp[x - 1][beforeCost] + cur);
            }
          }
        }
      }

      swap(newDp, dp);
    }

    int answer = -1;
    for (int cost = 0; cost <= k; cost++) {
      if (dp[cols - 1][cost] != -1) answer = max(answer, dp[cols - 1][cost]);
    }
    return answer;
  }
};