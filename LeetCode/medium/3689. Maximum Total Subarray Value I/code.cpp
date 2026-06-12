#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long maxTotalValue(vector<int>& nums, int k) {
    int maximum = nums[0];
    int minimum = nums[0];

    for (int& num : nums) {
      maximum = max(maximum, num);
      minimum = min(minimum, num);
    }

    return (long long)(maximum - minimum) * k;
  }
};