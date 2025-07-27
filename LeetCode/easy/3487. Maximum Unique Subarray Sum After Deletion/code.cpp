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
// space : O(N
class Solution {
 public:
  int maxSum(vector<int>& nums) {
    unordered_set<int> us;

    int sum = 0;
    int maximum = INT_MIN;
    for (int& num : nums) {
      maximum = max(maximum, num);
      if (us.count(num) == 0 && num > 0) {
        sum += num;
        us.insert(num);
      }
    }

    if (sum == 0) {
      return maximum;
    }

    return sum;
  }
};