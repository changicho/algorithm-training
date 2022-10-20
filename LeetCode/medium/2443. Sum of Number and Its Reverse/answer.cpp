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
  int reverseDigit(int num) {
    int ret = 0;
    while (num > 0) {
      ret *= 10;
      ret += num % 10;
      num /= 10;
    }
    return ret;
  }

 public:
  bool sumOfNumberAndReverse(int num) {
    for (int i = 0; i <= num; i++) {
      if (i + reverseDigit(i) == num) {
        return true;
      }
    }
    return false;
  }
};