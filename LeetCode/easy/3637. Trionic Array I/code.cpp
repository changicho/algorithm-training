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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool isTrionic(vector<int>& nums) {
    int size = nums.size();
    int desc = 0;
    int inc = 0;

    bool isInc = false;
    for (int i = 1; i < size; i++) {
      if (nums[i - 1] < nums[i]) {
        if (!isInc) {
          inc++;
          isInc = true;
        }
      } else if (nums[i - 1] > nums[i]) {
        if (isInc) {
          desc++;
          isInc = false;
        }
        if (inc == 0) return false;
      } else {
        return false;
      }
    }

    if (inc == 2 && desc == 1) return true;
    return false;
  }
};