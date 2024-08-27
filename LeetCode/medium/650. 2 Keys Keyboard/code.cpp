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
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int minSteps(int n) {
    int dp[1001];

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
      int cur = INT_MAX;

      for (int before = 1; before <= i / 2; before++) {
        if (i % before != 0) continue;

        int operations = i / before;
        cur = min(cur, dp[before] + operations);
      }

      dp[i] = cur;
    }

    return dp[n];
  }
};