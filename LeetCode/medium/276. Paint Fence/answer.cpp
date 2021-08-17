#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming top-down

class Solution {
 private:
  unordered_map<int, int> dp;

  int recursive(int i, int k) {
    if (i == 1) return k;
    if (i == 2) return k * k;

    if (dp.find(i) != dp.end()) {
      return dp[i];
    }

    return dp[i] = (k - 1) * (recursive(i - 1, k) + recursive(i - 2, k));
  }

 public:
  int numWays(int n, int k) {
    return recursive(n, k);
  }
};

// use dynamic programming bottom-up

class Solution {
 public:
  int numWays(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k * k;

    vector<int> dp(n + 1);
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++) {
      dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
  }
};

// use dynamic programming bottom-up with constant space

class Solution {
 public:
  int numWays(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k * k;

    int dp[3] = {
        k,
        k * k,
    };

    for (int i = 3; i <= n; i++) {
      dp[2] = (k - 1) * (dp[1] + dp[0]);
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    return dp[2];
  }
};