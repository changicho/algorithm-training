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
  bool isPalindrome(string &word) {
    int size = word.size();
    for (int i = 0; i < size / 2; i++) {
      int rI = size - 1 - i;

      if (word[i] != word[rI]) return false;
    }
    return true;
  }

 public:
  string firstPalindrome(vector<string> &words) {
    for (string &word : words) {
      if (isPalindrome(word)) return word;
    }
    return "";
  }
};