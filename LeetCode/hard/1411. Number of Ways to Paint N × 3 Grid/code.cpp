#include <algorithm>
#include <climits>
#include <cmath>
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

// use dynamic programming
// time : O(N)
// space : O(1)
class Solution {
 private:
  vector<int> convert(int state) {
    int c = state % 3;
    int b = ((state - c) % 9) / 3;
    int a = state / 9;

    return {a, b, c};
  }

  bool isRowFine(int cur) {
    vector<int> curS = convert(cur);
    for (int i = 0; i < 2; i++) {
      if (curS[i] == curS[i + 1]) return false;
    }
    return true;
  }

  bool isFine(int before, int cur) {
    vector<int> beforeS = convert(before);
    vector<int> curS = convert(cur);

    if (!isRowFine(before)) return false;
    if (!isRowFine(cur)) return false;
    for (int i = 0; i < 3; i++) {
      if (beforeS[i] == curS[i]) return false;
    }
    return true;
  }

 public:
  int numOfWays(int n) {
    const int MOD = 1e9 + 7;
    vector<long> dp(27, 0);

    vector<int> validStates;
    vector<vector<int>> nexts(27);

    for (int s = 0; s < 27; s++) {
      if (isRowFine(s)) {
        validStates.push_back(s);
        dp[s] = 1;
      }
    }

    for (int& before : validStates) {
      for (int& next : validStates) {
        if (isFine(before, next)) {
          nexts[before].push_back(next);
        }
      }
    }

    for (int i = 1; i < n; i++) {
      vector<long> newDp(27, 0);

      for (int& before : validStates) {
        for (int& cur : nexts[before]) {
          newDp[cur] += dp[before];
          newDp[cur] %= MOD;
        }
      }

      swap(dp, newDp);
    }

    long answer = 0;
    for (int& c : validStates) {
      answer += dp[c];
      answer %= MOD;
    }

    return answer;
  }
};

// use dynamic programming
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numOfWays(int n) {
    const int MOD = 1e9 + 7;

    long aba = 6;
    long abc = 6;

    for (int i = 1; i < n; i++) {
      long abaNew = (2 * aba + 2 * abc) % MOD;
      long abcNew = (2 * aba + 3 * abc) % MOD;

      aba = abaNew;
      abc = abcNew;
    }

    long answer = (aba + abc) % MOD;
    return answer;
  }
};