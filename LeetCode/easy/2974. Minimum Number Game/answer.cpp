#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> numberGame(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i += 2) {
      swap(nums[i], nums[i + 1]);
    }
    return nums;
  }
};