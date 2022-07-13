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
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // the number of people who found the secret on i day
    vector<long> dp(n + 1);
    dp[1] = 1;

    int share = 0, answer = 0;
    for (int i = 2; i <= n; i++) {
      share =
          (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + MOD) % MOD;
      dp[i] = share;
    }

    for (int i = n - forget + 1; i <= n; i++) {
      answer = (answer + dp[i]) % MOD;
    }
    return answer;
  }
};

// use dynamic programming
// time : O(N)
// space : O(forget)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<int> dp(forget);
    dp[0] = 1;
    long share = 0;
    for (int i = 1; i < n; i++) {
      share =
          (share + dp[(i - delay + forget) % forget] - dp[i % forget] + MOD) %
          MOD;
      dp[i % forget] = share;
    }

    int answer = 0;
    for (int &val : dp) {
      answer += val;
      answer %= MOD;
    }
    return answer;
  }
};