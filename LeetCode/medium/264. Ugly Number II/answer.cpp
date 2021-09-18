#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use greedy algorithm

class Solution {
 public:
  int nthUglyNumber(int n) {
    set<long long> s;

    s.insert(1);
    int count = 0;
    int answer = 0;

    while (!s.empty()) {
      long long cur = *s.begin();
      s.erase(cur);

      answer = cur;
      count += 1;
      if (count == n) break;

      s.insert(cur * 2);
      s.insert(cur * 3);
      s.insert(cur * 5);
    }

    return answer;
  }
};

// use dynamic programming

class Solution {
 public:
  int nthUglyNumber(int n) {
    int twoIdx = 0, threeIdx = 0, fiveIdx = 0;  // pointers for 2, 3, 5
    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
      dp[i] = min(dp[twoIdx] * 2, min(dp[threeIdx] * 3, dp[fiveIdx] * 5));

      if (dp[i] == dp[twoIdx] * 2) twoIdx++;
      if (dp[i] == dp[threeIdx] * 3) threeIdx++;
      if (dp[i] == dp[fiveIdx] * 5) fiveIdx++;
    }

    return dp.back();
  }
};
