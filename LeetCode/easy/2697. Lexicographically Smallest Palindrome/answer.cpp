#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  string makeSmallestPalindrome(string s) {
    int size = s.size();

    for (int i = 0; i < size / 2; i++) {
      int rI = size - 1 - i;

      if (s[i] != s[rI]) {
        s[i] = s[rI] = min(s[i], s[rI]);
      }
    }

    return s;
  }
};