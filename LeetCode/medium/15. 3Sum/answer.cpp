#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());
    int size = nums.size();

    for (int targetIdx = 0; targetIdx < size - 2; targetIdx++) {
      if (targetIdx > 0 && nums[targetIdx] == nums[targetIdx - 1]) continue;

      int target = nums[targetIdx];

      int start = targetIdx + 1;
      int end = size - 1;

      while (start < end) {
        int curSum = target + nums[start] + nums[end];
        if (curSum == 0) {
          answer.push_back({target, nums[start], nums[end]});

          while (start < end && nums[start] == nums[start + 1]) start++;
          start++;
          while (start < end && nums[end] == nums[end - 1]) end--;
          end--;
        } else if (curSum < 0) {
          start += 1;
        } else {
          end -= 1;
        }
      }
    }

    return answer;
  }
};