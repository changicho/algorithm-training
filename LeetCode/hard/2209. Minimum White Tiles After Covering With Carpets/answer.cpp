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
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    int size = floor.size();

    // dp[n][k]
    // the minimum number of white tiles when cover
    // the first n tiles using k carpet
    vector<vector<int>> dp(size + 1, vector<int>(numCarpets + 1, 0));

    for (int i = 1; i <= size; i++) {
      dp[i][0] = dp[i - 1][0] + (floor[i - 1] == '1' ? 1 : 0);

      for (int k = 1; k <= numCarpets; k++) {
        int jump = dp[i - 1][k] + (floor[i - 1] == '1' ? 1 : 0);
        int cover = dp[max(i - carpetLen, 0)][k - 1];

        dp[i][k] = min(cover, jump);
      }
    }
    return dp[size][numCarpets];
  }
};