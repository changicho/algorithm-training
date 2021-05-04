#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use divide

class Solution {
 public:
  double myPow(double x, int n) {
    if (n < 0) {
      return 1.0 / (myPow(x, -(n + 1)) * x);
    }
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return x;
    }

    double half = myPow(x, n / 2);
    if (n % 2 == 0) {
      return half * half;
    }
    return half * half * x;
  }
};

// use STL

class Solution {
 public:
  double myPow(double x, int n) {
    return pow(x, n);
  }
};