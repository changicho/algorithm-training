#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int answer = 20000;
    int size = nums.size();

    sort(nums.begin(), nums.end());

    for (int index = 0; index < size - 2 && answer != target; index++) {
      if (index > 0 && nums[index] == nums[index - 1]) continue;

      int start = index + 1;
      int end = size - 1;

      while (start < end) {
        int sum = nums[index] + nums[start] + nums[end];

        if (abs(answer - target) > abs(sum - target)) {
          answer = sum;
        }
        if (sum > target) {
          end--;
        } else {
          start++;
        }
      }
    }

    return answer;
  }
};

// use binary search

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int answer = 20000;
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int first = 0; first < size - 2 && answer != target; first++) {
      for (int second = first + 1; second < size - 1; second++) {
        int diff = target - nums[first] - nums[second];
        int end = upper_bound(nums.begin() + second + 1, nums.end(), diff) - nums.begin();
        int start = end - 1;

        if (end < size && abs(nums[first] + nums[second] + nums[end] - target) < abs(answer - target)) {
          answer = nums[first] + nums[second] + nums[end];
        }
        if (start > second && abs(nums[first] + nums[second] + nums[start] - target) < abs(answer - target)) {
          answer = nums[first] + nums[second] + nums[start];
        }
      }
    }
    return answer;
  }
};