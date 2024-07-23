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
  bool checkValidString(string s) {
    int openMin = 0;  // counts the minimum open parenthesis
    int openMax = 0;  // counts the maximum open parenthesis

    for (char &c : s) {
      switch (c) {
        case '(':
          openMin++;
          openMax++;
          break;
        case ')':
          openMin = max(openMin - 1, 0);
          openMax--;
          break;
        case '*':
          openMin = max(openMin - 1, 0);
          openMax++;
          break;
      }

      if (openMax < 0) return false;
    }

    return openMin == 0;
  }
};