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
// time : O(N * S * log_2(M))
// space : O(S)
class Solution {
 public:
  int minOperations(vector<int>& nums, int sum) {
    int size = nums.size();

    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;
    for (int& num : nums) {
      vector<int> newDp(sum + 1, INT_MAX);
      if (num <= sum) newDp[num] = 0;

      for (int before = 0; before <= sum; before++) {
        if (dp[before] == INT_MAX) continue;
        newDp[before] = min(newDp[before], dp[before]);

        for (int cur = num, count = 0; cur >= 1; cur /= 2, count++) {
          if ((before + cur) > sum) continue;
          newDp[before + cur] = min(newDp[before + cur], dp[before] + count);
        }
        for (int cur = num, count = 0; cur <= sum; cur *= 2, count++) {
          if ((before + cur) > sum) break;
          newDp[before + cur] = min(newDp[before + cur], dp[before] + count);
        }
      }

      swap(dp, newDp);
    }

    return dp[sum] == INT_MAX ? -1 : dp[sum];
  }
};