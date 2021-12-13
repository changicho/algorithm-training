#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// make it self

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    int left = size - 2, right = size - 1;

    // find first decreasing point from back (nums[i] < nums[i+1])
    while (left >= 0) {
      if (nums[left] < nums[left + 1]) {
        break;
      }
      left--;
    }

    // if there are no decreasing point (already sorted descending order)
    if (left < 0) {
      // rearrange it sorted in ascending order
      reverse(nums.begin(), nums.end());
      return;
    }

    // find first point nums[left] < nums[right]
    while (left < right) {
      if (nums[left] < nums[right]) {
        break;
      }
      right--;
    }

    // swap left and right
    swap(nums[left], nums[right]);
    // reverse the part after left
    reverse(nums.begin() + left + 1, nums.end());
  }
};

// use STL

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
  }
};
