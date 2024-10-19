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
  int target = 0;

  void recursive(int index, vector<int> &nums, int bit) {
    int size = nums.size();
    if (index == size) {
      if (target == bit) answer++;
      return;
    }

    recursive(index + 1, nums, bit);
    recursive(index + 1, nums, bit | nums[index]);
  }

 public:
  int countMaxOrSubsets(vector<int> &nums) {
    for (int &num : nums) {
      target |= num;
    }
    recursive(0, nums, 0);

    return answer;
  }
};

// use dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 private:
  int target = 0;

  vector<vector<int>> dp;

  int recursive(int index, vector<int> &nums, int bit) {
    int size = nums.size();
    if (index == size) {
      return target == bit;
    }

    if (dp[index][bit] != -1) return dp[index][bit];

    int without = recursive(index + 1, nums, bit);
    int within = recursive(index + 1, nums, bit | nums[index]);

    return dp[index][bit] = without + within;
  }

 public:
  int countMaxOrSubsets(vector<int> &nums) {
    for (int &num : nums) {
      target |= num;
    }

    dp.resize(nums.size(), vector<int>(target + 1, -1));

    return recursive(0, nums, 0);
  }
};

// use dynamic programming
// time : O(N * M)
// space : O(M)
class Solution {
 public:
  int countMaxOrSubsets(vector<int> &nums) {
    int bit = 0;
    int dp[1 << 17] = {
        0,
    };

    dp[0] = 1;
    for (int &num : nums) {
      for (int before = bit; before >= 0; before--) {
        dp[before | num] += dp[before];
      }

      bit |= num;
    }

    return dp[bit];
  }
};