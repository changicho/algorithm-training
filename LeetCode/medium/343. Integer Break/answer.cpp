#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    for (int cur = 2; cur <= n; ++cur) {
      dp[cur] = cur;
      for (int part = 1; part <= cur / 2; ++part) {
        int left = dp[cur - part];
        int right = dp[part];

        dp[cur] = max(dp[cur], left * right);
      }
    }

    int answer = 0;
    for (int part = 1; part < n; part++) {
      answer = max(answer, dp[part] * dp[n - part]);
    }
    return answer;
  }
};

// use dynamic programming

class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 2) return 1;

    vector<int> dp(n + 1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for (int cur = 3; cur <= n; cur++) {
      for (int part = 1; part < cur; part++) {
        dp[cur] = max(dp[cur], max(part * (cur - part), part * dp[cur - part]));
      }
    }
    return dp[n];
  }
};

// use math

class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 3) {
      return n - 1;
    }

    if (n % 3 == 0) {
      return (int)pow(3, n / 3);
    } else if (n % 3 == 1) {
      return 2 * 2 * (int)pow(3, (n - 4) / 3);
    }

    return 2 * (int)pow(3, n / 3);
  }
};