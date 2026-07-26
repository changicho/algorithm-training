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
  int maximumProduct(vector<int>& nums) {
    int a = max({nums[0], nums[1], nums[2]});
    int c = min({nums[0], nums[1], nums[2]});
    int b = nums[0] + nums[1] + nums[2] - a - c;

    int d = b;
    int e = c;

    int size = nums.size();
    for (int i = 3; i < size; i++) {
      int cur = nums[i];
      if (cur > a) {
        c = b;
        b = a;
        a = cur;
      } else if (cur > b) {
        c = b;
        b = cur;
      } else if (cur > c) {
        c = cur;
      }

      if (cur < e) {
        d = e;
        e = cur;
      } else if (cur < d) {
        d = cur;
      }
    }

    return max(a * b * c, a * d * e);
  }
};
