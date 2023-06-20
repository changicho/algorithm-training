#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming & sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n >= k + maxPts) return 1.0;

    vector<double> dp(n + 1);  // probability
    dp[0] = 1;

    double maxPtsSum = 1;
    for (int i = 1; i <= n; i++) {
      dp[i] = maxPtsSum / maxPts;
      if (i < k) {
        maxPtsSum += dp[i];
      }
      if (i >= maxPts) {
        maxPtsSum -= dp[i - maxPts];
      }
    }

    double sum = 0;
    for (int i = k; i <= n; i++) {
      sum += dp[i];
    }
    return sum;
  }
};