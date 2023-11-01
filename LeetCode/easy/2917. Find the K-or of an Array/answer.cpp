#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findKOr(vector<int>& nums, int k) {
    int answer = 0;

    for (int i = 0; i < 31; i++) {
      int digit = 1 << i;
      int count = 0;
      for (int& num : nums) {
        count += (num & digit) > 0;
      }

      if (count >= k) {
        answer += digit;
      }
    }
    return answer;
  }
};