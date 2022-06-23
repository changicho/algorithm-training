#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int deleteAndEarn(vector<int> &nums) {
    map<int, int> um;

    for (int &num : nums) {
      um[num] += 1;
    }
    int size = um.size();

    vector<pair<int, int>> counts;
    for (auto &it : um) {
      counts.push_back({it.first, it.first * it.second});
    }

    vector<int> dp(size, 0);

    dp[0] = counts[0].second;

    if (size < 2) return dp[0];
    dp[1] =
        counts[1].second + (counts[1].first - counts[0].first > 1 ? dp[0] : 0);

    if (size < 3) return max(dp[0], dp[1]);
    dp[2] = counts[2].second +
            (counts[2].first - counts[1].first > 1 ? max(dp[0], dp[1]) : dp[0]);

    for (int i = 3; i < size; i++) {
      if (counts[i].first - counts[i - 1].first > 1) {
        dp[i] = counts[i].second + max(dp[i - 1], dp[i - 2]);
      } else {
        dp[i] = counts[i].second + max(dp[i - 2], dp[i - 3]);
      }
    }

    int answer = 0;
    for (int &num : dp) {
      answer = max(answer, num);
    }
    return answer;
  }
};

// use dynamic programming
// time : O(N + K)
// space : O(N)
class Solution {
 public:
  int deleteAndEarn(vector<int> &nums) {
    unordered_map<int, int> counts;
    int maximum = nums.front();
    for (int &n : nums) {
      counts[n]++;
      maximum = max(maximum, n);
    }

    vector<int> dp(10001, 0);

    dp[1] = counts[1] > 0 ? counts[1] : 0;
    for (int i = 2; i <= maximum; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + i * counts[i]);
    }

    return dp[maximum];
  }
};