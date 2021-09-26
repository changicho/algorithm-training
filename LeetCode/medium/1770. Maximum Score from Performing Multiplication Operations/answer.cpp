#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use recursive + memoization

class Solution {
 private:
  vector<vector<int>> dp;
  int recursive(vector<int>& nums, vector<int>& multi, int index, int left,
                int right) {
    if (index == multi.size()) return 0;
    if (dp[left][index] != INT_MIN) return dp[left][index];

    int fromLeft = multi[index] * nums[left] +
                   recursive(nums, multi, index + 1, left + 1, right);
    int fromRight = multi[index] * nums[right] +
                    recursive(nums, multi, index + 1, left, right - 1);

    return dp[left][index] = max(fromLeft, fromRight);
  }

 public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int length = multipliers.size();
    dp.resize(length, vector<int>(length, INT_MIN));

    int size = nums.size();
    int left = 0, right = size - 1;

    int answer = recursive(nums, multipliers, 0, left, right);
    return answer;
  }
};

// use bottom-up dynamic programming

class Solution {
 public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();
    int diff = n - m;

    vector<int> dp(m, 0), before(m, 0);

    // initialize
    for (int left = 0; left < n - diff; left++) {
      int right = left;

      int fromLeft = nums[left] * multipliers[m - 1];
      int fromRight = nums[right + diff] * multipliers[m - 1];

      dp[right] = max(fromLeft, fromRight);
    }

    for (int length = 1; length < m; length++) {
      for (int left = 0; left < n - length - diff; left++) {
        int right = left + length;

        int fromLeft = dp[right] + nums[left] * multipliers[m - 1 - length];
        int fromRight =
            dp[right - 1] + nums[right + diff] * multipliers[m - 1 - length];

        before[right] = max(fromLeft, fromRight);
      }

      swap(dp, before);
    }

    return dp.back();
  }
};