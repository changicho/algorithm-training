#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer
// time : O(N * M)
// space : O(1)
class Solution {
 public:
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;
    int length = s.length();

    for (int start = 0; start < length; start++) {
      if (s[start] != goal[0]) continue;

      bool isSame = true;
      for (int i = 0; i < length; i++) {
        if (s[(start + i) % length] != goal[i]) {
          isSame = false;
          break;
        }
      }

      if (isSame) return true;
    }
    return false;
  }
};

// use KMP
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  bool rotateString(string s, string goal) {
    // edge case
    if (s.length() != goal.length()) return false;

    string line = s + s;

    vector<int> patterns(goal.length(), 0);
    for (int i = 1, pIdx = 0; i < goal.length(); i++) {
      // restore parent's index
      while (pIdx > 0 && goal[i] != goal[pIdx]) {
        pIdx = patterns[pIdx - 1];
      }

      if (goal[i] == goal[pIdx]) {
        pIdx++;
        patterns[i] = pIdx;
      }
    }

    for (int i = 0, pIdx = 0; i < line.length(); i++) {
      // restore parent's index
      while (pIdx > 0 && line[i] != goal[pIdx]) {
        pIdx = patterns[pIdx - 1];
      }

      if (line[i] != goal[pIdx]) continue;
      if (pIdx < goal.length() - 1) {
        pIdx++;
        continue;
      }

      // reach to goal's end
      return true;
    }

    return false;
  }
};

// use STL find
// time : O(N * M)
// space : O(N)
class Solution {
 public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;

    return (s + s).find(goal) != string::npos;
  }
};