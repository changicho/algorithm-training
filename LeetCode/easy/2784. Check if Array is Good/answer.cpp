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
  bool isGood(vector<int>& nums) {
    int size = nums.size();

    sort(begin(nums), end(nums));

    for (int i = 0; i < size - 1; i++) {
      if (nums[i] != (i + 1)) return false;
    }
    if (nums.back() != size - 1) return false;
    return true;
  }
};

// use count
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool isGood(vector<int>& nums) {
    int size = nums.size();

    int counts[101] = {
        0,
    };
    for (int i = 0; i < size; i++) {
      if (nums[i] >= size) return false;
      counts[nums[i]]++;

      if (nums[i] < (size - 1) && counts[nums[i]] > 1) return false;
    }
    if (counts[size - 1] > 2) return false;
    return true;
  }
};