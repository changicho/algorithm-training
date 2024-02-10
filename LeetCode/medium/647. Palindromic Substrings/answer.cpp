#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int countSubstrings(string s) {
    int size = s.size();
    bool dp[1001][1001] = {
        false,
    };

    int answer = 0;
    for (int i = 0; i < size; i++) {
      dp[i][i] = true;
      answer++;

      if (i + 1 < size && s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        answer++;
      }
    }
    for (int len = 2; len <= size; len++) {
      for (int from = 0; from < size - len + 1; from++) {
        int to = from + len - 1;
        if (dp[from + 1][to - 1] == false) continue;
        if (s[from] == s[to]) {
          dp[from][to] = true;
          answer++;
        }
      }
    }
    return answer;
  }
};