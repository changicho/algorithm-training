#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int from = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int to = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    if (from > to) {
      from = to = -1;
    }

    return {from, to};
  }
};

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int from = lower_bound(nums, target);
    int to = upper_bound(nums, target) - 1;

    if (from > to) {
      from = to = -1;
    }

    return {from, to};
  }

  int lower_bound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return right;
  }

  int upper_bound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return right;
  }
};