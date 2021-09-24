#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force with memoization

class Solution {
 private:
  int recursive(int left, int right, string &s, vector<vector<int>> &dp) {
    if (left == right) return 1;
    if (left > right) return 0;
    if (dp[left][right] != 0) return dp[left][right];

    if (s[left] == s[right]) {
      return dp[left][right] = 2 + recursive(left + 1, right - 1, s, dp);
    }

    int rightShift = recursive(left + 1, right, s, dp);
    int leftShift = recursive(left, right - 1, s, dp);

    return dp[left][right] = max(rightShift, leftShift);
  }

 public:
  int longestPalindromeSubseq(string s) {
    int length = s.length();
    vector<vector<int>> dp(length, vector<int>(length, 0));

    return recursive(0, length - 1, s, dp);
  }
};

// use dynamic programming

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int length = s.length();
    // dp[length][index];
    vector<vector<int>> dp(length + 1, vector<int>(length, 0));

    for (int i = 0; i < length; ++i) {
      dp[1][i] = 1;
    }

    for (int size = 2; size <= length; ++size) {
      for (int start = 0; start < length - size + 1; ++start) {  // start index
        if (s[start] == s[size + start - 1]) {
          dp[size][start] = dp[size - 2][start + 1] + 2;
        } else {
          dp[size][start] = max(dp[size - 1][start], dp[size - 1][start + 1]);
        }
      }
    }

    return dp.back().front();
  }
};

// use space optimized dynamic programming

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int length = s.length();
    if (length <= 1) return length;

    vector<int> dp(length, 0), before(length, 0);

    for (int left = length - 1; left >= 0; --left) {
      dp[left] = 1;

      for (int right = left + 1; right < length; ++right) {
        if (s[left] == s[right]) {
          dp[right] = before[right - 1] + 2;
        } else {
          dp[right] = max(before[right], dp[right - 1]);
        }
      }
      swap(before, dp);
    }

    return before.back();
  }
};