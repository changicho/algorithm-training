#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use XOR
// time : O(N)
// space : O(1)
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

// use reverse sign
// time : O(N)
// space : O(1)
class Solution {
 private:
  const int MOD = 1e6;

 public:
  int missingNumber(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      int cur = abs(nums[i] % MOD);
      if (cur == 0) continue;

      if (nums[cur - 1] == 0) nums[cur - 1] += MOD;
      nums[cur - 1] *= -1;
    }

    for (int i = 0; i < size; i++) {
      if (nums[i] >= 0) return i + 1;
    }
    return 0;
  }
};