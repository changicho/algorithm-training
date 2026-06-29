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
// time : O(NM)
// space : O(M)
class Solution {
 public:
  int zigZagArrays(int n, int l, int r) {
    const int MOD = 1e9 + 7;

    int beforeDp[2002][2] = {
        0,
    };
    int dp[2002][2] = {
        0,
    };

    for (int a = l; a <= r; a++) {
      beforeDp[a][0] = 1;
      beforeDp[a][1] = 1;
    }

    for (int i = 1; i < n; i++) {
      for (int a = l; a <= r; a++) {
        // b < a case

        dp[a][1] += beforeDp[a - 1][0];
        dp[a][1] %= MOD;

        beforeDp[a][0] += beforeDp[a - 1][0];
        beforeDp[a][0] %= MOD;
      }
      for (int a = r; a >= l; a--) {
        // b > a case

        dp[a][0] += beforeDp[a + 1][1];
        dp[a][0] %= MOD;

        beforeDp[a][1] += beforeDp[a + 1][1];
        beforeDp[a][1] %= MOD;
      }

      swap(dp, beforeDp);
      memset(dp, 0, sizeof(dp));
    }

    int answer = 0;
    for (int i = l; i <= r; i++) {
      answer += beforeDp[i][0];
      answer %= MOD;
      answer += beforeDp[i][1];
      answer %= MOD;
    }
    return answer;
  }
};