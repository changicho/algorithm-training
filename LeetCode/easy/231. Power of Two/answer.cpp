#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit operation (shift, and)

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    while (!(n & 1)) {
      n >>= 1;
    }

    return n == 1;
  }
};

// use mod, divide

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    while (n % 2 != 1) {
      n /= 2;
    }

    return n == 1;
  }
};

// use n & (n-1)

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    return (n & (n - 1)) == 0;
  }
};