#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use XOR
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int bits = x ^ y;

    int count = 0;
    while (bits > 0) {
      if (bits % 2 == 1) count++;
      bits /= 2;
    }
    return count;
  }
};