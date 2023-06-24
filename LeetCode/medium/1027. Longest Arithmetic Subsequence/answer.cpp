#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (N^2)
// time : O(N^2)
// space : O(N * M)
class Solution {
 public:
  int longestArithSeqLength(vector<int>& nums) {
    int size = nums.size();
    int dp[1001][1001] = {
        0,
    };

    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int before = 0; before < i; before++) {
        int curDiff = nums[i] - nums[before] + 500;

        int curMax = dp[before][curDiff] + 1;
        dp[i][curDiff] = max(dp[i][curDiff], curMax);

        answer = max(answer, dp[i][curDiff]);
      }
    }

    return answer + 1;
  }
};