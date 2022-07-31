#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(K * M * N + L)
// space : O(K * M * N)
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int size = strs.size();

    // dp[i][m][n]; ith, size m, n maximum count
    vector<vector<vector<int>>> dp(
        size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    for (int i = 1; i <= size; i++) {
      int curOne = 0, curZero = 0;
      for (char& c : strs[i - 1]) {
        if (c == '0')
          curZero++;
        else if (c == '1')
          curOne++;
      }

      for (int zero = 0; zero <= m; zero++) {
        for (int one = 0; one <= n; one++) {
          // first str case
          if (zero - curZero < 0 || one - curOne < 0) {
            dp[i][zero][one] = dp[i - 1][zero][one];
            continue;
          }

          dp[i][zero][one] = max(dp[i - 1][zero][one],
                                 dp[i - 1][zero - curZero][one - curOne] + 1);
        }
      }
    }

    return dp[size][m][n];
  }
};