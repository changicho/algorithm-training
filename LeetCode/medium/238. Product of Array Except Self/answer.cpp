#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dp from left, right

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer(size, 1);

    vector<int> fromLefts(size, 1);
    vector<int> fromRights(size, 1);

    for (int i = 1; i < size; i++) {
      int reversed = size - 1 - i;

      fromLefts[i] = fromLefts[i - 1] * nums[i - 1];
      fromRights[reversed] = fromRights[reversed + 1] * nums[reversed + 1];
    }

    for (int i = 0; i < size; i++) {
      answer[i] = fromLefts[i] * fromRights[i];
    }

    return answer;
  }
};

// use update left, right

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer(size, 1);

    int fromLeft = 1, fromRight = 1;

    for (int i = 0; i < size; i++) {
      int reversed = size - 1 - i;

      answer[i] *= fromLeft;
      answer[reversed] *= fromRight;
      fromLeft *= nums[i];
      fromRight *= nums[reversed];
    }

    return answer;
  }
};