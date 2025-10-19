#include <algorithm>
#include <climits>
#include <cmath>
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

// use dynamic programming
// time : O(N^3)
// space : O(N^2)
class Solution {
 public:
  int minScoreTriangulation(vector<int>& values) {
    int size = values.size();

    int dp[51][51] = {
        0,
    };

    for (int diff = 2; diff < size; diff++) {
      for (int left = 0; left < size - diff; left++) {
        int right = left + diff;

        dp[left][right] = INT_MAX;
        for (int through = left + 1; through < right; through++) {
          int cur = dp[left][through] + dp[through][right] +
                    values[left] * values[through] * values[right];

          dp[left][right] = min(dp[left][right], cur);
        }
      }
    }
    return dp[0][size - 1];
  }
};