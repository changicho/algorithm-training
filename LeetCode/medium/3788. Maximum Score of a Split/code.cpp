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

// use prefix suffix
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long maximumScore(vector<int>& nums) {
    int size = nums.size();
    long long answer = LLONG_MIN;

    long long sum = accumulate(nums.begin(), nums.end(), 0LL) - nums[size - 1];
    long long beforeMin = nums[size - 1];

    for (int i = size - 2; i >= 0; i--) {
      long long cur = sum - beforeMin;
      beforeMin = min(beforeMin, (long long)nums[i]);
      sum -= nums[i];
      answer = max(cur, answer);
    }
    return answer;
  }
};