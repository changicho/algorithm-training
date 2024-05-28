#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N) + M)
// space : O(N)
class Solution {
 public:
  int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int target = 0; target <= 1000; target++) {
      int count = nums.end() - lower_bound(nums.begin(), nums.end(), target);

      if (count == target) return target;
    }

    return -1;
  }
};

// use counting sort
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int specialArray(vector<int>& nums) {
    int counts[1001] = {
        0,
    };

    for (int& num : nums) {
      counts[num]++;
    }

    int left = nums.size();
    for (int target = 0; target <= 1000; target++) {
      if (target == left) return target;

      left -= counts[target];
    }

    return -1;
  }
};