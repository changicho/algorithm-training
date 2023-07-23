#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size();

    // dp[index][num];
    int dp[100001][2] = {
        0,
    };

    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < size; i++) {
      // fill 1
      dp[i][0] = 1;
      if (nums1[i - 1] <= nums1[i]) {
        dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
      }
      if (nums2[i - 1] <= nums1[i]) {
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
      }

      // fill 2
      dp[i][1] = 1;
      if (nums1[i - 1] <= nums2[i]) {
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
      }
      if (nums2[i - 1] <= nums2[i]) {
        dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
      }
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      answer = max({answer, dp[i][0], dp[i][1]});
    }

    return answer;
  }
};