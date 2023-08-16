#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (bottom up)
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> validNext(vector<int>& nums, int i) {
    int size = nums.size();
    vector<int> ret;
    if (i + 1 < size && nums[i] == nums[i + 1]) {
      ret.push_back(i + 1);
    }

    if (i + 2 < size) {
      if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
        ret.push_back(i + 2);
      } else if (nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) {
        ret.push_back(i + 2);
      }
    }
    return ret;
  }

 public:
  bool validPartition(vector<int>& nums) {
    int size = nums.size();

    bool valid[100001] = {
        false,
    };
    for (int next : validNext(nums, 0)) {
      valid[next] = true;
    }
    for (int i = 0; i < size - 1; i++) {
      if (!valid[i]) continue;

      for (int next : validNext(nums, i + 1)) {
        valid[next] = true;
      }
    }

    return valid[size - 1];
  }
};

// use dynamic programming (space optimized)
// time : O(N)
// space : O(1)
class Solution {
 private:
  vector<int> validNext(vector<int>& nums, int i) {
    int size = nums.size();
    vector<int> ret;
    if (i + 1 < size && nums[i] == nums[i + 1]) {
      ret.push_back(i + 1);
    }

    if (i + 2 < size) {
      if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
        ret.push_back(i + 2);
      } else if (nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) {
        ret.push_back(i + 2);
      }
    }
    return ret;
  }

 public:
  bool validPartition(vector<int>& nums) {
    int size = nums.size();

    bool valid[3] = {
        false,
    };
    for (int next : validNext(nums, 0)) {
      valid[next % 3] = true;
    }
    for (int i = 0; i < size - 1; i++) {
      if (!valid[i % 3]) continue;
      valid[i % 3] = false;

      for (int next : validNext(nums, i + 1)) {
        valid[next % 3] = true;
      }
    }

    return valid[(size - 1) % 3];
  }
};

// use dynamic programming (top down)
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool solve(vector<int>& nums, int i, vector<int>& dp) {
    if (i == nums.size()) return true;
    if (dp[i] != -1) return dp[i];

    if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
      if (solve(nums, i + 2, dp)) return true;
      if (i + 2 < nums.size() && nums[i] == nums[i + 2]) {
        if (solve(nums, i + 3, dp)) return true;
      }
    }
    if (i + 2 < nums.size() && nums[i] == nums[i + 1] - 1 &&
        nums[i] == nums[i + 2] - 2) {
      if (solve(nums, i + 3, dp)) return true;
    }
    return dp[i] = false;
  }

 public:
  bool validPartition(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return solve(nums, 0, dp);
  }
};