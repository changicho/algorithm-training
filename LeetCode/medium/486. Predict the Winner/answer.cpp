#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursive
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int maxDiff(vector<int>& nums, int left, int right) {
    if (left == right) {
      return nums[left];
    }

    int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right);
    int scoreByRight = nums[right] - maxDiff(nums, left, right - 1);

    return max(scoreByLeft, scoreByRight);
  }

 public:
  bool PredictTheWinner(vector<int>& nums) {
    int size = nums.size();

    return maxDiff(nums, 0, size - 1) >= 0;
  }
};

// use dynamic programming (top down)
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  int memo[21][21] = {
      -1,
  };

  int maxDiff(vector<int>& nums, int left, int right) {
    if (memo[left][right] != -1) return memo[left][right];

    if (left == right) {
      return memo[left][right] = nums[left];
    }

    int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right);
    int scoreByRight = nums[right] - maxDiff(nums, left, right - 1);

    return memo[left][right] = max(scoreByLeft, scoreByRight);
  }

 public:
  bool PredictTheWinner(vector<int>& nums) {
    memset(memo, -1, sizeof(memo));
    int size = nums.size();

    return maxDiff(nums, 0, size - 1) >= 0;
  }
};

// use dynamic programming (bottom up)
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> dp(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
      dp[i][i] = nums[i];
    }

    for (int i = 1; i < size; i++) {
      for (int j = 0; j + i < size; j++) {
        dp[j][j + i] =
            max(nums[j + i] - dp[j][j + i - 1], nums[j] - dp[j + 1][j + i]);
      }
    }
    return dp[0][size - 1] >= 0;
  }
};