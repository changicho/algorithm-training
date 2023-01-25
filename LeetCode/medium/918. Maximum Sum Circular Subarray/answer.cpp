#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
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
// time : O(N)
// space : O(1)
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

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int size = nums.size();
    vector<int> prefixSums(size + 1, 0);
    vector<int> leftMaxs(size, 0), rightMaxs(size, 0);

    for (int i = 0; i < size; i++) {
      prefixSums[i + 1] = prefixSums[i] + nums[i];
    }

    leftMaxs[0] = nums[0];
    for (int i = 1; i < size; i++) {
      leftMaxs[i] = max(prefixSums[i + 1], leftMaxs[i - 1]);
    }
    rightMaxs[size - 1] = nums[size - 1];
    for (int i = size - 2; i >= 0; i--) {
      rightMaxs[i] = max(prefixSums.back() - prefixSums[i], rightMaxs[i + 1]);
    }

    int answer = nums.front();
    int temp = 0;
    for (int &num : nums) {
      if (temp < 0) temp = 0;
      temp += num;

      answer = max(answer, temp);
    }

    for (int i = 0; i < size - 1; i++) {
      answer = max(answer, leftMaxs[i] + rightMaxs[i + 1]);
    }

    return answer;
  }
};