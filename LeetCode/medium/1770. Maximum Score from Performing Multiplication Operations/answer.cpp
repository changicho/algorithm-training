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
