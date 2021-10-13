#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use LCS

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    if (text2.length() > text1.length()) swap(text2, text1);
    int length1 = text1.length(), length2 = text2.length();

    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));

    for (int first = 1; first <= length1; ++first) {
      for (int second = 1; second <= length2; ++second) {
        if (text1[first - 1] == text2[second - 1]) {
          dp[first][second] = dp[first - 1][second - 1] + 1;
        } else {
          dp[first][second] = max(dp[first - 1][second], dp[first][second - 1]);
        }
      }
    }

    return dp[length1][length2];
  }
};