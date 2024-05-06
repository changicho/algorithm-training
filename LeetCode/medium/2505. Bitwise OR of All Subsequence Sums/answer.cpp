#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit count
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long subsequenceSumOr(vector<int>& nums) {
    long long bits[64] = {
        0,
    };

    for (int& num : nums) {
      for (int i = 0; i < 31; i++) {
        if (num & (1 << i)) {
          bits[i]++;
        }
      }
    }

    long long answer = 0;
    for (int i = 0; i < 63; ++i) {
      if (bits[i] > 0) {
        answer |= 1LL << i;
      }

      // carry count
      bits[i + 1] += bits[i] / 2;
    }

    return answer;
  }
};