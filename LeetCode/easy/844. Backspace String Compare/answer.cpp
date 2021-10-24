#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 private:
  string convert(string &s) {
    string ret;

    for (char c : s) {
      if (c == '#') {
        if (!ret.empty()) ret.pop_back();
        continue;
      }
      ret.push_back(c);
    }
    return ret;
  }

 public:
  bool backspaceCompare(string s, string t) {
    string first = convert(s), second = convert(t);

    return first == second;
  }
};

// use two pointer

class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int first = s.length() - 1, second = t.length() - 1;
    int firstDeleted = 0, secondDeleted = 0;

    while (first >= 0 || second >= 0) {
      while (first >= 0 && (s[first] == '#' || firstDeleted > 0)) {
        firstDeleted += s[first] == '#' ? 1 : -1;
        first--;
      }

      while (second >= 0 && (t[second] == '#' || secondDeleted > 0)) {
        secondDeleted += t[second] == '#' ? 1 : -1;
        second--;
      }

      if (first < 0 || second < 0) break;
      if (s[first] != t[second]) return false;
      first--;
      second--;
    }

    return first == second;
  }
};