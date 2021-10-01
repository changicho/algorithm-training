#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    int size = coins.size();
    vector<vector<int>> dp(size + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;

    for (int count = 1; count <= size; count++) {
      dp[count][0] = 1;
      for (int cost = 1; cost <= amount; cost++) {
        dp[count][cost] = dp[count - 1][cost];

        // if can use to make before value
        if (cost >= coins[count - 1]) {
          dp[count][cost] += dp[count][cost - coins[count - 1]];
        }
      }
    }

    return dp.back().back();
  }
};

// use dynamic programming (space optimized)

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
      for (int cost = coin; cost <= amount; cost++) {
        dp[cost] += dp[cost - coin];
      }
    }

    return dp.back();
  }
};