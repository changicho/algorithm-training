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

// use simulation
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int triangularSum(vector<int>& nums) {
    while (nums.size() > 1) {
      vector<int> arr;

      while (nums.size() > 1) {
        int cur = nums.back();
        nums.pop_back();
        arr.push_back((cur + nums.back()) % 10);
      }

      swap(nums, arr);
    }
    return nums.back();
  }
};