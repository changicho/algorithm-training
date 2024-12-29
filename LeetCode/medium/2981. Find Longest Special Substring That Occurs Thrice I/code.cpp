#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use one pass
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int maximumLength(string s) {
    int answer = -1;

    int dp[26][51] = {
        0,
    };

    char before = ' ';
    int count = 0;
    for (char &c : s) {
      if (before != c) {
        count = 0;
      }

      count++;
      before = c;

      for (int len = 1; len <= count; len++) {
        dp[c - 'a'][len]++;
      }
    }

    for (int c = 0; c < 26; c++) {
      for (int len = 1; len <= 50; len++) {
        if (dp[c][len] >= 3) {
          answer = max(answer, len);
        }
      }
    }
    return answer;
  }
};