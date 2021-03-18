#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    string prefix = strs.front();

    for (string str : strs) {
      prefix = getPrefix(prefix, str);
    }

    return prefix;
  }

  string getPrefix(string a, string b) {
    string prefix = "";
    int length = min(a.length(), b.length());

    for (int index = 0; index < length; index++) {
      if (a[index] != b[index]) break;
      prefix += a[index];
    }
    return prefix;
  }
};