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
    int decreasingIdx = size - 2;

    while (decreasingIdx >= 0 && nums[decreasingIdx] >= nums[decreasingIdx + 1]) {
      decreasingIdx--;
    }

    if (decreasingIdx >= 0) {
      int largerIdx = size - 1;
      while (largerIdx >= 0 && nums[largerIdx] <= nums[decreasingIdx]) {
        largerIdx--;
      }
      swap(nums[decreasingIdx], nums[largerIdx]);
    }
    reverse(nums.begin() + decreasingIdx + 1, nums.end());
  }
};

// use STL

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
  }
};
