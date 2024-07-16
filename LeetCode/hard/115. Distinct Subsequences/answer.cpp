#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  int numDistinct(string s, string t) {
    long dp[1001][1001] = {
        0,
    };

    for (int i = 0; i < s.size(); i++) {
      dp[i][0] = i > 0 ? dp[i - 1][0] : 0;
      if (s[i] == t[0]) {
        dp[i][0] += 1;
        dp[i][0] = min(dp[i][0], (long)INT_MAX);
      }
      for (int j = 1; j < t.size(); j++) {
        dp[i][j] = i > 0 ? dp[i - 1][j] : 0;

        if (i > 0 && t[j] == s[i]) {
          dp[i][j] += dp[i - 1][j - 1];
          dp[i][j] = min(dp[i][j], (long)INT_MAX);
        }
      }
    }
    int answer = dp[s.size() - 1][t.size() - 1];
    return answer;
  }
};

// use dynamic programming (space optimized)
// time : O(N * M)
// space : O(M)
class Solution {
 public:
  int numDistinct(string s, string t) {
    long before[1001] = {
        0,
    };

    for (int i = 0; i < s.size(); i++) {
      long dp[1001] = {
          0,
      };
      dp[0] = before[0];
      if (s[i] == t[0]) {
        dp[0] += 1;
        dp[0] = min(dp[0], (long)INT_MAX);
      }
      for (int j = 1; j < t.size(); j++) {
        dp[j] = i > 0 ? before[j] : 0;

        if (i > 0 && t[j] == s[i]) {
          dp[j] += before[j - 1];
          dp[j] = min(dp[j], (long)INT_MAX);
        }
      }

      for (int j = 0; j < t.size(); j++) {
        before[j] = dp[j];
      }
    }
    int answer = before[t.size() - 1];
    return answer;
  }
};