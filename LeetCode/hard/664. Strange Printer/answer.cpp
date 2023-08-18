#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// usd dynamic programming
// time : O(N^3)
// space : O(N^2)
class Solution {
 public:
  int strangePrinter(string s) {
    int size = s.size();

    int dp[101][101] = {
        0,
    };

    for (int len = 1; len <= size; len++) {
      for (int left = 0; left <= size - len; left++) {
        int right = left + len - 1;

        dp[left][right] = len;

        int before = -1;
        for (int i = left; i < right; i++) {
          if (s[i] != s[right] && before == -1) {
            before = i;
          }
          if (before != -1) {
            dp[left][right] =
                min(dp[left][right], 1 + dp[before][i] + dp[i + 1][right]);
          }
        }

        if (before == -1) {
          dp[left][right] = 0;
        }
      }
    }

    return dp[0][size - 1] + 1;
  }
};