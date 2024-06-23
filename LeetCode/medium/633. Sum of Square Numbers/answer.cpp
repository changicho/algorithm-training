#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sqrt one pass
// time : O(log_2(C) * sqrt(C))
// space : O(1)
class Solution {
 public:
  bool judgeSquareSum(int c) {
    for (int a = 0; a <= sqrt(c); a++) {
      double b = sqrt(c - a * a);
      if (b == (int)b) return true;
    }
    return false;
  }
};