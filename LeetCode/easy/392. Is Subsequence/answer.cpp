#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use two pointer

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int lengthS = s.length(), lengthT = t.length();

    if (lengthS > lengthT) return false;
    int index = 0;

    for (int i = 0; i < lengthT; i++) {
      if (s[index] == t[i]) {
        index += 1;
      }

      if (index == lengthS) break;
    }

    return index == lengthS;
  }
};

// use binary search

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    unordered_map<char, vector<int>> um;
    int lengthS = s.length(), lengthT = t.length();

    for (int i = 0; i < lengthT; ++i) {
      um[t[i]].push_back(i);
    }

    int prev = -1;
    for (char c : s) {
      if (um.find(c) == um.end()) return false;

      vector<int> &arr = um[c];
      int index = upper_bound(arr.begin(), arr.end(), prev) - arr.begin();
      if (index == arr.size()) return false;

      prev = arr[index];
    }

    return true;
  }
};

// use dynamic programming (LCS)

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int lengthS = s.size();
    int lengthT = t.size();

    vector<vector<int>> dp(lengthS + 1, vector<int>(lengthT + 1, 0));

    for (int i = 1; i <= lengthS; ++i) {
      for (int j = 1; j <= lengthT; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp.back().back() == s.length();
  }
};