#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumAverageDifference(vector<int>& nums) {
    int size = nums.size();
    long long leftSum = 0, rightSum = 0;
    for (int& num : nums) {
      rightSum += num;
    }

    long long minimum = rightSum;
    int answer = 0;
    for (int i = 0; i < size; i++) {
      leftSum += nums[i];
      rightSum -= nums[i];

      long long cur;
      if (i == size - 1) {
        cur = abs(leftSum / (i + 1));
      } else {
        cur = abs(leftSum / (i + 1) - rightSum / (size - (i + 1)));
      }

      if (cur < minimum) {
        minimum = cur;
        answer = i;
      }
    }

    return answer;
  }
};