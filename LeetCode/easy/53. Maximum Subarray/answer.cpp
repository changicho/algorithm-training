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

// use sliding window with explain

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // currentSum = 0
    int currentSum = 0;
    int answer = 0;

    // for(num : nums)
    for (int& num : nums) {
      // if currentSum + num lower than 0
      // currentSum = 0
      // else (currentSum + num eqaul or bigger than 0
      // currentSum += num
      if (currentSum + num < 0) {
        currentSum = 0;
      } else {
        currentSum += num;
      }
      // update answer
      answer = max(answer, currentSum);
    }
    // if currentSum == 0
    // we find the maximum one of nums
    if (answer == 0) {
      int maximum = nums.front();
      for (int& num : nums) {
        maximum = max(num, maximum);
      }
      answer = maximum;
    }
    return answer;
  }
};

// use one pass

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    // we set the value can be answer. one of nums
    int answer = nums.front();

    // iterate all num in nums
    for (int& num : nums) {
      // update current Sum
      currentSum += num;
      // update answer
      answer = max(answer, currentSum);

      // if currentSum is smaller than 0, we don't use current subArray
      currentSum = max(0, currentSum);
    }

    return answer;
  }
};