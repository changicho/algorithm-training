#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int dp[100][100] = {
        0,
    };

    for (int i = 0; i < n; i++) {
      dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
      dp[i][0] = 1;
    }

    for (int y = 1; y < m; y++) {
      for (int x = 1; x < n; x++) {
        dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};

// use dynamic with minimum dp

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int dp[2][100] = {
        0,
    };

    for (int i = 0; i < n; i++) {
      dp[0][i] = 1;
    }
    dp[0][0] = dp[1][0] = 1;

    for (int y = 1; y < m; y++) {
      for (int x = 1; x < n; x++) {
        dp[y % 2][x] = dp[(y - 1) % 2][x] + dp[y % 2][x - 1];
      }
    }

    return dp[(m - 1) % 2][n - 1];
  }
};

// use math (permutation)

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1 || n == 1) {
      return 1;
    }

    m--;
    n--;
    if (m < n) {
      swap(m, n);
    }

    long ret = 1;
    for (int denominator = m + 1, molecule = 1; denominator <= m + n; denominator++, molecule++) {
      ret *= denominator;
      ret /= molecule;
    }

    return (int)ret;
  }
};