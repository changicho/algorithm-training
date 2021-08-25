#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use upper_bound, lower_bound

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);

    if (*it == target) return it - nums.begin();

    return -1;
  }
};

// use binary search

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0, right = size - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) return mid;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return -1;
  }
};