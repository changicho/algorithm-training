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
  int calc(int cur, int diff) { return (cur + diff + 26) % 26; }

 public:
  long long shiftDistance(string s, string t, vector<int>& nextCost,
                          vector<int>& previousCost) {
    vector<vector<long long>> dp(26, vector<long long>(26, LLONG_MAX));
    for (int i = 0; i < 26; i++) {
      dp[i][i] = 0;
    }
    for (int i = 0; i < 26; i++) {
      for (int next = calc(i, +1); next != i; next = calc(next, +1)) {
        int nprev = calc(next, -1);

        dp[i][next] = min(dp[i][next], dp[i][nprev] + nextCost[nprev]);
      }
      for (int prev = calc(i, -1); prev != i; prev = calc(prev, -1)) {
        int pnext = calc(prev, +1);

        dp[i][prev] = min(dp[i][prev], dp[i][pnext] + previousCost[pnext]);
      }
    }

    int size = s.size();
    long long answer = 0;
    for (int i = 0; i < size; i++) {
      int from = s[i] - 'a';
      int to = t[i] - 'a';

      answer += dp[from][to];
    }
    return answer;
  }
};