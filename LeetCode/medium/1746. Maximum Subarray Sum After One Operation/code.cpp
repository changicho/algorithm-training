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

// use max left and max right
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxSumAfterOperation(vector<int>& nums) {
    int size = nums.size();

    vector<int> maxRights(size);
    vector<int> maxLefts(size);

    maxLefts[0] = maxRights[size - 1] = 0;
    for (int left = 1, right = size - 2; left < size; left++, right--) {
      maxLefts[left] = max(maxLefts[left - 1] + nums[left - 1], 0);
      maxRights[right] = max(maxRights[right + 1] + nums[right + 1], 0);
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int cur = nums[i];
      int subArraySum = maxLefts[i] + cur * cur + maxRights[i];

      answer = max(answer, subArraySum);
    }
    return answer;
  }
};

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxSumAfterOperation(vector<int>& nums) {
    int size = nums.size();

    vector<vector<int>> dp(size, vector<int>(2, 0));

    dp[0][0] = nums[0];
    dp[0][1] = nums[0] * nums[0];

    int maxSum = nums[0] * nums[0];

    for (int i = 1; i < size; i++) {
      dp[i][0] = max(nums[i], dp[i - 1][0] + nums[i]);

      // three case
      // use nums[i]^2 only
      // use nums[i]^2 and prev normal sum
      // use prev square sum and nums[i]
      dp[i][1] = max({nums[i] * nums[i], dp[i - 1][0] + nums[i] * nums[i],
                      dp[i - 1][1] + nums[i]});

      maxSum = max(maxSum, dp[i][1]);
    }

    return maxSum;
  }
};