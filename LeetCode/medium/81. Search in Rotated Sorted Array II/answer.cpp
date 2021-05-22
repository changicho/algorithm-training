#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    for (int num : nums) {
      if (num == target) return true;
    }
    return false;
  }
};

// use binary search with avoid duplicate

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      while (left < right && nums[left] == nums[left + 1]) left++;
      while (left < right && nums[right] == nums[right - 1]) right--;
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) return true;

      if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return false;
  }
};