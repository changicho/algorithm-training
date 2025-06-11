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
// time : O(N * M)
// space : O(M)
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int size = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 == 1) return false;

    vector<bool> dp(sum + 1);
    vector<bool> newDp(sum + 1);

    dp[0] = true;

    for (int i = 1; i <= size; i++) {
      int cur = nums[i - 1];

      newDp.clear();
      for (int before = 0; before <= sum; before++) {
        if (dp[before] == false) continue;

        if (before == sum / 2) return true;
        newDp[before] = true;
        newDp[before + cur] = true;
      }

      swap(dp, newDp);
    }
    return dp[sum / 2];
  }
};