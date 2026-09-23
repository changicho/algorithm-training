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

// dynamic programming & greedy
// time : O(N * sqrt(N))
// space : O(N)
class Solution {
 public:
  int minDays(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    int cur = 1, earn = 1;

    while (cur <= n) {
      dp[cur] = earn;

      for (int i = cur + 1; i <= min(n, cur + cur); i++) {
        // skip case
        dp[i] = min(dp[i], dp[i - cur] + earn + 1);
      }

      earn++;
      cur += earn;
    }
    return dp[n];
  }
};