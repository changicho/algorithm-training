#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int ret = 0;
    int length = columnTitle.length();

    for (char c : columnTitle) {
      ret = ret * 26 + (c - 'A' + 1);
    }

    return ret;
  }
};