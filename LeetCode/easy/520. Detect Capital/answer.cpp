#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool isAllUpper(string &word) {
    for (char &c : word) {
      if (islower(c)) return false;
    }
    return true;
  }

  bool isAllLower(string &word) {
    for (char &c : word) {
      if (isupper(c)) return false;
    }
    return true;
  }

  bool isCamelCase(string &word) {
    int length = word.size();
    if (islower(word.front())) return false;

    for (int i = 1; i < length; i++) {
      if (isupper(word[i])) return false;
    }
    return true;
  }

 public:
  bool detectCapitalUse(string word) {
    if (isAllUpper(word)) return true;
    if (isAllLower(word)) return true;
    if (isCamelCase(word)) return true;

    return false;
  }
};