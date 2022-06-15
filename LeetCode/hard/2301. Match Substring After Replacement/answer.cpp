#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use change table (array)
// time : O(N * M + K)
// space : O(1)
class Solution {
 public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    bool canChange[256][256] = {
        false,
    };

    for (vector<char>& mapping : mappings) {
      canChange[mapping.back()][mapping.front()] = true;
    }

    int length = s.length();
    for (int i = 0; i <= length - sub.length(); i++) {
      bool flag = true;
      for (int j = 0; j < sub.length(); j++) {
        if (s[i + j] == sub[j] || canChange[s[i + j]][sub[j]]) {
          continue;
        }
        flag = false;
        break;
      }

      if (flag) return true;
    }

    return false;
  }
};

// use change table (hash set)
// time : O(N * M + K)
// space : O(1)
class Solution {
 public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    unordered_map<char, unordered_set<char>> table;
    for (vector<char>& mapping : mappings) {
      table[mapping.back()].insert(mapping.front());
    }

    int length = s.length();
    for (int i = 0; i <= length - sub.length(); i++) {
      bool flag = true;
      for (int j = 0; j < sub.length(); j++) {
        if (s[i + j] == sub[j] || table[s[i + j]].count(sub[j])) {
          continue;
        }
        flag = false;
        break;
      }

      if (flag) return true;
    }

    return false;
  }
};

// use kmp (fail)

class Solution {
 private:
  vector<int> getKMPArr(string& s, bool canChange[256][256]) {
    int length = s.length();
    vector<int> pIdxArr(length);

    // i : index
    // pIdx : pattern index
    pIdxArr[0] = 0;
    for (int i = 1, pIdx = 0; i < length; i++) {
      while (pIdx > 0 && s[i] != s[pIdx] && !canChange[s[i]][s[pIdx]]) {
        pIdx = pIdxArr[pIdx - 1];
      }

      if (s[i] == s[pIdx] || canChange[s[i]][s[pIdx]]) {
        pIdx++;
        pIdxArr[i] = pIdx;
      }
    }
    return pIdxArr;
  }

 public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    bool canChange[256][256] = {
        false,
    };

    for (vector<char>& mapping : mappings) {
      canChange[mapping.back()][mapping.front()] = true;
    }

    vector<int> pIdxArr = getKMPArr(sub, canChange);

    for (int i = 0, pIdx = 0; i < s.length(); i++) {
      while (pIdx > 0 && s[i] != sub[pIdx] && !canChange[s[i]][sub[pIdx]]) {
        pIdx = pIdxArr[pIdx - 1];
      }

      if (s[i] == sub[pIdx] || canChange[s[i]][sub[pIdx]]) {
        pIdx++;
      }

      if (pIdx == sub.length()) return true;
    }
    return false;
  }
};