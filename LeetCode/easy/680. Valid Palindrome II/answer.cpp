#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use skip one char

class Solution {
 private:
  bool isValid(string &s, int left, int right) {
    while (left < right) {
      if (s[left] == s[right]) {
        left++;
        right--;
      } else {
        return false;
      }
    }
    return true;
  }

 public:
  bool validPalindrome(string s) {
    int length = s.length();
    int left = 0, right = length - 1;

    while (left < right) {
      if (s[left] == s[right]) {
        left++;
        right--;
        continue;
      }

      // skip one char from currnet
      return isValid(s, left + 1, right) || isValid(s, left, right - 1);
    }
    return true;
  }
};