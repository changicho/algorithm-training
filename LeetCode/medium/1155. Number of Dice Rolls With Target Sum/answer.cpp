#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * K * T)
// space : O(N * T)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numRollsToTarget(int n, int k, int target) {
    // n, k
    int dp[31][1001] = {
        0,
    };

    for (int i = 1; i <= k; i++) {
      dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
      for (int cur = 1; cur <= k; cur++) {
        for (int before = 1; before <= target; before++) {
          if (cur + before > target) break;
          dp[i][cur + before] += dp[i - 1][before];
          dp[i][cur + before] %= MOD;
        }
      }
    }

    return dp[n][target];
  }
};

// use dynamic programming (space optimized)
// time : O(N * K * T)
// space : O(T)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numRollsToTarget(int n, int k, int target) {
    // n, k
    int dp[1001] = {
        0,
    };

    for (int i = 1; i <= k; i++) {
      dp[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
      int curDp[1001] = {
          0,
      };
      for (int num = 1; num <= k; num++) {
        for (int before = 1; before <= target; before++) {
          if (num + before > target) break;
          curDp[num + before] += dp[before];
          curDp[num + before] %= MOD;
        }
      }

      for (int j = 0; j <= 1000; j++) {
        dp[j] = curDp[j];
      }
    }

    return dp[target];
  }
};