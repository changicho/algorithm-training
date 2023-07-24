#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool checkArray(vector<int>& nums, int k) {
    int size = nums.size();
    int diff = 0;
    for (int right = 0; right < size; right++) {
      int left = right - k + 1;

      if (diff > nums[right]) {
        return false;
      }

      nums[right] -= diff;
      diff += nums[right];

      if (right >= k - 1) {
        diff -= nums[left];
      }
    }

    return diff == 0;
  }
};