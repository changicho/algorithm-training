#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * L)
// space : O(1)
class Solution {
 private:
  bool isPrefix(string &word, string &pref) {
    if (word.length() < pref.length()) return false;

    // if (word.substr(0, pref.length()) != pref) return false;
    for (int i = 0; i < pref.length(); i++) {
      if (word[i] != pref[i]) return false;
    }
    return true;
  }

 public:
  int prefixCount(vector<string> &words, string pref) {
    int count = 0;

    for (string &word : words) {
      if (isPrefix(word, pref)) count++;
    }

    return count;
  }
};