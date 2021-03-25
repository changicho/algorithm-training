#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};

// my_lower_bound

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return my_lower_bound(nums, target);
  }

 private:
  int my_lower_bound(vector<int>& nums, int key) {
    int start = 0;
    int end = nums.size();
    int mid;

    while (start < end) {
      mid = (start + end) / 2;

      if (nums[mid] < key) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return end;
  }
};