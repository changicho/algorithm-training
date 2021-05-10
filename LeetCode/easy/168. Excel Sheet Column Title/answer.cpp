#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use iterate

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string ret = "";
    columnNumber -= 1;

    while (columnNumber >= 0) {
      int div = columnNumber % 26;
      columnNumber /= 26;
      columnNumber -= 1;

      ret += (char)('A' + div);
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
};

// use recursion

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    return columnNumber == 0 ? "" : convertToTitle((columnNumber - 1) / 26) + (char)((columnNumber - 1) % 26 + 'A');
  }
};