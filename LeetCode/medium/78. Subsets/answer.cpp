#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursive

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret;
    vector<int> array;

    recursive(array, -1, nums, ret);
    return ret;
  }

  void recursive(vector<int> &array, int index, vector<int> &nums, vector<vector<int>> &answer) {
    answer.push_back(array);

    for (int i = index + 1; i < nums.size(); i++) {
      int num = nums[i];

      array.push_back(num);
      recursive(array, i, nums, answer);
      array.pop_back();
    }
  }
};

// use bitmask

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret;

    int limit = pow(2, nums.size());

    for (int digit = 0; digit < limit; digit++) {
      vector<int> array;
      for (int i = 0; i < nums.size(); i++) {
        if (digit & (1 << i)) {
          array.push_back(nums[i]);
        }
      }
      ret.push_back(array);
    }

    return ret;
  }
};

// use iterate

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret = {{}};

    for (int num : nums) {
      int size = ret.size();

      for (int i = 0; i < size; i++) {
        ret.push_back(ret[i]);
        ret.back().push_back(num);
      }
    }

    return ret;
  }
};