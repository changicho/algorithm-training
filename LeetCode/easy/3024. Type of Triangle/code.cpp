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

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  string triangleType(vector<int>& nums) {
    int maximum = *max_element(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum - maximum <= maximum) return "none";
    if (nums[0] == nums[1] && nums[1] == nums[2] && nums[2] == nums[0]) {
      return "equilateral";
    }
    if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
      return "isosceles";
    }

    return "scalene";
  }
};