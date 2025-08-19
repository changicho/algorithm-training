#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int numberOfWays(int n, int x) {
    const int MOD = 1e9 + 7;

    // dp[num][sum] : until num, possible to make pow sum cases
    long long dp[301][301] = {
        0,
    };
    dp[0][0] = 1;

    for (int num = 1; num <= n; num++) {
      long long val = pow(num, x);
      if (val > n) break;

      for (int sum = n; sum >= 0; sum--) {
        dp[num][sum] = dp[num - 1][sum];

        if (sum >= val) {
          dp[num][sum] += dp[num - 1][sum - val];
          dp[num][sum] %= MOD;
        }
      }
    }
    return dp[n][n];
  }
};

// use dynamic programming (space optimized)
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int numberOfWays(int n, int x) {
    const long long MOD = 1e9 + 7;

    long long dp[301] = {
        0,
    };

    dp[0] = 1;
    for (long long num = 1; num <= n; num++) {
      long long val = pow(num, x);

      for (int sum = n; sum >= val; sum--) {
        dp[sum] += dp[sum - val];
        dp[sum] %= MOD;
      }
    }
    return dp[n];
  }
};