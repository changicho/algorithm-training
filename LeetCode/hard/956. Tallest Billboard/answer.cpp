#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * M)
// space : O(M)
class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    // biggest pair with difference diff
    // dp[diff] = smallest sum of the pair
    unordered_map<int, int> dp;
    dp[0] = 0;
    for (int& rod : rods) {
      unordered_map<int, int> before(dp);
      for (auto it : before) {
        int sum = it.first;

        dp[sum + rod] = max(dp[sum + rod], before[sum]);
        dp[abs(sum - rod)] =
            max(dp[abs(sum - rod)], before[sum] + min(sum, rod));
      }
    }
    return dp[0];
  }
};

// use dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    int size = rods.size();
    int totalSum = accumulate(rods.begin(), rods.end(), 0);
    int limit = 2 * totalSum + 1;

    vector<vector<int>> dp(size + 1, vector<int>(limit, INT_MIN));

    dp[0][totalSum] = 0;
    for (int i = 1; i <= size; i++) {
      for (int curSum = 0; curSum < limit; curSum++) {
        int rod = rods[i - 1];
        // Putting ith rod in g0
        if ((curSum - rod) >= 0 && dp[i - 1][curSum - rod] != INT_MIN) {
          dp[i][curSum] = max(dp[i][curSum], dp[i - 1][curSum - rod] + rod);
        }
        // Putting ith in g1
        if ((curSum + rod) < limit && dp[i - 1][curSum + rod] != INT_MIN) {
          dp[i][curSum] = max(dp[i][curSum], dp[i - 1][curSum + rod]);
        }
        // Ignoring ith rod
        if (dp[i - 1][curSum] != INT_MIN) {
          dp[i][curSum] = max(dp[i][curSum], dp[i - 1][curSum]);
        }
      }
    }

    return dp[size][totalSum];
  }
};