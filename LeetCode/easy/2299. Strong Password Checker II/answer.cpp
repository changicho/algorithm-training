#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(L)
// space : O(1)
class Solution {
 public:
  bool strongPasswordCheckerII(string password) {
    bool hasDigit = false;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasSameAdj = false;
    bool hasSpecial = false;

    string special = "!@#$%^&*()-+";
    unordered_set<char> specials;
    for (char &c : special) {
      specials.insert(c);
    }

    if (password.length() < 8) return false;
    for (char &c : password) {
      if (isdigit(c)) hasDigit = true;
      if (islower(c)) hasLower = true;
      if (isupper(c)) hasUpper = true;
      if (specials.count(c) > 0) hasSpecial = true;
    }

    int length = password.length();
    for (int i = 0; i < length - 1; i++) {
      if (password[i] == password[i + 1]) hasSameAdj = true;
    }

    return hasDigit && hasUpper && hasLower && hasSpecial && !hasSameAdj;
  }
};