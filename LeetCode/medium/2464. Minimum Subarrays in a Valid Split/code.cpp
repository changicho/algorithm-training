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
  int validSubarraySplit(vector<int>& nums) {
    int size = nums.size();

    vector<long long> dp(size, INT_MAX);

    for (int right = 0; right < size; right++) {
      for (int left = 0; left <= right; left++) {
        if (gcd(nums[left], nums[right]) == 1) continue;

        long long before = (left - 1) < 0 ? 0 : dp[left - 1];
        dp[right] = min(dp[right], before + 1);
      }
    }

    if (dp.back() == INT_MAX) return -1;
    return dp.back();
  }
};