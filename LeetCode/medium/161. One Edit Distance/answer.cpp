#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use index diff

class Solution {
  int countDiff(string &s, string &t) {
    int length = s.length();
    int count = 0;

    for (int i = 0; i < length; i++) {
      if (s[i] != t[i]) count += 1;
    }
    return count;
  }

 public:
  bool isOneEditDistance(string s, string t) {
    if (s == t) return false;

    if (s.length() < t.length()) swap(s, t);
    if (s.length() == t.length() && countDiff(s, t) == 1) return true;

    int length = t.length();
    int left = 0;
    int right = 0;

    for (int i = 0; i < length; i++) {
      if (s[i] != t[i]) break;
      left++;
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    for (int i = 0; i < length; i++) {
      if (s[i] != t[i]) break;
      right++;
    }

    right = s.length() - 1 - right;

    if (left == right) return true;
    if (right == 0 && left == s.length() - 1) return true;
    return false;
  }
};

// use index diff compact

class Solution {
  int countDiff(string &s, string &t) {
    int length = s.length();
    int count = 0;

    for (int i = 0; i < length; i++) {
      if (s[i] != t[i]) count += 1;
    }
    return count;
  }

 public:
  bool isOneEditDistance(string s, string t) {
    if (s.length() == t.length()) {
      return countDiff(s, t) == 1;
    }
    if (s.length() < t.length()) swap(s, t);

    int length = s.length();
    int sIdx = 0, tIdx = 0;

    while (sIdx < length) {
      if (s[sIdx] != t[tIdx]) {
        if (sIdx != tIdx) return false;
        sIdx += 1;
      } else {
        sIdx += 1;
        tIdx += 1;
      }
    }

    return true;
  }
};