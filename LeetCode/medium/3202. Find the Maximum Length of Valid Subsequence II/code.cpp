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
// time : O(N + K^2)
// space : O(K^2)
class Solution {
 public:
  int maximumLength(vector<int>& nums, int k) {
    vector<vector<int>> dp(k, vector<int>(k, 0));
    int answer = 0;

    for (int& num : nums) {
      num %= k;

      for (int prev = 0; prev < k; ++prev) {
        dp[num][prev] = dp[prev][num] + 1;

        answer = max(answer, dp[num][prev]);
      }
    }

    return answer;
  }
};