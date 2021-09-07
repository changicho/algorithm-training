#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();
    vector<int> dp(2, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < size; i++) {
      int temp = cost[i] + min(dp[0], dp[1]);
      dp[0] = dp[1];
      dp[1] = temp;
    }

    return min(dp[0], dp[1]);
  }
};