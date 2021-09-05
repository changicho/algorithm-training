#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size, 0);
    dp[0] = nums[0];
    if (size == 1) return dp.back();

    dp[1] = max(nums[0], nums[1]);
    if (size == 2) return dp.back();

    dp[2] = max(dp[1], dp[0] + nums[2]);

    for (int i = 3; i < size; i++) {
      dp[i] = max(dp[i - 1], nums[i] + max(dp[i - 2], dp[i - 3]));
    }

    return dp.back();
  }
};

// use even odd dynamic programming

class Solution {
 public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    int even = 0;
    int odd = 0;

    for (int i = 0; i < size; i++) {
      if (i % 2 == 0) {
        even = max(even + nums[i], odd);
      } else {
        odd = max(even, odd + nums[i]);
      }
    }

    return max(even, odd);
  }
};

// use current before dynamic programming

class Solution {
 public:
  int rob(vector<int>& nums) {
    int second = 0, first = 0;

    for (int& num : nums) {
      int cur = max(second + num, first);

      second = first;
      first = cur;
    }

    return first;
  }
};