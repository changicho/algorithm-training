#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  bool canSortArray(vector<int>& nums) {
    int size = nums.size();

    int beforeBit = __builtin_popcount(nums[0]);
    int left = 0;

    for (int i = 1; i < size; i++) {
      int bit = __builtin_popcount(nums[i]);

      if (beforeBit == bit) {
        continue;
      }
      sort(nums.begin() + left, nums.begin() + i);
      beforeBit = bit;
      left = i;
    }

    sort(nums.begin() + left, nums.end());

    for (int i = 0; i < size - 1; i++) {
      if (nums[i] > nums[i + 1]) return false;
    }

    return true;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool canSortArray(vector<int>& nums) {
    int size = nums.size();

    int beforeMax = INT_MIN;
    int curBit = __builtin_popcount(nums[0]);
    int curMax = nums[0];
    int curMin = nums[0];

    for (int i = 1; i < size; i++) {
      int bit = __builtin_popcount(nums[i]);

      if (curBit == bit) {
        curMax = max(curMax, nums[i]);
        curMin = min(curMin, nums[i]);
        continue;
      }

      if (curMax < beforeMax) return false;
      if (beforeMax > curMin) return false;

      beforeMax = curMax;
      curMax = nums[i];
      curMin = nums[i];

      curBit = bit;
    }
    if (curMax < beforeMax) return false;
    if (beforeMax > curMin) return false;

    return true;
  }
};