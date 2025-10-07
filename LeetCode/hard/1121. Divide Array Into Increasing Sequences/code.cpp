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

// use one pass & duplicated count
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool canDivideIntoSubsequences(vector<int>& nums, int k) {
    int size = nums.size();

    int before = nums[0], count = 0;
    for (int& num : nums) {
      if (num == before) {
        count++;
      } else {
        before = num;
        count = 1;
      }

      // need start count more than available
      if (count * k > size) return false;
    }
    return true;
  }
};

// use duplicated count
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool canDivideIntoSubsequences(vector<int>& nums, int k) {
    int size = nums.size();

    unordered_map<int, int> count;
    for (int& num : nums) {
      count[num]++;
    }

    for (auto [key, val] : count) {
      if (val * k > size) return false;
    }
    return true;
  }
};