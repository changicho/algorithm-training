#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int numDecodings(string s) {
    unordered_set<string> S;
    for (int i = 1; i <= 26; i++) {
      S.insert(to_string(i));
    }

    int answer = 0;
    if (s.front() == '0') return answer;
    int length = s.length();
    int dp[101] = {1};
    reverse(s.begin(), s.end());

    if (s.front() != '0') {
      dp[1] = 1;
    }

    for (int i = 2; i <= length; i++) {
      if (s[i - 2] != '0') {
        dp[i] += dp[i - 1];
      }

      string key = {s[i - 1], s[i - 2]};
      if (S.find(key) != S.end()) {
        if (i >= 3 && s[i - 3] == '0') {
          continue;
        }
        dp[i] += dp[i - 2];
      }
    }

    return dp[length];
  }
};

// use dynamic programming without set

class Solution {
 public:
  int numDecodings(string s) {
    int answer = 0;
    if (s.front() == '0') return answer;

    int length = s.length();
    int dp[101] = {1};
    reverse(s.begin(), s.end());

    if (s.front() != '0') {
      dp[1] = 1;
      dp[2] = 1;
    }

    if (s[1] != '0') {
      int key = (s[1] - '0') * 10 + (s[0] - '0');
      if (0 < key && key <= 26) dp[2] += 1;
    }

    for (int i = 3; i <= length; i++) {
      if (s[i - 2] != '0') {
        dp[i] += dp[i - 1];
      }

      if (s[i - 1] == '0') continue;
      int key = (s[i - 1] - '0') * 10 + (s[i - 2] - '0');

      if (0 < key && key <= 26 && s[i - 3] != '0') {
        dp[i] += dp[i - 2];
      }
    }

    return dp[length];
  }
};