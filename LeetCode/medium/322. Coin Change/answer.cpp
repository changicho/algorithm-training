#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);

    dp[0] = 0;
    for (int& coin : coins) {
      if (coin > amount) continue;
      dp[coin] = 1;
    }

    for (int i = 1; i <= amount; i++) {
      for (int coin : coins) {
        if (i - coin < 0) continue;

        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }

    int answer = dp[amount];

    if (answer == INT_MAX - 1) return -1;
    return answer;
  }
};