#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use mod
// time : O(log_10(N))
// space : O(1)
class Solution {
 public:
  int reverse(int x) {
    bool isNeg = x < 0;

    int ret = 0;
    while (x) {
      if (isNeg && ret < INT_MIN / 10) return 0;
      if (!isNeg && ret > INT_MAX / 10) return 0;

      ret *= 10;
      ret += x % 10;
      x /= 10;
    }
    return ret;
  }
};