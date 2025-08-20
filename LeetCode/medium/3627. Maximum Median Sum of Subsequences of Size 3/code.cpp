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

// use sort & greedy
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maximumMedianSum(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    long long sum = 0;

    int left = 0, right = size - 1;

    while (left < right) {
      sum += nums[right - 1];
      left++;
      right -= 2;
    }
    return sum;
  }
};