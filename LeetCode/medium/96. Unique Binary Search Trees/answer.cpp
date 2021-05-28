#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (top-down)

class Solution {
 public:
  int dp[20][20] = {0};
  int numTrees(int n) {
    return recursive(1, n);
  }

  int recursive(int from, int to) {
    if (from > to) return 1;
    if (from == to) return 1;
    if (dp[from][to] != 0) return dp[from][to];
    int count = 0;

    for (int root = from; root <= to; root++) {
      int leftCount = recursive(from, root - 1);
      int rightCount = recursive(root + 1, to);

      count += leftCount * rightCount;
    }

    return dp[from][to] = count;
  }
};

// use dynamic programming smaller (top-down)

class Solution {
 public:
  int dp[20] = {0};
  int numTrees(int n) {
    return recursive(1, n);
  }

  int recursive(int from, int to) {
    if (from > to) return 1;
    if (from == to) return 1;
    if (dp[to - from] != 0) return dp[to - from];
    int count = 0;

    for (int root = from; root <= to; root++) {
      int leftCount = recursive(from, root - 1);
      int rightCount = recursive(root + 1, to);

      count += leftCount * rightCount;
    }

    return dp[to - from] = count;
  }
};

// use dynamic programming (bottom-up)

class Solution {
 public:
  int numTrees(int n) {
    int dp[20] = {0};
    dp[0] = dp[1] = 1;

    for (int number = 2; number <= n; number++) {
      for (int center = 1; center <= number; center++) {
        dp[number] += dp[center - 1] * dp[number - center];
      }
    }

    return dp[n];
  }
};