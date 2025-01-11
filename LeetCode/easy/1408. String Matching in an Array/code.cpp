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

// use brute force
// time : O(N^2 * L^2)
// space : O(N * L)
class Solution {
 private:
  bool isSubstring(string &a, string &b) { return a.find(b) != -1; }

 public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> answer;

    for (string &a : words) {
      bool flag = false;
      for (string &b : words) {
        if (a == b) continue;

        if (isSubstring(b, a)) {
          flag = true;
        }
      }

      if (flag) {
        answer.push_back(a);
      }
    }
    return answer;
  }
};

// use KMP
// time : O(N^2 * L)
// space : O(N * L)
class Solution {
 private:
  vector<int> getLPS(string &pattern) {
    int size = pattern.size();

    vector<int> lps(size, 0);

    for (int i = 1, pI = 0; i < size; i++) {
      while (pI > 0 && pattern[i] != pattern[pI]) {
        pI = lps[pI - 1];
      }
      if (pattern[i] == pattern[pI]) {
        pI++;
        lps[i] = pI;
      }
    }
    return lps;
  }

  bool isSubstringOf(string &sub, string &main, vector<int> &lps) {
    int mainI = 0;
    int subI = 0;

    while (mainI < main.size()) {
      if (main[mainI] == sub[subI]) {
        subI++;
        mainI++;

        if (subI == sub.size()) return true;
      } else {
        if (subI > 0) {
          subI = lps[subI - 1];
        } else {
          mainI++;
        }
      }
    }
    return false;
  }

 public:
  vector<string> stringMatching(vector<string> &words) {
    int size = words.size();

    vector<string> answer;

    for (int i = 0; i < size; i++) {
      vector<int> lps = getLPS(words[i]);

      for (int j = 0; j < size; j++) {
        if (i == j) continue;

        if (isSubstringOf(words[i], words[j], lps)) {
          answer.push_back(words[i]);
          break;
        }
      }
    }

    return answer;
  }
};