#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int rows = board.size(), cols = board.front().size();

    vector<int> values;
    for (int y = rows - 1; y >= 0; y--) {
      if ((rows - 1 - y) % 2 == 0) {
        for (int x = 0; x < cols; x++) {
          values.push_back(board[y][x]);
        }
      } else {
        for (int x = cols - 1; x >= 0; x--) {
          values.push_back(board[y][x]);
        }
      }
    }

    vector<int> dp(rows * cols, INT_MAX);

    queue<int> q;
    q.push(0);
    dp[0] = 0;

    int step = 0;
    while (!q.empty()) {
      int i = q.front();
      q.pop();

      for (int j = 1; j <= 6; j++) {
        int next = i + j;
        if (next >= rows * cols) break;

        if (values[next] != -1) {
          int target = values[next] - 1;

          if (dp[target] > dp[i] + 1) {
            q.push(target);
            dp[target] = min(dp[target], dp[i] + 1);
          }
        } else {
          if (dp[next] > dp[i] + 1) {
            q.push(next);
            dp[next] = min(dp[next], dp[i] + 1);
          }
        }
      }
    }

    return dp.back() == INT_MAX ? -1 : dp.back();
  }
};