#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maximumTop(vector<int>& nums, int k) {
    int size = nums.size();
    if (size == 1 && k % 2 == 1) {
      return -1;
    }

    int maximum = -1;
    for (int i = 0; i < min(size, k - 1); i++) {
      maximum = max(maximum, nums[i]);
    }

    if (k < size) {
      maximum = max(maximum, nums[k]);
    }

    return maximum;
  }
};