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

// use dynamic programming one pass

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int size = nums.size();
    if (size < 3) return 0;

    vector<int> dp(size, 0);  // i번째 index가 끝 range일 때의 arithmetic 개수
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = nums[2] - nums[1] == nums[1] - nums[0] ? 1 : 0;

    int answer = dp[2];
    for (int i = 3; i < size; ++i) {
      int left = nums[i - 1] - nums[i - 2];
      int right = nums[i] - nums[i - 1];

      dp[i] = right == left ? dp[i - 1] + 1 : 0;
      answer += dp[i];
    }
    return answer;
  }
};