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

// count odd
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool uniformArray(vector<int>& nums1) {
    int odd = 0;
    int minimum = nums1[0];
    for (int& num : nums1) {
      minimum = min(minimum, num);
      if (num % 2 == 1) {
        odd++;
      }
    }

    if (odd == 0) return true;
    if (minimum % 2 == 1) return true;
    return false;
  }
};