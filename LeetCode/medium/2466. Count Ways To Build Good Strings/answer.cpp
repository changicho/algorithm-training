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
  int countGoodStrings(int low, int high, int zero, int one) {
    int dp[100001] = {
        0,
    };

    dp[zero] += 1;
    dp[one] += 1;

    for (int i = 1; i <= high; i++) {
      if (i + zero <= high) {
        dp[i + zero] += dp[i];
        dp[i + zero] %= MOD;
      }
      if (i + one <= high) {
        dp[i + one] += dp[i];
        dp[i + one] %= MOD;
      }
    }

    int answer = 0;
    for (int i = low; i <= high; i++) {
      answer += dp[i];
      answer %= MOD;
    }

    return answer;
  }
};