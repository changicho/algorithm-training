#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int sum = 0;

  void recursive(vector<int>& nums, int size, int index, int bit) {
    if (index == size) {
      sum += bit;
      return;
    }

    recursive(nums, size, index + 1, bit);
    recursive(nums, size, index + 1, bit ^ nums[index]);
  }

 public:
  int subsetXORSum(vector<int>& nums) {
    int size = nums.size();

    recursive(nums, size, 0, 0);

    return sum;
  }
};