#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (memoization)

class Solution {
 private:
  int recursive(vector<int> nums, int target, vector<int>& dp) {
    if (dp[target] != -1) return dp[target];

    int res = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      if (target - nums[i] < 0) continue;

      res += recursive(nums, target - nums[i], dp);
    }

    dp[target] = res;

    return res;
  }

 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, -1);
    dp[0] = 1;

    int answer = recursive(nums, target, dp);

    return answer;
  }
};

// use dynamic programming (iteration)

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;

    for (int value = 1; value <= target; ++value) {
      for (int num : nums) {
        if (value - num < 0) continue;

        dp[value] += dp[value - num];
      }
    }

    return (int)dp[target];
  }
};

// use dynamic programming (iteration)

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    int size = nums.size();
    vector<unsigned int> dp(target + 1, 0);

    for (int num : nums) {
      if (num > target) continue;
      dp[num] += 1;
    }

    for (int value = 1; value <= target; value++) {
      for (int num : nums) {
        int next = num + value;
        if (next > target) continue;

        dp[next] += dp[value];
      }
    }

    return (int)dp[target];
  }
};
