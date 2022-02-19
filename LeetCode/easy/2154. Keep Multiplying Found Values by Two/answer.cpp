#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    // sort to find next original in one pass
    sort(nums.begin(), nums.end());

    // iterate nums
    for (int& n : nums) {
      // if same, increase original
      if (n == original) original *= 2;
    }

    return original;
  }
};

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    // convert nums to hash set
    unordered_set<int> uniques(nums.begin(), nums.end());

    // increase original until not found
    while (uniques.count(original) > 0) {
      original *= 2;
    }

    return original;
  }
};