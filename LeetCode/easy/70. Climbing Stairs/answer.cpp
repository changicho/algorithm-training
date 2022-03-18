#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int climbStairs(int n) {
    vector<int> dp(45);  // dp[n - 1] : count of n steps
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
  }
};

// use dynamic programming (space optimized)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    }

    int oneAgo = 2, twoAgo = 1;

    for (int i = 2; i < n; i++) {
      int cur = oneAgo + twoAgo;
      twoAgo = oneAgo;
      oneAgo = cur;
    }

    return oneAgo;
  }
};