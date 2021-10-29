#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use LIS with dynamic programming

class Solution {
 private:
  struct Status {
    int length, count;
  };

 public:
  int findNumberOfLIS(vector<int>& nums) {
    int size = nums.size();

    int maxLength = 0;
    int answer = 0;
    // dp[index] = {maximum LIS length, maximum case}
    vector<Status> dp(size, {1, 1});  // initial value is 1,1

    for (int current = 0; current < size; ++current) {
      for (int before = 0; before < current; ++before) {
        if (nums[before] >= nums[current]) continue;

        if (dp[before].length + 1 == dp[current].length) {
          // from before, can reach current length
          dp[current].count += dp[before].count;
        }

        if (dp[before].length >= dp[current].length) {
          dp[current] = {dp[before].length + 1, dp[before].count};
        }
      }

      if (maxLength == dp[current].length) {
        answer += dp[current].count;
      } else if (maxLength < dp[current].length) {
        maxLength = dp[current].length;
        answer = dp[current].count;
      }
    }

    return answer;
  }
};

// DP + Binary search + prefix sums
// time complexity : O(N * log_2(N))
// space complexity : O(N)

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;

    vector<vector<pair<int, int>>> dp(size + 1);
    int maxLength = 0;

    auto outerCheck = [](vector<pair<int, int>>& v, int target) {
      return !v.empty() && v.back().first < target;
    };
    auto innerCheck = [](int target, pair<int, int>& p) {
      return target > p.first;
    };

    for (int& num : nums) {
      int outer =
          lower_bound(dp.begin(), dp.end(), num, outerCheck) - dp.begin();

      int options = 1;
      int preList = outer - 1;
      if (preList >= 0) {
        int inner = upper_bound(dp[preList].begin(), dp[preList].end(), num,
                                innerCheck) -
                    dp[preList].begin();

        options = dp[preList].back().second;
        options -= inner == 0 ? 0 : dp[preList][inner - 1].second;
      }

      dp[outer].push_back({num, dp[outer].size() == 0
                                    ? options
                                    : dp[outer].back().second + options});
      if (outer == maxLength) maxLength++;
    }

    return dp[maxLength - 1].back().second;
  }
};