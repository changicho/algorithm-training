#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use count

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> m;

    for (char c : s) {
      m[c] += 1;
    }

    for (char c : t) {
      m[c] -= 1;
      if (m[c] < 0) return false;
    }

    return true;
  }
};

// use sort

class Solution {
 public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
  }
};