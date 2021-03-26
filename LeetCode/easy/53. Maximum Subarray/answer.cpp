#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int answer = nums.front();
    int temp = 0;

    for (int num : nums) {
      temp += num;
      answer = max(temp, answer);

      if (temp < 0) {
        temp = 0;
      }
    }

    return answer;
  }
};

// 분할정복기법

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    return divide(nums, 0, nums.size() - 1);
  }

 private:
  int divide(vector<int>& nums, int left, int right) {
    if (left > right) {
      return INT_MIN;
    }

    int mid = (left + right) / 2;
    int leftSumMax = 0;
    int rightSumMax = 0;

    for (int i = mid - 1, sum = 0; i >= left; i--) {
      sum += nums[i];
      leftSumMax = max(sum, leftSumMax);
    }

    for (int i = mid + 1, sum = 0; i <= right; i++) {
      sum += nums[i];
      rightSumMax = max(sum, rightSumMax);
    }

    int leftMax = divide(nums, left, mid - 1);
    int rightMax = divide(nums, mid + 1, right);

    return max(max(leftMax, rightMax), leftSumMax + rightSumMax + nums[mid]);
  }
};