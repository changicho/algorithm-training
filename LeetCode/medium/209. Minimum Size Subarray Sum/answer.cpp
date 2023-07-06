#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int size = nums.size();
    int answer = INT_MAX;

    for (int right = 0, left = 0, sum = 0; right < size; right++) {
      sum += nums[right];

      while (left < right && sum - nums[left] >= target) {
        sum -= nums[left];
        left++;
      }

      if (sum >= target) {
        answer = min(answer, right - left + 1);
      }
    }

    return answer == INT_MAX ? 0 : answer;
  }
};