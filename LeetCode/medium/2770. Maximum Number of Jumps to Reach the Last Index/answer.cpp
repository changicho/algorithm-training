#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int maximumJumps(vector<int> &nums, int target) {
    int size = nums.size();

    vector<vector<int>> graph(size);
    for (int from = 0; from < size; from++) {
      for (int to = from + 1; to < size; to++) {
        int diff = nums[from] - nums[to];

        if (-target <= diff && diff <= target) {
          graph[from].push_back(to);
        }
      }
    }

    vector<int> dp(size, -1);
    dp[0] = 0;
    for (int from = 0; from < size; from++) {
      if (dp[from] == -1) continue;
      for (int &to : graph[from]) {
        dp[to] = max(dp[to], dp[from] + 1);
      }
    }

    if (dp[size - 1] == 0) return -1;
    return dp[size - 1];
  }
};