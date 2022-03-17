#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();
    vector<int> dp(size, INT_MAX);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < size; i++) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    return min(dp[size - 1], dp[size - 2]);
  }
};

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();
    // dp[index]; minimum cost to reach index
    vector<int> dp(size + 1);

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= size; i++) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[size];
  }
};

// use dynamic programming space optimized
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();

    int twoAgo = cost[0];  // index is (cur - 2)
    int oneAgo = cost[1];  //  index is (cur - 1)

    for (int i = 2; i < size; i++) {
      int curCost = cost[i] + min(twoAgo, oneAgo);
      twoAgo = oneAgo;
      oneAgo = curCost;
    }

    return min(twoAgo, oneAgo);
  }
};