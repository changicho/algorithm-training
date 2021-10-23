#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = 0;
    int answer = size + 1;

    int curSum = 0;
    while (left < size) {
      if (target <= curSum) {
        answer = min(answer, right - left);
      }

      if (curSum < target && right < size) {
        curSum += nums[right];
        right++;
        continue;
      }

      curSum -= nums[left];
      left += 1;
    }

    return answer == size + 1 ? 0 : answer;
  }
};