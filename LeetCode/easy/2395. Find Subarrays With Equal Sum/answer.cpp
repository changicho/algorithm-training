#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool findSubarrays(vector<int>& nums) {
    int size = nums.size();

    unordered_set<int> appears;
    for (int i = 0; i < size - 1; i++) {
      int cur = nums[i] + nums[i + 1];

      if (appears.count(cur) > 0) return true;
      appears.insert(cur);
    }
    return false;
  }
};