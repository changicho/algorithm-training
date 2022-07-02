#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 private:
  int MOD = 1e9 + 7;

 public:
  int countHousePlacements(int n) {
    int dp[10002] = {
        0,
    };

    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 2] + dp[i - 1];
      dp[i] %= MOD;
    }

    long long target = dp[n];
    long long answer = (long long)dp[n] * dp[n];
    answer %= MOD;

    return answer;
  }
};