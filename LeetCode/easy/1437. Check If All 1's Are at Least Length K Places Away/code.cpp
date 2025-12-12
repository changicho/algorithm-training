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
  bool kLengthApart(vector<int>& nums, int k) {
    int size = nums.size();
    int before = -1e6;

    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) continue;

      if (i - before <= k) return false;
      before = i;
    }

    return true;
  }
};