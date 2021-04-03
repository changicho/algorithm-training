#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    vector<string> rows(numRows);

    int index = 0;
    int diff = +1;
    for (char c : s) {
      rows[index] += c;

      index += diff;
      if (index == numRows - 1) {
        diff = -1;
      } else if (index == 0) {
        diff = +1;
      }
      index %= numRows;
    }

    string answer = "";
    for (string line : rows) {
      answer += line;
    }

    return answer;
  }
};

// visit by rule

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    string ret = "";
    int N = s.length();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j + i < N; j += cycleLen) {
        ret += s[j + i];
        if (i != 0 && i != numRows - 1 && j + cycleLen - i < N) {
          ret += s[j + cycleLen - i];
        }
      }
    }
    return ret;
  }
};