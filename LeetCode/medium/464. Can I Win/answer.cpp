#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(2^N)
// space : O(2^N)
class Solution {
 private:
  int dp[1 << 20] = {};
  // digit : current game state
  bool dfs(int m, int total, int digit) {
    if (dp[digit] != 0) return dp[digit] > 0;
    if (total <= 0) return false;

    for (int i = 0; i < m; ++i) {
      if (digit & (1 << i)) continue;

      int next = digit | (1 << i);
      // if (i+1) is available to pick and my opponent can't win after I picked
      if (!dfs(m, total - i - 1, next)) {
        // win
        dp[digit] = 1;
        return true;
      }
    }

    dp[digit] = -1;
    return false;
  }

 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

    if (desiredTotal < 2) return true;
    if (sum < desiredTotal) return false;

    if (sum == desiredTotal) {
      return maxChoosableInteger % 2;
    }
    return dfs(maxChoosableInteger, desiredTotal, 0);
  }
};
