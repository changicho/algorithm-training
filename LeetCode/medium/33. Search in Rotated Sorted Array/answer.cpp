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
  int search(vector<int>& nums, int target) {
    int size = nums.size();

    int left = 0, right = size - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) return mid;

      // left ~ mid is sorted
      if (nums[left] <= nums[mid]) {
        if (target < nums[mid] && nums[left] <= target) {
          // pick left part
          right = mid - 1;
        } else {
          // pick right part
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[right]) {
          // pick right part
          left = mid + 1;
        } else {
          // pick left part
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};