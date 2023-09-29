#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    int size = nums.size();

    int diff = 0;

    for (int i = 1; i < size; i++) {
      if (nums[i] == nums[i - 1]) continue;

      if (diff * (nums[i] - nums[i - 1]) < 0) return false;
      diff = nums[i] - nums[i - 1] > 0 ? 1 : -1;
    }
    return true;
  }
};