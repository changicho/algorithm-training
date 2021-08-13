#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use memoization

class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    int dp[3] = {costs[0][0], costs[0][1], costs[0][2]};
    int before[3] = {0, 0, 0};
    int size = costs.size();

    for (int i = 1; i < size; i++) {
      for (int color = 0; color < 3; color++) {
        before[color] = min(dp[(color + 2) % 3], dp[(color + 4) % 3]) + costs[i][color];
      }

      for (int color = 0; color < 3; color++) {
        dp[color] = before[color];
      }
    }

    int answer = dp[0];
    for (int color = 1; color < 3; color++) {
      answer = min(dp[color], answer);
    }
    return answer;
  }
};