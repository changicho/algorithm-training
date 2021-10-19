#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search (pick left)

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = size - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] <= nums[right]) {
        // pick left part
        right = mid;
      } else {
        // pick right part
        left = mid + 1;
      }
    }

    return nums[left];
  }
};

// use binary search

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = size - 1;
    int answer = nums.front();

    while (left <= right) {
      int mid = left + (right - left) / 2;

      answer = min(answer, nums[mid]);

      if (nums[mid] <= nums[right]) {
        // pick left part
        right = mid - 1;
      } else {
        // pick right part
        left = mid + 1;
      }
    }

    return answer;
  }
};