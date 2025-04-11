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

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    unordered_set<int> us;
    for (int& num : nums) {
      if (num < k)
        return -1;
      else if (num > k)
        us.insert(num);
    }

    return us.size();
  }
};