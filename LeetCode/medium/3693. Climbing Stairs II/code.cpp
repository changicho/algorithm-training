#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

// dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int climbStairs(int n, vector<int>& costs) {
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= 3; j++) {
        if (i + j > n) break;

        int diff = j * j;
        dp[i + j] = min(dp[i + j], dp[i] + costs[i + j - 1] + diff);
      }
    }

    return dp[n];
  }
};

// dynamic programming (space optimized)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int climbStairs(int n, vector<int>& costs) {
    int dp[4] = {0, INT_MAX, INT_MAX, INT_MAX};

    int answer = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= 3; j++) {
        if (i + j > n) break;

        int diff = j * j;
        dp[j] = min(dp[j], dp[0] + costs[i + j - 1] + diff);
      }

      if (i == n) return dp[0];

      // shift
      for (int i = 0; i <= 2; i++) {
        dp[i] = dp[i + 1];
      }
      dp[3] = INT_MAX;
    }

    return -1;
  }
};