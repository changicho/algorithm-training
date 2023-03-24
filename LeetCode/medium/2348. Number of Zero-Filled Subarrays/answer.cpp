#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass & count continuous zero
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long answer = 0;

    long long continuous = 0;
    for (int& num : nums) {
      if (num != 0) {
        // 1 + 2 + ... + X = X * (X + 1) / 2
        answer += (continuous + 1) * (continuous) / 2;
        continuous = 0;
      } else {
        continuous++;
      }
    }

    if (continuous > 0) {
      answer += (continuous + 1) * (continuous) / 2;
    }
    return answer;
  }
};