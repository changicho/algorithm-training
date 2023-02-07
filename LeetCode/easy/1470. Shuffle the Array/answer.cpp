#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use extra space
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ret;

    for (int i = 0; i < n; i++) {
      ret.push_back(nums[i]);
      ret.push_back(nums[n + i]);
    }

    return ret;
  }
};

// use multiple
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    for (int i = 0; i < nums.size(); i++) {
      nums[i] *= 10000;
    }

    for (int i = 0; i < n; i++) {
      nums[2 * i] += nums[i] / 10000;
      nums[2 * i + 1] += nums[n + i] / 10000;
    }

    for (int i = 0; i < nums.size(); i++) {
      nums[i] %= 10000;
    }

    return nums;
  }
};