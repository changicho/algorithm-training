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