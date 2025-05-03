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

// use dynamic programming
// time : O(N * M * L)
// space : O(N * M * L)
class Solution {
 public:
  int maxProduct(vector<int>& nums, int k, int limit) {
    int size = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(k) > abs(sum)) return -1;

    unordered_map<
        int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>
        dp;

    function<int(int, int, int, int)> recursive =
        [&](int i, int count, int curSum, int curProduct) {
          if (i == size) {
            if (curSum == k && curProduct <= limit && count > 0) {
              return curProduct;
            }
            return -1;
          }

          if (dp[i][curSum][curProduct].count(count % 2)) {
            return dp[i][curSum][curProduct][count % 2];
          }

          int first = recursive(i + 1, count + 1,
                                curSum + (count % 2 == 0 ? 1 : -1) * nums[i],
                                min(curProduct * nums[i], limit + 1));
          int second = recursive(i + 1, count, curSum, curProduct);
          return dp[i][curSum][curProduct][count % 2] = max(first, second);
        };

    return recursive(0, 0, 0, 1);
  }
};