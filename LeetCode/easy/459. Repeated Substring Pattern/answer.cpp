#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  bool isRepeated(string &s, string &pattern) {
    if (s.size() % pattern.size() != 0) return false;

    int index = 0;
    while (index < s.size() && s.find(pattern, index) == index) {
      index += pattern.size();
    }

    if (index == s.size()) return true;
    return false;
  }

 public:
  bool repeatedSubstringPattern(string s) {
    string pattern = "";

    for (char &c : s) {
      pattern += c;
      if (pattern.size() > s.size() / 2) return false;

      if (isRepeated(s, pattern)) return true;
    }
    return false;
  }
};

// use pattern check
// time : O(N * sqrt(N))
// space : O(N)
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int size = s.length();
    for (int length = 1; length <= size / 2; length++) {
      if (size % length == 0) {
        string pattern = "";
        for (int j = 0; j < size / length; j++) {
          pattern += s.substr(0, length);
        }
        if (s == pattern) {
          return true;
        }
      }
    }
    return false;
  }
};

// use string concatenation
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    string t = s + s;
    if (t.substr(1, t.size() - 2).find(s) != -1) return true;
    return false;
  }
};