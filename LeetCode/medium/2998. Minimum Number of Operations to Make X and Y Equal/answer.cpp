#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    vector<int> dp(10001, INT_MAX);

    queue<int> q;
    q.push(x);
    dp[x] = 0;

    int step = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      if (cur == y) break;

      if (cur % 11 == 0) {
        int next = cur / 11;
        if (dp[next] == INT_MAX) {
          q.push(next);
          dp[next] = dp[cur] + 1;
        }
      }
      if (cur % 5 == 0) {
        int next = cur / 5;
        if (dp[next] == INT_MAX) {
          q.push(next);
          dp[next] = dp[cur] + 1;
        }
      }
      if (cur > 0) {
        int next = cur - 1;
        if (dp[next] == INT_MAX) {
          q.push(next);
          dp[next] = dp[cur] + 1;
        }
      }
      if (cur < 10000) {
        int next = cur + 1;
        if (dp[next] == INT_MAX) {
          q.push(next);
          dp[next] = dp[cur] + 1;
        }
      }
    }

    return dp[y];
  }
};