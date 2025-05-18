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

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  bool check(string& s1, string& s2) {
    if (s1.size() != s2.size()) return false;

    int diff = 0;
    for (int i = 0, size = s1.size(); i < size; i++) {
      if (s1[i] != s2[i]) diff++;
      if (diff > 1) return false;
    }
    return diff == 1;
  }

 public:
  vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                              vector<int>& groups) {
    int size = groups.size();
    vector<int> dp(size, 1);
    vector<int> prev(size, -1);

    int index = 0;
    for (int i = 1; i < size; i++) {
      for (int before = 0; before < i; before++) {
        if (!check(words[i], words[before])) continue;
        if (groups[i] == groups[before]) continue;
        if (dp[before] + 1 <= dp[i]) continue;

        dp[i] = dp[before] + 1;
        prev[i] = before;
      }

      if (dp[i] > dp[index]) {
        index = i;
      }
    }

    vector<string> answer;
    while (index != -1) {
      answer.emplace_back(words[index]);
      index = prev[index];
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};