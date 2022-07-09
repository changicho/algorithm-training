#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maximumXOR(vector<int>& nums) {
    int bit = 0;
    for (int& n : nums) {
      bit |= n;
    }
    return bit;
  }
};