#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int tribonacci(int n) {
    vector<int> dp = {1, 1, 0};

    if (n < 3) {
      return dp[2 - n];
    }

    for (int i = 2; i < n; i++) {
      int temp = dp[0] + dp[1] + dp[2];

      dp[2] = dp[1];
      dp[1] = dp[0];
      dp[0] = temp;
    }

    return dp.front();
  }
};