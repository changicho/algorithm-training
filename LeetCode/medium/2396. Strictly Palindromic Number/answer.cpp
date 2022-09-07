#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  string convert(int n, int base) {
    string ret = "";
    while (n > 0) {
      ret += (n % base) + '0';
      n /= base;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  bool isPalindrome(string &str) {
    int length = str.length();

    for (int i = 0; i < length / 2; i++) {
      int rI = length - 1 - i;
      if (str[i] != str[rI]) return false;
    }
    return true;
  }

 public:
  bool isStrictlyPalindromic(int n) {
    for (int base = 2; base <= n - 2; base++) {
      string num = convert(n, base);

      if (!isPalindrome(num)) return false;
    }
    return true;
  }
};

// use return false
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool isStrictlyPalindromic(int n) { return false; }
};