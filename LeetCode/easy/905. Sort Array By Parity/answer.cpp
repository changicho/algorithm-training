#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int size = nums.size();
    int index = 0;
    for (int i = 0; i < size; i++) {
      while (index < i && nums[index] % 2 == 0) {
        index++;
      }
      if (nums[index] % 2 == 1 && nums[i] % 2 == 0) {
        swap(nums[index], nums[i]);
        index++;
      }
    }
    return nums;
  }
};