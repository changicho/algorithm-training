#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  bool isMatch(string s, string p) {
    int length = s.size(), patternLength = p.size();
    vector<vector<bool>> dp(length + 1, vector<bool>(patternLength + 1, false));
    dp[0][0] = true;

    for (int pI = 2; pI <= patternLength; pI++) {
      if (p[pI - 1] == '*' && dp[0][pI - 2]) {
        dp[0][pI] = true;
      }
    }

    for (int sI = 1; sI <= length; sI++) {
      for (int pI = 1; pI <= patternLength; pI++) {
        if (p[pI - 1] == '*') {  // wildcard case
          if (dp[sI][pI - 2]) {
            dp[sI][pI] = true;
          } else {
            if (!dp[sI - 1][pI]) continue;
            dp[sI][pI] = (s[sI - 1] == p[pI - 2] || p[pI - 2] == '.');
          }
        } else if (p[pI - 1] == '.') {  // skip case
          if (!dp[sI - 1][pI - 1]) continue;
          dp[sI][pI] = true;
        } else {  // normal case
          if (!dp[sI - 1][pI - 1]) continue;
          dp[sI][pI] = (s[sI - 1] == p[pI - 1]);
        }
      }
    }

    return dp[length][patternLength];
  }
};