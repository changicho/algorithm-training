#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// iterate
// time : O(1)
// space : O(1)
class Solution {
 public:
  int reverseBits(int n) {
    int answer = 0;
    for (int i = 31; i >= 0; i--) {
      // answer |= (n % 2) << i;
      answer |= (n & 1) << i;
      n /= 2;
    }
    return answer;
  }
};

// iterate
// time : O(1)
// space : O(1)
class Solution {
 public:
  int reverseBits(int n) {
    int answer = 0;

    for (int i = 0; i < 16; i++) {
      int left = 1 << i;
      int right = 1 << (31 - i);

      answer += (n & right) ? left : 0;
      answer += (n & left) ? right : 0;
    }
    return answer;
  }
};

// byte reverse
// time : O(1)
// space : O(1)
class Solution {
 public:
  int reverseByte(int byte) {
    return (byte * 0x0202020202 & 0x010884422010) % 1023;
  }

  int reverseBits(int n) {
    int ret = 0;
    int power = 24;

    while (n != 0) {
      ret += reverseByte(n & 0xff) << power;
      n = n >> 8;
      power -= 8;
    }
    return ret;
  }
};

// merge
// time : O(1)
// space : O(1)
class Solution {
 public:
  int reverseBits(int n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
  }
};