#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use
// time : O(N)
// space : O(1)
class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
    int size = nums.size();
    for (auto &num : nums) {
      if (num <= 0 || num > size) {
        num = size + 1;
      }
    }

    for (int &num : nums) {
      if (abs(num) <= size) {
        if (nums[abs(num) - 1] > 0) nums[abs(num) - 1] = -nums[abs(num) - 1];
      }
    }
    for (int i = 0; i < size; i++) {
      if (nums[i] >= 0) return i + 1;
    }
    return size + 1;
  }
};