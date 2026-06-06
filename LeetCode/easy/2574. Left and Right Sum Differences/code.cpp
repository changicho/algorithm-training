#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> leftRigthDifference(vector<int>& nums) {
    int size = nums.size();
    vector<int> leftSums(size), rightSums(size);

    for (int i = 1; i < size; i++) {
      leftSums[i] = leftSums[i - 1] + nums[i - 1];
    }
    for (int i = size - 2; i >= 0; i--) {
      rightSums[i] = rightSums[i + 1] + nums[i + 1];
    }

    vector<int> answer(size);
    for (int i = 0; i < size; i++) {
      answer[i] = abs(leftSums[i] - rightSums[i]);
    }
    return answer;
  }
};

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> leftRightDifference(vector<int>& nums) {
    int left = 0;
    int right = accumulate(nums.begin(), nums.end(), 0);

    vector<int> answer;
    for (int& num : nums) {
      right -= num;
      answer.push_back(abs(right - left));

      left += num;
    }
    return answer;
  }
};