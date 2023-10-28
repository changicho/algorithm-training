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
  int countVowelPermutation(int n) {
    int dp[5] = {0};
    for (int i = 0; i < 5; i++) {
      dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
      // a e i o u
      int newDp[5] = {
          0,
      };

      // a
      newDp[0] += dp[1];
      newDp[0] %= MOD;

      // e
      newDp[1] += dp[0];
      newDp[1] %= MOD;
      newDp[1] += dp[2];
      newDp[1] %= MOD;

      // i
      newDp[2] += dp[0];
      newDp[2] %= MOD;
      newDp[2] += dp[1];
      newDp[2] %= MOD;
      newDp[2] += dp[3];
      newDp[2] %= MOD;
      newDp[2] += dp[4];
      newDp[2] %= MOD;

      // o
      newDp[3] += dp[2];
      newDp[3] %= MOD;
      newDp[3] += dp[4];
      newDp[3] %= MOD;

      // u
      newDp[4] += dp[0];
      newDp[4] %= MOD;

      for (int j = 0; j < 5; j++) {
        dp[j] = newDp[j];
      }
    }

    int answer = 0;
    for (int i = 0; i < 5; i++) {
      answer += dp[i];
      answer %= MOD;
    }
    return answer;
  }
};

// use dynamic programming
// time : O(N)
// space : O(1)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int countVowelPermutation(int n) {
    int dp[5] = {0};
    for (int i = 0; i < 5; i++) {
      dp[i] = 1;
    }

    vector<vector<int>> nexts = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};

    for (int i = 1; i < n; i++) {
      // a e i o u
      int newDp[5] = {
          0,
      };
      for (int cur = 0; cur < 5; cur++) {
        for (int &next : nexts[cur]) {
          newDp[cur] += dp[next];
          newDp[cur] %= MOD;
        }
      }

      for (int cur = 0; cur < 5; cur++) {
        dp[cur] = newDp[cur];
      }
    }

    int answer = 0;
    for (int cur = 0; cur < 5; cur++) {
      answer += dp[cur];
      answer %= MOD;
    }
    return answer;
  }
};