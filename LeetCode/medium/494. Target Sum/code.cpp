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

// use brute force
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  void recursive(vector<int>& nums, int i, int sum, int target) {
    int size = nums.size();
    if (i == size) {
      if (sum == target) answer++;
      return;
    }

    recursive(nums, i + 1, sum + nums[i], target);
    recursive(nums, i + 1, sum - nums[i], target);
  };

 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int size = nums.size();

    recursive(nums, 0, 0, target);

    return answer;
  }
};

// use dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int size = nums.size();

    int center = 1000;
    int dp[20][2001] = {
        0,
    };

    dp[0][center + nums[0]] += 1;
    dp[0][center - nums[0]] += 1;

    for (int i = 1; i < size; i++) {
      for (int sum = -center; sum <= center; sum++) {
        if (dp[i - 1][sum + center] > 0) {
          int before = sum + center;

          dp[i][before + nums[i]] += dp[i - 1][before];
          dp[i][before - nums[i]] += dp[i - 1][before];
        }
      }
    }

    // if(center - abs(target) < 0) return 0;
    if (target + center < 0 || target + center > 2000) return 0;
    return dp[size - 1][target + center];
  }
};