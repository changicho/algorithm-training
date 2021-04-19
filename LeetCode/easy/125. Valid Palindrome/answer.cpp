#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use STL & two pointer

class Solution {
 public:
  bool isPalindrome(string s) {
    int length = s.length();
    int start = 0;
    int end = length - 1;

    while (start < end) {
      while (start < end && !isalnum(s[start])) start++;
      while (end > 0 && !isalnum(s[end])) end--;

      if (start > end) break;

      if (tolower(s[start]) != tolower(s[end])) return false;
      start++;
      end--;
    }

    return true;
  }
};

// use trim

class Solution {
 public:
  bool isPalindrome(string s) {
    s = trim(s);

    int length = s.length();
    int start = 0;
    int end = length - 1;

    while (start < end) {
      if (s[start] != s[end]) return false;
      start++;
      end--;
    }

    return true;
  }

  string trim(string s) {
    string ret = "";

    for (char c : s) {
      if (isalnum(c)) ret += tolower(c);
    }
    return ret;
  }
};