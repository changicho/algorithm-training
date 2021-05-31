#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int num : nums) {
      if (s.find(num) != s.end()) return true;
      s.insert(num);
    }

    return false;
  }
};

// use sort

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) return true;
    }

    return false;
  }
};
