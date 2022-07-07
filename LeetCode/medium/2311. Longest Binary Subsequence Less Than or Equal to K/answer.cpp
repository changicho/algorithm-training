#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int longestSubsequence(string s, int k) {
    int length = s.length();

    int answer = 0, cost = 1;
    for (int i = length - 1; i >= 0; i--) {
      if (s[i] == '0' || cost <= k) {
        if (s[i] == '1') k -= cost;

        answer++;
      }

      if (cost <= k) cost *= 2;
    }

    return answer;
  }
};

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int longestSubsequence(string s, int k) {
    // dp[i] : the minimum value of subsequence with length i
    int dp[1010] = {};
    int length = 0;

    for (char& c : s) {
      int curCost = dp[length] * 2 + c - '0';

      if (curCost <= k) {
        length++;
        dp[length] = curCost;
      }

      for (int i = length; i > 0; --i) {
        dp[i] = min(dp[i], dp[i - 1] * 2 + c - '0');
      }
    }
    return length;
  }
};