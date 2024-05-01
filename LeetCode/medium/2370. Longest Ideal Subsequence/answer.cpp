#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(1)
class Solution {
 public:
  int longestIdealString(string s, int k) {
    int size = s.size();
    int dp[26] = {
        0,
    };

    for (int i = 0; i < size; i++) {
      int cur = s[i] - 'a';

      int len = 0;
      for (int before = 0; before < 26; before++) {
        if (abs(before - cur) > k) continue;

        len = max(len, dp[before] + 1);
      }

      dp[cur] = max(dp[cur], len);
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
      answer = max(answer, dp[i]);
    }

    return answer;
  }
};