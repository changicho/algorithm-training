#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(1)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int knightDialer(int n) {
    vector<vector<int>> moves = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {3, 9, 0},
                                 {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

    vector<int> before(10, 1);

    for (int i = 2; i <= n; i++) {
      vector<int> dp(10, 0);
      for (int num = 0; num <= 9; num++) {
        for (int &next : moves[num]) {
          dp[next] += before[num];
          dp[next] %= MOD;
        }
      }

      before = dp;
    }

    int answer = 0;
    for (int &num : before) {
      answer += num;
      answer %= MOD;
    }
    return answer;
  }
};