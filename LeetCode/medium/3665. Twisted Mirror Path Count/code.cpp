#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

// dynamic programming
// time : O(RC)
// space : O(RC)
class Solution {
 public:
  int uniquePaths(vector<vector<int>>& grid) {
    const int MOD = 1e9 + 7;
    // 0 : right, 1 : down
    int dp[501][501][2] = {
        0,
    };

    int rows = grid.size();
    int cols = grid[0].size();

    dp[0][0][0] = 1;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        for (int dir = 0; dir <= 1; dir++) {
          bool isMirror = grid[y][x] == 1;

          if (x + 1 < cols && !(isMirror && dir == 0)) {
            dp[y][x + 1][0] += dp[y][x][dir];
            dp[y][x + 1][0] %= MOD;
          }
          if (y + 1 < rows && !(isMirror && dir == 1)) {
            dp[y + 1][x][1] += dp[y][x][dir];
            dp[y + 1][x][1] %= MOD;
          }
        }
      }
    }

    int answer = 0;
    for (int dir = 0; dir <= 1; dir++) {
      answer += dp[rows - 1][cols - 1][dir];
      answer %= MOD;
    }

    return answer;
  }
};
