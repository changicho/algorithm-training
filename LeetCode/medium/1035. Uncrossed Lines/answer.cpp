#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use LCS
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    if (nums2.size() > nums1.size()) swap(nums2, nums1);
    int size1 = nums1.size(), size2 = nums2.size();

    int dp[501][501] = {
        0,
    };

    for (int first = 1; first <= size1; ++first) {
      for (int second = 1; second <= size2; ++second) {
        if (nums1[first - 1] == nums2[second - 1]) {
          dp[first][second] = dp[first - 1][second - 1] + 1;
        } else {
          dp[first][second] = max(dp[first - 1][second], dp[first][second - 1]);
        }
      }
    }

    return dp[size1][size2];
  }
};