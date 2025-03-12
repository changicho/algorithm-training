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

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    int size = nums.size();
    int zeroS = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    int zeroE = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();

    int neg = zeroS;
    int pos = size - zeroE;

    return max(neg, pos);
  }
};