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
 private:
  vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {-1, -1}};

 public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    const int MOD = 1e9 + 7;

    int rows = board.size(), cols = board[0].size();

    board[0][0] = board[rows - 1][cols - 1] = '0';

    // {val, count}
    pair<int, int> dp[101][101];
    dp[rows - 1][cols - 1] = {0, 1};

    for (int y = rows - 1; y >= 0; y--) {
      for (int x = cols - 1; x >= 0; x--) {
        for (vector<int>& d : dirs) {
          int ny = y + d[0], nx = x + d[1];

          if (ny < 0 || nx < 0) continue;
          if (board[ny][nx] == 'X') continue;

          int cur = board[ny][nx] - '0';

          int val = dp[y][x].first;
          int count = dp[y][x].second;
          if (count == 0) continue;

          if (dp[ny][nx].first < val + cur) {
            dp[ny][nx] = {val + cur, count % MOD};
          } else if (dp[ny][nx].first == val + cur) {
            dp[ny][nx].second += count;
            dp[ny][nx].second %= MOD;
          }
        }
      }
    }

    int val = dp[0][0].first, count = dp[0][0].second;
    return {val, count};
  }
};