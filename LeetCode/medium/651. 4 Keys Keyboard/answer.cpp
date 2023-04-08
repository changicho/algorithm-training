#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int maxA(int n) {
    // dp[i] : max A's when i presses
    int dp[51] = {
        0,
    };
    // iota(dp.begin(), dp.end(), 0);
    for (int i = 0; i <= n; i++) {
      dp[i] = i;
    }

    for (int i = 0; i <= n; i++) {
      // select, copy, paste
      for (int pastedCount = 1; i + 2 + pastedCount <= n; pastedCount++) {
        int next = i + 2 + pastedCount;
        dp[next] = max(dp[next], dp[i] + pastedCount * dp[i]);
      }
    }
    return dp[n];
  }
};