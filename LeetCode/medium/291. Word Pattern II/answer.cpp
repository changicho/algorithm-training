#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use backtracking
// time : O(P * N^3)
// space : O(P + N)
class Solution {
 private:
  unordered_map<char, string> pDict;
  unordered_map<string, char> sDict;

  bool recursive(string &pattern, int pI, string &s, int sI) {
    int pSize = pattern.size();
    int sSize = s.size();

    if (pI == pSize || sI == sSize) {
      return pI == pSize && sI == sSize;
    }

    for (int i = sI; i < sSize; i++) {
      string key = s.substr(sI, i - sI + 1);

      if (pDict.count(pattern[pI]) && pDict[pattern[pI]] != key) continue;
      if (sDict.count(key) && sDict[key] != pattern[pI]) continue;

      bool inserted = false;
      if (!pDict.count(pattern[pI]) && !sDict.count(key)) {
        pDict[pattern[pI]] = key;
        sDict[key] = pattern[pI];
        inserted = true;
      }

      if (recursive(pattern, pI + 1, s, i + 1)) return true;

      if (inserted) {
        pDict.erase(pattern[pI]);
        sDict.erase(key);
      }
    }

    return false;
  }

 public:
  bool wordPatternMatch(string pattern, string s) {
    return recursive(pattern, 0, s, 0);
  }
};