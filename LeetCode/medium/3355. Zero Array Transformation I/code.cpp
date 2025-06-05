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

// use diff array
// time : O(N + Q)
// space : O(N)
class Solution {
 public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int size = nums.size();

    vector<int> diffs(size + 1, 0);
    for (vector<int>& q : queries) {
      int l = q[0], r = q[1];

      diffs[l]++;
      diffs[r + 1]--;
    }

    int diff = 0;
    for (int i = 0; i < size; i++) {
      diff += diffs[i];

      if (nums[i] > diff) return false;
    }
    return true;
  }
};