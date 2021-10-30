#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use LCS

class Solution {
 private:
  int longestCommonSubsequence(string &word1, string &word2) {
    int length1 = word1.length(), length2 = word2.length();
    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));

    for (int idx1 = 1; idx1 <= length1; ++idx1) {
      for (int idx2 = 1; idx2 <= length2; ++idx2) {
        if (word1[idx1 - 1] == word2[idx2 - 1]) {
          dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
        } else {
          dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
        }
      }
    }

    return dp[length1][length2];
  }

 public:
  int minDistance(string word1, string word2) {
    int length1 = word1.length();
    int length2 = word2.length();

    int lcsLength = longestCommonSubsequence(word1, word2);

    return length1 + length2 - 2 * lcsLength;
  }
};