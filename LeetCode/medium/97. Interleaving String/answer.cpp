#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force + backtracking + dynamic programming

class Solution {
 public:
  bool visited[100][100] = {
      false,
  };
  bool dp[100][100] = {
      false,
  };
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) return false;

    return recursive(s1, s2, s3, 0, 0, 0);
  }

  bool recursive(string &s1, string &s2, string &s3, int idx1, int idx2, int idx3) {
    if (idx3 == s3.length()) return true;
    if (visited[idx1][idx2] == true) return dp[idx1][idx2];

    bool response = false;
    if (idx1 < s1.length() && s3[idx3] == s1[idx1]) {
      response |= recursive(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
    }
    if (idx2 < s2.length() && s3[idx3] == s2[idx2]) {
      response |= recursive(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
    }

    visited[idx1][idx2] = true;
    return dp[idx1][idx2] = response;
  }
};