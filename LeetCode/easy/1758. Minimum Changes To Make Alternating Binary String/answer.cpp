#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 private:
  int calc(string &s, int start) {
    int cur = start;
    int ret = 0;
    for (char &c : s) {
      if (c - '0' != cur) {
        ret++;
      }
      cur = !cur;
    }
    return ret;
  }

 public:
  int minOperations(string s) { return min(calc(s, 0), calc(s, 1)); }
};