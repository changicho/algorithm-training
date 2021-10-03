#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    for (int cur = 2; cur <= n; ++cur) {
      dp[cur] = cur;
      for (int part = 1; part <= cur / 2; ++part) {
        int left = dp[cur - part];
        int right = dp[part];

        dp[cur] = max(dp[cur], left * right);
      }
    }

    int answer = 0;
    for (int part = 1; part < n; part++) {
      answer = max(answer, dp[part] * dp[n - part]);
    }
    return answer;
  }
};