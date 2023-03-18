#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * M^2)
// space : O(N * M)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int waysToReachTarget(int target, vector<vector<int>>& types) {
    // dp[index][score]; // until index, case of make score
    // dp[i][score] = dp[i-1][score] + dp[i-1][score - s] + (cur s count) ...

    int size = types.size();
    int dp[51][1001] = {
        0,
    };

    for (int i = 0; i < size; i++) {
      for (int score = 1; score <= target; score++) {
        int curMax = types[i][0] * types[i][1];

        if (score <= curMax && (score % types[i][1]) == 0) {
          dp[i][score] = 1;
        }

        // ignore invalid case
        for (int diff = 0; i - 1 >= 0 && diff <= min(curMax, score);
             diff += types[i][1]) {
          dp[i][score] += dp[i - 1][score - diff];
          dp[i][score] %= MOD;
        }
      }
    }

    return dp[size - 1][target];
  }
};