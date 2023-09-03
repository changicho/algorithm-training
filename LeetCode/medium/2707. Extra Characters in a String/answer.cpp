#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (top down)
// time : O(N^3 * M)
// space : O(N^2)
class Solution {
 private:
  const int MAX = 100001;
  vector<string> words;
  string s;

  int dp[51][51] = {
      0,
  };

  vector<int> find(string &s, string &target, int left, int right) {
    vector<int> ret;
    int pos = s.find(target, left);
    while (pos != -1 && pos + target.size() - 1 <= right) {
      ret.push_back(pos);
      pos = s.find(target, pos + 1);
    }
    return ret;
  }

  int recursive(int left, int right) {
    if (left > right) return 0;
    if (dp[left][right] != MAX) return dp[left][right];

    int ret = right - left + 1;

    for (string &w : words) {
      for (int idx : find(s, w, left, right)) {
        int leftCount = recursive(left, idx - 1);
        int rightCount = recursive(idx + w.size(), right);

        int cur = leftCount + rightCount;

        ret = min(ret, cur);
      }
    }

    return dp[left][right] = ret;
  }

 public:
  int minExtraChar(string s, vector<string> &dictionary) {
    this->s = s;
    this->words = dictionary;

    int size = s.size();
    for (int l = 0; l < size; l++) {
      for (int r = 0; r < size; r++) {
        dp[l][r] = MAX;
      }
    }

    recursive(0, size - 1);

    return dp[0][size - 1];
  }
};