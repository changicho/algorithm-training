#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * K)
// space : O(N * K)
class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int size = piles.size();

    // dp[i][coins] : i번째까지의 piles에서 coins개의 코인을 뽑았을 때의 최대값
    int dp[1001][2001] = {
        0,
    };
    for (int i = 0; i < size; i++) {
      for (int coins = 0; coins <= k; coins++) {
        int prefixSum = 0;

        int pilesSize = piles[i].size();
        int maximum = min(pilesSize, coins);
        for (int selected = 0; selected <= maximum; selected++) {
          if (selected > 0) {
            prefixSum += piles[i][selected - 1];
          }

          int prev = (i - 1) < 0 ? 0 : dp[i - 1][coins - selected];

          dp[i][coins] = max(dp[i][coins], prev + prefixSum);
        }
      }
    }

    return dp[size - 1][k];
  }
};