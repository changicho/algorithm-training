#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use STL

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    do {
      answer.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return answer;
  }
};

// my next permutation

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    do {
      answer.push_back(nums);
    } while (nextPermutation(nums));

    return answer;
  }

  bool nextPermutation(vector<int>& nums) {
    int size = nums.size();
    int decreasingIdx = size - 1;

    while (decreasingIdx > 0 && nums[decreasingIdx - 1] >= nums[decreasingIdx]) {
      decreasingIdx--;
    }
    decreasingIdx--;

    if (decreasingIdx < 0) {
      return false;
    }

    int largerIdx = size - 1;
    while (largerIdx >= 0 && nums[largerIdx] <= nums[decreasingIdx]) {
      largerIdx--;
    }
    swap(nums[decreasingIdx], nums[largerIdx]);

    reverse(nums.begin() + decreasingIdx + 1, nums.end());
    return true;
  }
};