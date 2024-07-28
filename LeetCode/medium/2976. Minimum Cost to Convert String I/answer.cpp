#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use floyed warshall
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  long long minimumCost(string source, string target, vector<char>& original,
                        vector<char>& changed, vector<int>& cost) {
    // from, to
    vector<vector<long long>> dp(26, vector<long long>(26, LLONG_MAX));

    for (int i = 0; i < cost.size(); i++) {
      char from = original[i], to = changed[i];
      int c = cost[i];

      dp[from - 'a'][to - 'a'] = min(dp[from - 'a'][to - 'a'], (long long)c);
    }

    for (int i = 0; i < 26; i++) {
      dp[i][i] = 0;
    }

    for (int through = 0; through < 26; through++) {
      for (int from = 0; from < 26; from++) {
        for (int to = 0; to < 26; to++) {
          if (dp[from][through] == LLONG_MAX || dp[through][to] == LLONG_MAX) {
            continue;
          }
          dp[from][to] = min(dp[from][to], dp[from][through] + dp[through][to]);
        }
      }
    }

    int size = source.size();
    long long answer = 0;
    for (int i = 0; i < size; i++) {
      char from = source[i], to = target[i];
      if (from == to) continue;

      if (dp[from - 'a'][to - 'a'] == LLONG_MAX) return -1;
      answer += dp[from - 'a'][to - 'a'];
    }
    return answer;
  }
};