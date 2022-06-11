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
  int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int count = 0;
    int before = nums.front();
    for (int& num : nums) {
      if (num - before > k) {
        count++;
        before = num;
        continue;
      }
    }

    return count + 1;
  }
};