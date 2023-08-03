#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (bottom up)
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    int size1 = s1.length(), size2 = s2.length();
    // costs[len1][len2] : cost of s1.substr(0,len1) and s2.substr(0,len2)
    int costs[1001][1001] = {
        0,
    };

    for (int i = 1; i <= size1; i++) {
      costs[i][0] = costs[i - 1][0] + s1[i - 1];
    }
    for (int j = 1; j <= size2; j++) {
      costs[0][j] = costs[0][j - 1] + s2[j - 1];
    }

    for (int i = 1; i <= size1; i++) {
      for (int j = 1; j <= size2; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          costs[i][j] = costs[i - 1][j - 1];
        } else {
          int fromS1 = s1[i - 1] + costs[i - 1][j];
          int fromS2 = s2[j - 1] + costs[i][j - 1];
          costs[i][j] = min(fromS1, fromS2);
        }
      }
    }

    return costs[size1][size2];
  }
};

// use dynamic programming (top down)
// time : O(N * M)
// space : O(N * M)
class Solution {
 private:
  string s1, s2;
  int memo[1001][1001] = {
      0,
  };

  int recursive(int i, int j) {
    if (i == s1.size() || j == s2.size()) {
      return 0;
    }
    if (memo[i][j] != 0) {
      return memo[i][j];
    }

    int ret = 0;
    if (s1[i] == s2[j]) {
      ret = s1[i] + recursive(i + 1, j + 1);
    } else {
      ret = max(recursive(i + 1, j), recursive(i, j + 1));
    }
    return memo[i][j] = ret;
  }

 public:
  int minimumDeleteSum(string s1, string s2) {
    this->s1 = s1;
    this->s2 = s2;

    int sum = accumulate(s1.begin(), s1.end(), 0) +
              accumulate(s2.begin(), s2.end(), 0);

    return sum - (2 * (recursive(0, 0)));
  }
};