#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & dynamic programming
// time : O(N + M * log_2(M))
// space : O(N)
class Solution {
 public:
  int maximizeTheProfit(int n, vector<vector<int>> &offers) {
    // offers[i] = [start_i, end_i, gold_i]

    // sort by end_i
    sort(offers.begin(), offers.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    vector<int> dp(n + 1, 0);

    for (int i = 0, j = 0; i <= n; i++) {
      dp[i] = max(dp[i], (i - 1) < 0 ? 0 : dp[i - 1]);

      while (j < offers.size() && offers[j][1] == i) {
        vector<int> offer = offers[j];
        j++;

        int left = offer[0], right = offer[1], gold = offer[2];

        dp[right] = max(dp[right], ((left - 1 < 0) ? 0 : dp[left - 1]) + gold);
      }
    }
    return dp.back();
  }
};