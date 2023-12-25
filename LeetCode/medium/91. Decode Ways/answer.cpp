#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int numDecodings(string s) {
    int size = s.size();
    unordered_set<string> us;
    for (int i = 1; i <= 26; i++) {
      us.insert(to_string(i));
    }

    int answer = 0;

    vector<int> dp(size + 1, 0);
    if (s[0] != '0') {
      dp[0] = 1;
    }

    for (int i = 1; i < size; i++) {
      if (s[i] != '0') {
        dp[i] += dp[i - 1];
      }

      string key = {s[i - 1], s[i]};
      if (us.count(key) == 0) continue;

      dp[i] += (i - 2 >= 0) ? dp[i - 2] : 1;
    }

    return dp[size - 1];
  }
};

// use dynamic programming without set
// time : O(N)
// space : O(N)
class Solution {
 public:
  int numDecodings(string s) {
    int size = s.size();

    int answer = 0;

    vector<int> dp(size + 1, 0);
    if (s[0] != '0') {
      dp[0] = 1;
    }

    for (int i = 1; i < size; i++) {
      if (s[i] != '0') {
        dp[i] += dp[i - 1];
      }

      int key = (s[i - 1] - '0') * 10 + s[i] - '0';
      if (s[i - 1] == '0') continue;
      if (0 == key || key > 26) continue;

      dp[i] += (i - 2 >= 0) ? dp[i - 2] : 1;
    }

    return dp[size - 1];
  }
};