#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int ret = 1;

    for (int& n : nums) {
      if (n > 0) {
        ret *= 1;
      } else if (n < 0) {
        ret *= -1;
      } else {
        ret *= 0;
      }
    }

    return ret;
  }
};