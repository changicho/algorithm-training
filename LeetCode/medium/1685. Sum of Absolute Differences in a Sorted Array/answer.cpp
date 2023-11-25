#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int size = nums.size();

    vector<int> leftSums(size, 0);
    vector<int> rightSums(size, 0);
    for (int i = 0; i < size; i++) {
      if (i - 1 >= 0) leftSums[i] = leftSums[i - 1];
      leftSums[i] += nums[i];
    }
    for (int i = size - 1; i >= 0; i--) {
      if (i + 1 < size) rightSums[i] = rightSums[i + 1];
      rightSums[i] += nums[i];
    }

    vector<int> answer(size, 0);
    for (int i = 0; i < size; i++) {
      int leftCount = i;
      int rightCount = size - i - 1;

      if (i - 1 >= 0) {
        answer[i] += leftCount * nums[i] - leftSums[i - 1];
      }
      if (i + 1 < size) {
        answer[i] += rightSums[i + 1] - rightCount * nums[i];
      }
    }

    return answer;
  }
};

// use prefix sum (space optimized)
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int size = nums.size();

    int leftSum = 0;
    int rightSum = 0;
    for (int& num : nums) {
      rightSum += num;
    }

    for (int i = 0; i < size; i++) {
      int leftCount = i;
      int rightCount = size - i - 1;

      int curAnswer = 0;
      rightSum -= nums[i];

      if (i - 1 >= 0) {
        curAnswer += leftCount * nums[i] - leftSum;
      }
      if (i + 1 < size) {
        curAnswer += rightSum - rightCount * nums[i];
      }

      leftSum += nums[i];

      nums[i] = curAnswer;
    }

    return nums;
  }
};