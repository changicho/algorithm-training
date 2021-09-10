#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 private:
  int getMaximumSum(vector<int> &nums) {
    int answer = nums.front();
    int sum = 0;

    for (int num : nums) {
      sum += num;
      answer = max(sum, answer);

      if (sum < 0) sum = 0;
    }

    return answer;
  }

  int getMinimumSum(vector<int> &nums) {
    int answer = nums.front();
    int sum = 0;

    for (int num : nums) {
      sum += num;
      answer = min(sum, answer);

      if (sum > 0) sum = 0;
    }

    return answer;
  }

  int getSum(vector<int> &nums) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    return sum;
  }

 public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int sum = getSum(nums);

    int maximum = getMaximumSum(nums);
    int minimum = getMinimumSum(nums);

    if (sum == minimum) return maximum;
    return max(maximum, sum - minimum);
  }
};

// use only one pass dynamic programming

class Solution {
 public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int sum = 0;
    int maximum = nums.front();
    int maximumSum = 0;

    int minimum = nums.front();
    int minimumSum = 0;

    for (int num : nums) {
      sum += num;
      maximumSum += num;
      minimumSum += num;

      maximum = max(maximum, maximumSum);
      minimum = min(minimum, minimumSum);

      if (maximumSum < 0) maximumSum = 0;
      if (minimumSum > 0) minimumSum = 0;
    }

    if (sum == minimum) return maximum;
    return max(maximum, sum - minimum);
  }
};