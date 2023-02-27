#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  int MOD = 1e9 + 7;

 public:
  int numberOfWays(int numPeople) {
    // dp[num/2] : number of ways to handshake with num people
    int dp[501] = {
        0,
    };
    dp[0] = 1;

    for (int num = 1; num <= numPeople / 2; num++) {
      for (int left = 0; left < num; left++) {
        int right = num - left - 1;
        dp[num] += (long long)dp[left] * dp[right] % MOD;
        dp[num] %= MOD;
      }
    }

    return dp[numPeople / 2];
  }
};