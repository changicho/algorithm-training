#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (bottom up)
// time : O(N * K)
// space : O(N * K)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int kInversePairs(int n, int k) {
    int dp[1001][1001] = {
        0,
    };

    for (int i = 1; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        int val = dp[i - 1][j];
        if (j - i >= 0) val -= dp[i - 1][j - i];

        val += MOD;
        val %= MOD;

        dp[i][j] = (dp[i][j - 1] + val) % MOD;
      }
    }

    int answer = dp[n][k];
    if (k > 0) answer -= dp[n][k - 1];
    answer += MOD;
    answer %= MOD;
    return answer;
  }
};

// use dynamic programming (top down)
// time : O(N * K)
// space : O(N * K)
class Solution {
 private:
  const int MOD = 1e9 + 7;
  int dp[1001][1001] = {
      0,
  };

  int inverse(int n, int k) {
    if (n == 0) return 0;
    if (k == 0) return 1;

    if (dp[n][k] != 0) return dp[n][k];

    int val = inverse(n - 1, k);
    if (k - n >= 0) val -= inverse(n - 1, k - n);
    val += MOD;
    val %= MOD;

    dp[n][k] = (inverse(n, k - 1) + val) % MOD;
    return dp[n][k];
  }

 public:
  int kInversePairs(int n, int k) {
    return (inverse(n, k) + MOD - (k > 0 ? inverse(n, k - 1) : 0)) % MOD;
  }
};