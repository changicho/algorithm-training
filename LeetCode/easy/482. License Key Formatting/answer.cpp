#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    string filtered = "";
    for (char &c : s) {
      if (c == '-') continue;
      filtered += toupper(c);
    }

    reverse(filtered.begin(), filtered.end());
    string ret = "";
    int count = 0;
    for (char &c : filtered) {
      ret += c;
      count++;

      if (count == k) {
        ret += '-';
        count = 0;
      }
    }

    if (ret.back() == '-') ret.pop_back();
    reverse(ret.begin(), ret.end());
    return ret;
  }
};