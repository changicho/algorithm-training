#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search (find left)

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = size - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] > nums[mid + 1]) {
        // pick left part
        right = mid;
      } else {
        // pick right part
        left = mid + 1;
      }
    }

    return left;
  }
};

// use binary search

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = size - 1;

    int answer = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (mid > 0 && nums[mid - 1] > nums[mid]) {
        // pick left part
        right = mid - 1;
      } else if (mid < size - 1 && nums[mid] < nums[mid + 1]) {
        // pick right part
        left = mid + 1;
      } else {
        // find answer case
        answer = mid;
        break;
      }
    }
    return answer;
  }
};