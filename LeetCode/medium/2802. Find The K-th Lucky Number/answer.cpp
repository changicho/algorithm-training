#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary simulation
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 private:
  string convert(int num, int length) {
    string ret(length, '4');
    for (int i = 0; i < length; i++) {
      if (num % 2 == 1) {
        ret[i] = '7';
      }
      num /= 2;
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }

 public:
  string kthLuckyNumber(int k) {
    k++;
    int digit = log2(k);
    k -= pow(2, digit);

    return convert(k, digit);
  }
};