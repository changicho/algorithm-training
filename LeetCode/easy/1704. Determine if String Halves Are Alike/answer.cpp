#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(L)
// space : O(L)
class Solution {
 private:
  bool isVowel(char &c) {
    switch (tolower(c)) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
    }
    return false;
  }

  int getVowelCount(string &s) {
    int count = 0;
    for (char &c : s) {
      if (isVowel(c)) count++;
    }
    return count;
  }

 public:
  bool halvesAreAlike(string s) {
    int length = s.size();
    string a = s.substr(0, length / 2), b = s.substr(length / 2);

    return getVowelCount(a) == getVowelCount(b);
  }
};