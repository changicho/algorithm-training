#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  pair<string, string> convert(string &s) {
    int size = s.size();
    string evens = "", odds = "";

    for (int i = 0; i < size; i++) {
      if (i % 2 == 0) {
        evens += s[i];
      } else {
        odds += s[i];
      }
    }

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());

    return {evens, odds};
  }

 public:
  bool checkStrings(string s1, string s2) { return convert(s1) == convert(s2); }
};

// use counting
// time : O(N)
// space : O(1)
class Solution {
 private:
  pair<vector<int>, vector<int>> convert(string &s) {
    int size = s.size();
    vector<int> evens(26), odds(26);

    for (int i = 0; i < size; i++) {
      char &c = s[i];
      if (i % 2 == 0) {
        evens[c - 'a']++;
      } else {
        odds[c - 'a']++;
      }
    }

    return {evens, odds};
  }

 public:
  bool checkStrings(string s1, string s2) { return convert(s1) == convert(s2); }
};