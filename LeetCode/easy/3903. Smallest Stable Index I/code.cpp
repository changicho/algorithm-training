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

// suffix minimum & one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    int size = nums.size();

    vector<int> minimum(size);
    minimum[size - 1] = nums[size - 1];

    for (int i = size - 2; i >= 0; i--) {
      minimum[i] = min(minimum[i + 1], nums[i]);
    }

    int maximum = nums[0];

    for (int i = 0; i < size; i++) {
      maximum = max(maximum, nums[i]);

      if (maximum - minimum[i] <= k) {
        return i;
      }
    }
    return -1;
  }
};