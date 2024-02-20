#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit operation (shift, and)
// time : O(1)
// space : O(1)
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
// time : O(1)
// space : O(1)
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
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    return (n & (n - 1)) == 0;
  }
};

// use builtin bit count
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    return __builtin_popcount(n) == 1;
  }
};
