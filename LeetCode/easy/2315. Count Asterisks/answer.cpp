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
  int countAsterisks(string s) {
    int count = 0;
    bool isPair = false;
    for (char &c : s) {
      if (c == '|') {
        isPair = !isPair;
      } else if (!isPair && c == '*') {
        count++;
      }
    }
    return count;
  }
};