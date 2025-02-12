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
  bool isArraySpecial(vector<int>& nums) {
    int size = nums.size();

    for (int i = 0; i < size - 1; i++) {
      int first = nums[i] % 2;
      int second = nums[i + 1] % 2;

      if (first == second) return false;
    }
    return true;
  }
};