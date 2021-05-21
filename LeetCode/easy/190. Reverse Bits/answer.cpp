#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use iterate

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t answer = 0;
    for (int i = 31; i >= 0; i--) {
      // answer |= (n % 2) << i;
      answer |= (n & 1) << i;
      n /= 2;
    }
    return answer;
  }
};

// use byte reverse

class Solution {
 public:
  uint32_t reverseByte(uint32_t byte) {
    return (byte * 0x0202020202 & 0x010884422010) % 1023;
  }

  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    int power = 24;

    while (n != 0) {
      ret += reverseByte(n & 0xff) << power;
      n = n >> 8;
      power -= 8;
    }
    return ret;
  }
};

// use merge

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
  }
};