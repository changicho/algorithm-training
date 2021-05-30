#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use convert

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    string first = convert(s);
    string second = convert(t);
    return first == second;
  }

  string convert(string& s) {
    int count = 1;
    unordered_map<char, char> m;

    m[s[0]] = '0';
    string ret = {m[s[0]]};

    for (int i = 1; i < s.length(); i++) {
      if (m[s[i]] != 0) {
        ret += m[s[i]];
        continue;
      }

      m[s[i]] = count + '0';
      count += 1;
      ret += m[s[i]];
    }

    return ret;
  }
};

// use int array

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    int m1[256] = {0}, m2[256] = {0};
    int length = s.length();

    for (int i = 0; i < length; i++) {
      if (m1[s[i]] != m2[t[i]]) {
        return false;
      }

      m1[s[i]] = i + 1;
      m2[t[i]] = i + 1;
    }
    return true;
  }
};