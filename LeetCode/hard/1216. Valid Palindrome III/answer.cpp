#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (top down)
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  // minimum k count of [leftI][rightI]
  vector<vector<int>> dp;

  int recursive(string &s, int leftI, int rightI) {
    if (leftI > rightI) {
      return 0;
    }

    if (dp[leftI][rightI] != -1) {
      return dp[leftI][rightI];
    }

    if (s[leftI] == s[rightI]) {
      return dp[leftI][rightI] = recursive(s, leftI + 1, rightI - 1);
    }
    return dp[leftI][rightI] = 1 + min(recursive(s, leftI + 1, rightI),
                                       recursive(s, leftI, rightI - 1));
  }

 public:
  bool isValidPalindrome(string s, int k) {
    int length = s.length();
    dp.resize(length + 1, vector<int>(length + 1, -1));

    return recursive(s, 0, length - 1) <= k;
  }
};

// use dynamic programming (bottom-up)
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  bool isValidPalindrome(string s, int k) {
    int length = s.length();
    vector<vector<int>> dp(length, vector<int>(length, 0));

    for (int leftI = length - 2; leftI >= 0; leftI--)
      for (int rightI = leftI + 1; rightI < length; rightI++) {
        if (s[leftI] == s[rightI]) {
          dp[leftI][rightI] = dp[leftI + 1][rightI - 1];
        } else {
          dp[leftI][rightI] =
              1 + min(dp[leftI + 1][rightI], dp[leftI][rightI - 1]);
        }
      }

    return dp[0][s.length() - 1] <= k;
  }
};