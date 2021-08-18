#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use XOR

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int size = nums.size();

    int bit = 0;
    for (int num : nums) {
      bit ^= num;
    }

    for (int i = 0; i <= size; i++) {
      bit ^= i;
    }
    return bit;
  }
};