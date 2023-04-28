#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math, divisor
// time : O(sqrt(N))
// space : O(1)
class Solution {
 public:
  int bulbSwitch(int n) {
    int count = 0;
    for (int num = 1; num * num <= n; num++) {
      count++;
    }
    return count;
  }
};

// use math, sqrt
// time : O(1)
// space : O(1)
class Solution {
 public:
  int bulbSwitch(int n) { return sqrt(n); }
};