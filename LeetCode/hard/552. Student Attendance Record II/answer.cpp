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
  const int MOD = 1e9 + 7;

 public:
  int checkRecord(int n) {
    // [index][late][absent]
    int dp[100001][3][2] = {
        0,
    };

    // Absent, Late, Present
    dp[1][0][1] = dp[1][1][0] = dp[1][0][0] = 1;
    for (int i = 2; i <= n; i++) {
      // Absent
      for (int late = 0; late <= 2; late++) {
        dp[i][0][1] += dp[i - 1][late][0];
        dp[i][0][1] %= MOD;
      }

      // Late
      for (int late = 1; late <= 2; late++) {
        for (int a = 0; a <= 1; a++) {
          dp[i][late][a] += dp[i - 1][late - 1][a];
          dp[i][late][a] %= MOD;
        }
      }

      // Present
      for (int late = 0; late <= 2; late++) {
        for (int a = 0; a <= 1; a++) {
          dp[i][0][a] += dp[i - 1][late][a];
          dp[i][0][a] %= MOD;
        }
      }
    }

    int answer = 0;
    for (int late = 0; late <= 2; late++) {
      for (int a = 0; a <= 1; a++) {
        answer += dp[n][late][a];
        answer %= MOD;
      }
    }
    return answer;
  }
};

// use dynamic programming (space optimized)
// time : O(N)
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int checkRecord(int n) {
    // [late][absent]
    int dp[3][2] = {
        0,
    };

    // Absent, Late, Present
    dp[0][1] = dp[1][0] = dp[0][0] = 1;
    for (int i = 2; i <= n; i++) {
      int newDp[3][2] = {
          0,
      };
      // Absent
      for (int late = 0; late <= 2; late++) {
        newDp[0][1] += dp[late][0];
        newDp[0][1] %= MOD;
      }

      // Late
      for (int late = 1; late <= 2; late++) {
        for (int a = 0; a <= 1; a++) {
          newDp[late][a] += dp[late - 1][a];
          newDp[late][a] %= MOD;
        }
      }

      // Present
      for (int late = 0; late <= 2; late++) {
        for (int a = 0; a <= 1; a++) {
          newDp[0][a] += dp[late][a];
          newDp[0][a] %= MOD;
        }
      }

      // copy
      swap(dp, newDp);
    }

    int answer = 0;
    for (int late = 0; late <= 2; late++) {
      for (int a = 0; a <= 1; a++) {
        answer += dp[late][a];
        answer %= MOD;
      }
    }
    return answer;
  }
};