#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit count

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int answer = 0;
    for (int i = 0; i < 32; i++) {
      if (n & 1 == 1) answer += 1;
      n >>= 1;
    }

    return answer;
  }
};

// use and operation

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int answer = 0;
    while (n != 0) {
      answer++;
      n &= (n - 1);
    }
    return answer;
  }
};