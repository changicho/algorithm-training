#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * K^2)
// space : O(N * K)
class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    int size = costs.size();
    int colors = costs[0].size();

    int dp[101][101] = {
        -1,
    };
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < colors; i++) {
      dp[0][i] = costs[0][i];
    }

    for (int i = 1; i < size; i++) {
      for (int curColor = 0; curColor < colors; curColor++) {
        dp[i][curColor] = INT_MAX;
        for (int beforeColor = 0; beforeColor < colors; beforeColor++) {
          if (curColor == beforeColor) continue;

          dp[i][curColor] =
              min(dp[i - 1][beforeColor] + costs[i][curColor], dp[i][curColor]);
        }
      }
    }

    int answer = INT_MAX;

    for (int i = 0; i < colors; i++) {
      answer = min(answer, dp[size - 1][i]);
    }
    return answer;
  }
};