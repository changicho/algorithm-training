#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int size = nums.size();
    int limit = 2001;
    vector<vector<int>> dp(size, vector<int>(size, limit));

    for (int i = 1; i < size; i++) {
      dp[i - 1][i] = nums[i] - nums[i - 1];
    }

    int answer = 0;
    for (int length = 3; length <= size; length++) {
      for (int left = 0; left <= size - length; left++) {
        int right = left + (length - 1);
        int leftPart = dp[left][right - 1];
        int rightPart = dp[right - 1][right];

        if (leftPart == rightPart && leftPart != limit) {
          dp[left][right] = leftPart;
          answer += 1;
        }
      }
    }

    return answer;
  }
};