#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  double probabilityOfHeads(vector<double>& prob, int target) {
    int size = prob.size();

    // dp[index][count]
    double dp[1001][1001] = {
        0.0,
    };

    dp[0][0] = 1 - prob[0];
    dp[0][1] = prob[0];

    for (int i = 1; i < size; i++) {
      double one = prob[i], zero = 1 - prob[i];

      dp[i][0] = dp[i - 1][0] * zero;
      for (int count = 1; count <= target && count <= (i + 1); count++) {
        dp[i][count] += dp[i - 1][count - 1] * one;
        dp[i][count] += dp[i - 1][count] * zero;
      }
    }

    return dp[size - 1][target];
  }
};