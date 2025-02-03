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
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

 public:
  int maximumAmount(vector<vector<int>>& coins) {
    int rows = coins.size();
    int cols = coins[0].size();

    vector<vector<vector<int>>> dp(
        rows, vector<vector<int>>(cols, vector<int>(3, INT_MIN)));

    dp[0][0][0] = coins[0][0];
    if (coins[0][0] < 0) {
      dp[0][0][1] = 0;
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int beforeY = y - 1, beforeX = x - 1;
        bool isRobber = coins[y][x] < 0;

        if (beforeY >= 0) {
          if (isRobber) {
            for (int i = 1; i <= 2; i++) {
              dp[y][x][i] = max(dp[beforeY][x][i - 1], dp[y][x][i]);
            }
          }

          for (int i = 0; i <= 2; i++) {
            if (dp[beforeY][x][i] == INT_MIN) continue;
            dp[y][x][i] = max(dp[beforeY][x][i] + coins[y][x], dp[y][x][i]);
          }
        }
        if (beforeX >= 0) {
          if (isRobber) {
            for (int i = 1; i <= 2; i++) {
              dp[y][x][i] = max(dp[y][beforeX][i - 1], dp[y][x][i]);
            }
          }

          for (int i = 0; i <= 2; i++) {
            if (dp[y][beforeX][i] == INT_MIN) continue;
            dp[y][x][i] = max(dp[y][beforeX][i] + coins[y][x], dp[y][x][i]);
          }
        }
      }
    }

    int answer = INT_MIN;
    for (int i = 0; i <= 2; i++) {
      answer = max(answer, dp[rows - 1][cols - 1][i]);
    }
    return answer;
  }
};