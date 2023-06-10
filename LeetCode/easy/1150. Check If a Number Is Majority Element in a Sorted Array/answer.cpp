#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  bool isMajorityElement(vector<int>& nums, int target) {
    int count = upper_bound(nums.begin(), nums.end(), target) -
                lower_bound(nums.begin(), nums.end(), target);

    return count > (nums.size() / 2);
  }
};