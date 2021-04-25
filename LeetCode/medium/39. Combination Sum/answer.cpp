#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use reference

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> numbers;

    sort(candidates.begin(), candidates.end());

    recursive(candidates, target, 0, numbers, ret);

    return ret;
  }

  void recursive(vector<int>& nums, int target, int index, vector<int>& numbers, vector<vector<int>>& results) {
    for (int i = index; i < nums.size(); i++) {
      if (target < nums[i]) {
        break;
      }
      if (target == nums[i]) {
        numbers.push_back(nums[i]);
        results.push_back(numbers);
        numbers.pop_back();

        break;
      }

      numbers.push_back(nums[i]);
      recursive(nums, target - nums[i], i, numbers, results);
      numbers.pop_back();
    }
  }
};

// not use sorting

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> prefix;

    recursive(candidates, target, 0, prefix, results);

    return results;
  }

  void recursive(vector<int>& nums, int target, int start, vector<int>& prefix, vector<vector<int>>& results) {
    for (int i = start; i < nums.size(); i++) {
      if (target == nums[i]) {
        prefix.push_back(nums[i]);
        results.push_back(prefix);
        prefix.pop_back();
      } else if (target - nums[i] > 0) {
        prefix.push_back(nums[i]);
        recursive(nums, target - nums[i], i, prefix, results);
        prefix.pop_back();
      }
    }
  }
};