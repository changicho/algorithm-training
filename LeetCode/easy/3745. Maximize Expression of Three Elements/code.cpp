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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maximizeExpressionOfThree(vector<int>& nums) {
    int size = nums.size();

    int minimum = min({nums[0], nums[1], nums[2]});
    int maximum1 = max({nums[0], nums[1], nums[2]});
    int maximum2 = nums[0] + nums[1] + nums[2] - minimum - maximum1;

    for (int i = 3; i < size; i++) {
      int& num = nums[i];

      if (minimum > num) {
        minimum = num;
      } else if (maximum1 <= num) {
        maximum2 = maximum1;
        maximum1 = num;
      } else if (maximum2 < num) {
        maximum2 = num;
      }
    }

    return maximum1 + maximum2 - minimum;
  }
};