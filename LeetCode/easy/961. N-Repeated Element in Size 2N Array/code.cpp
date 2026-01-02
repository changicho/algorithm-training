#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use count
// time : O(N)
// space : O(M)
class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    int size = nums.size();

    int count[10001] = {
        0,
    };
    for (int& num : nums) {
      count[num]++;

      if (count[num] == size / 2) return num;
    }
    return -1;
  }
};

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int half = size / 2;
    if (nums[0] == nums[half - 1]) return nums[0];
    if (nums[half] == nums[size - 1]) return nums[size - 1];

    return nums[half];
  }
};