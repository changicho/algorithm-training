#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    size_t size = nums.size();
    if (size < 3) {
      return false;
    }
    stack<int> stk;
    vector<int> minArr(size);  // until i, the min value

    minArr[0] = nums[0];
    for (size_t i = 1; i < size; i++) {
      minArr[i] = min(minArr[i - 1], nums[i]);
    }

    for (size_t i = size - 1; i > 0; i--) {
      if (nums[i] == minArr[i]) continue;

      while (!stk.empty() && stk.top() <= minArr[i]) {
        stk.pop();
      }
      if (!stk.empty() && stk.top() < nums[i]) {
        return true;
      }
      stk.push(nums[i]);
    }
    return false;
  }
};