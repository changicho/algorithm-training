#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int longestRepeatingSubstring(string s) {
    int size = s.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));

    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (s[i] != s[j]) continue;

        dp[i][j] = (i > 0 ? dp[i - 1][j - 1] : 0) + 1;
        answer = max(answer, dp[i][j]);
      }
    }

    return answer;
  }
};

// use KMP
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  int kmp(string &s) {
    int size = s.size();

    vector<int> pIs(size);
    int ret = 0;
    for (int i = 1, pI = 0; i < size; i++) {
      while (pI > 0 && s[pI] != s[i]) {
        pI = pIs[pI - 1];
      }

      if (s[pI] == s[i]) {
        pI++;
        pIs[i] = pI;
      }
      ret = max(ret, pI);
    }
    return ret;
  }

 public:
  int longestRepeatingSubstring(string s) {
    int size = s.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      string line = s.substr(i);
      int cur = kmp(line);
      answer = max(answer, cur);
    }
    return answer;
  }
};