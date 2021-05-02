#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use STL

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    do {
      answer.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return answer;
  }
};

// my permutation

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;

    permutation(nums, answer, 0);

    return answer;
  }

  void permutation(vector<int>& nums, vector<vector<int>>& array, int start) {
    int size = nums.size();
    if (start >= size) {
      array.push_back(nums);
      return;
    }

    for (int i = start; i < size; i++) {
      swap(nums[start], nums[i]);
      permutation(nums, array, start + 1);
      swap(nums[start], nums[i]);
    }
  }
};
