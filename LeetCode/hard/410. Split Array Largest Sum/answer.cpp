#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    int size = nums.size();
    vector<int> sums(size + 1, 0);
    for (int i = 0; i < size; i++) {
      sums[i + 1] = sums[i] + nums[i];
    }

    // dp[i][j]; minimum largest sum of 0 ~ (i - 1), when split j parts
    vector<vector<int>> dp(size + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= size; i++) {
      for (int part = 1; part <= m; part++) {
        for (int left = 0; left < i; left++) {
          // compare leftPart and rightPart
          int currentMaximum = max(dp[left][part - 1], sums[i] - sums[left]);
          dp[i][part] = min(dp[i][part], currentMaximum);
        }
      }
    }

    return dp[size][m];
  }
};