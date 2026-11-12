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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int peakValleyDifference(vector<int>& nums) {
    int size = nums.size();
    int peak = 0, valley = 0;

    for (int i = 1; i < size - 1; i++) {
      if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
        peak += nums[i];
      }
      if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
        valley += nums[i];
      }
    }

    return peak - valley;
  }
};