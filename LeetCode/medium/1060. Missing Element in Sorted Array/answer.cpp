#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use iteration
// time : O(N)
// space : O(1)
class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int target = nums.front();

    int i = 0;
    while (k > 0 && i < nums.size()) {
      if (target != nums[i]) {
        k--;
        target++;
        continue;
      }

      i++;
      target++;
    }

    target--;
    if (k > 0) {
      target += k;
    }

    return target;
  }
};

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int size = nums.size();

    int left = 0, right = size - 1;
    while (left < right) {
      int mid = right - (right - left) / 2;

      int missing = nums[mid] - nums[0] - mid;
      if (missing < k) {
        // pick right
        left = mid;
      } else {
        // pick left
        right = mid - 1;
      }
    }

    return nums[0] + k + left;
  }
};