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
// time : O(N + log_2(M))
// space : O(1)
class Solution {
 public:
  int findGCD(vector<int>& nums) {
    int minimum = nums[0];
    int maximum = nums[0];

    for (int& num : nums) {
      minimum = min(minimum, num);
      maximum = max(maximum, num);
    }

    return gcd(maximum, minimum);
  }
};