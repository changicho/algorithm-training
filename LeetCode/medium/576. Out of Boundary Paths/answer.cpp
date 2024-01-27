#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * M * K)
// space : O(N * M * K)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  const int MOD = 1e9 + 7;

 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // step, y, x;
    int dp[51][51][51] = {
        0,
    };

    int answer = 0;

    dp[0][startRow][startColumn] = 1;

    for (int step = 0; step < maxMove; step++) {
      for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
          if (dp[step][y][x] == 0) continue;

          for (Axis &dir : dirs) {
            Axis next = {y + dir.y, x + dir.x};

            if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n) {
              answer += dp[step][y][x];
              answer %= MOD;

              continue;
            }
            if (step + 1 >= maxMove) continue;
            dp[step + 1][next.y][next.x] += dp[step][y][x];
            dp[step + 1][next.y][next.x] %= MOD;
          }
        }
      }
    }

    return answer;
  }
};