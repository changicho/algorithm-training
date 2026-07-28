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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int largestInteger(int n, int s) {
    int answer = 0;

    for (int i = 0; i < n; ++i) {
      int cur = min(s, 9);
      answer = answer * 10 + cur;
      s -= cur;
    }
    if (s > 0) return -1;
    return answer;
  }
};

// DFS
// time : O(10^N)
// space : O(N)
class Solution {
 private:
  int answer = -1;

  void recursive(int n, int num, int s) {
    if (n == 0) {
      if (s == 0) {
        answer = max(answer, num);
      }
      return;
    }

    for (int i = 0; i <= 9; i++) {
      if (s - i < 0) break;
      int next = num * 10 + i;

      recursive(n - 1, next, s - i);
    }
  }

 public:
  int largestInteger(int n, int s) {
    recursive(n, 0, s);

    return answer;
  }
};

// dynamic programming
// time : O(N * S)
// space : O(N * S)
class Solution {
 public:
  int largestInteger(int n, int s) {
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
    dp[0][s] = 0;

    for (int i = 1; i <= n; i++) {
      for (int before = s; before >= 0; before--) {
        if (dp[i - 1][before] == -1) continue;

        for (int j = 0; j <= 9; j++) {
          if (before - j < 0) break;
          dp[i][before - j] =
              max(dp[i][before - j], dp[i - 1][before] * 10 + j);
        }
      }
    }

    return dp[n][0];
  }
};

// dynamic programming (space optimized)
// time : O(N * S)
// space : O(S)
class Solution {
 public:
  int largestInteger(int n, int s) {
    vector<int> dp(s + 1, -1);
    dp[s] = 0;

    for (int i = 1; i <= n; i++) {
      vector<int> newDp(s + 1, -1);

      for (int before = s; before >= 0; before--) {
        if (dp[before] == -1) continue;

        for (int j = 0; j <= 9; j++) {
          if (before - j < 0) break;
          newDp[before - j] = max(newDp[before - j], dp[before] * 10 + j);
        }
      }

      swap(newDp, dp);
    }

    return dp[0];
  }
};
