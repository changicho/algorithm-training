#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    bool dp[1001][1001] = {
        false,
    };

    int answer_from = 0, answer_to = 0;

    dp[0][0] = true;
    for (int i = 1; i < s.length(); i++) {
      dp[i][i] = true;
      if (s[i - 1] == s[i]) {
        dp[i - 1][i] = true;

        answer_from = i - 1;
        answer_to = i;
      }
    }

    for (int length = 3; length <= s.length(); length++) {
      for (int from = 0; from <= s.length() - length; from++) {
        int to = from + length - 1;

        if (dp[from + 1][to - 1] && s[from] == s[to]) {
          dp[from][to] = true;

          if (answer_to - answer_from + 1 < length) {
            answer_from = from;
            answer_to = to;
          }
        }
      }
    }

    return s.substr(answer_from, answer_to - answer_from + 1);
  }
};

// Expand Around Center

class Solution {
 public:
  string longestPalindrome(string s) {
    int N = s.length();
    int answer_from = 0, answer_to = 0;

    for (int index = 0; index < N; index++) {
      int length = 0;
      int from = index, to = index;
      while (from >= 0 && to < N && s[from] == s[to]) {
        from--;
        to++;
      }
      length = max(to - from - 1, length);

      from = index, to = index + 1;
      while (from >= 0 && to < N && s[from] == s[to]) {
        from--;
        to++;
      }
      length = max(to - from - 1, length);

      if (length > answer_to - answer_from + 1) {
        answer_from = index - (length - 1) / 2;
        answer_to = index + length / 2;
      }
    }

    return s.substr(answer_from, answer_to - answer_from + 1);
  }
};
