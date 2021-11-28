#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};

// my_lower_bound

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return my_lower_bound(nums, target);
  }

 private:
  int my_lower_bound(vector<int>& nums, int key) {
    int start = 0;
    int end = nums.size();
    int mid;

    while (start < end) {
      mid = (start + end) / 2;

      if (nums[mid] < key) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return end;
  }
};

// use binary search

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    // first we set the range of part
    int left = 0, right = size;
    // we will set left is the answer.
    // so we set the right is the limit + 1 of the range (cannot be answer)

    // while left is lower than right
    while (left < right) {
      int mid = (left + right) / 2;

      // if mid < target
      if (nums[mid] < target) {
        // target will be in right part
        left = mid + 1;
      } else {  // else
        // target will be in left part
        right = mid;
      }
    }

    // left is the answer
    return left;
  }
};