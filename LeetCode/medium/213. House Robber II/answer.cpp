#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
      return nums[0];
    }

    vector<int> robFirstDp(2, 0);
    vector<int> robSecondDp(2, 0);

    robFirstDp[0] = nums[0];
    robFirstDp[1] = max(nums[0], nums[1]);
    robSecondDp[0] = 0;
    robSecondDp[1] = nums[1];

    for (int i = 2; i < size; i++) {
      int first = max(robFirstDp[1], nums[i] + robFirstDp[0]);
      robFirstDp[0] = robFirstDp[1];
      robFirstDp[1] = first;

      int second = max(robSecondDp[1], nums[i] + robSecondDp[0]);
      robSecondDp[0] = robSecondDp[1];
      robSecondDp[1] = second;
    }

    return max(robSecondDp[1], robFirstDp[0]);
  }
};