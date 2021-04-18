#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int size = nums.size();

    int start = 0;
    int end = size - 1;

    while (start <= end) {
      int mid = (start + end) / 2;

      if (nums[mid] == target) return mid;
      if (nums[start] <= nums[mid]) {
        if (target < nums[mid] && nums[start] <= target) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }

    return -1;
  }
};