#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dp & binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  // maximum days[index] < target
  int find(vector<int> &days, int target) {
    int left = 0, right = days.size() + 1;
    int ret = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (days[mid] < target) {
        // pick right;
        ret = mid;
        left = mid + 1;
      } else {
        // pick left;
        right = mid;
      }
    }
    return ret;
  }

 public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int size = days.size();

    vector<int> dp(size, INT_MAX);
    for (int &cost : costs) {
      dp[0] = min(dp[0], cost);
    }

    for (int i = 1; i < size; i++) {
      for (int &cost : costs) {
        dp[i] = min(dp[i], dp[i - 1] + cost);
      }

      if (days[i] - days[i - 1] < 7) {
        int start = days[i] - 7 + 1;
        int before = find(days, start);
        dp[i] = min(dp[i], costs[1] + (before == -1 ? 0 : dp[before]));
      }
      if (days[i] - days[i - 1] < 30) {
        int start = days[i] - 30 + 1;
        int before = find(days, start);
        dp[i] = min(dp[i], costs[2] + (before == -1 ? 0 : dp[before]));
      }
    }

    return dp[size - 1];
  }
};

// use dp (top down)
// time : O(N)
// space : O(N)
class Solution {
 public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int size = days.size();
    int dp[size];

    for (int i = size - 1; i >= 0; i--) {
      int oneDay = costs[0] + (i < size - 1 ? dp[i + 1] : 0);

      int next = i + 1;
      while (next < size && days[next] < days[i] + 7) {
        next++;
      }
      int oneWeek = costs[1] + (next < size ? dp[next] : 0);

      while (next < size && days[next] < days[i] + 30) {
        next++;
      }
      int oneMonth = costs[2] + (next < size ? dp[next] : 0);

      dp[i] = min({oneDay, oneWeek, oneMonth});
    }

    return dp[0];
  }
};

// use dp (bottom up)
// time : O(N)
// space : O(N)
class Solution {
 public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int size = days.size();
    vector<int> dp(size, INT_MAX);

    for (int i = 0; i < size; i++) {
      int oneDay = (i - 1 < 0 ? 0 : dp[i - 1]) + costs[0];

      int before = i - 1;
      while (before >= 0 && days[i] - days[before] < 7) {
        before--;
      }
      int oneWeek = (before < 0 ? 0 : dp[before]) + costs[1];

      before = i - 1;
      while (before >= 0 && days[i] - days[before] < 30) {
        before--;
      }
      int oneMonth = (before < 0 ? 0 : dp[before]) + costs[2];

      dp[i] = min({oneDay, oneWeek, oneMonth});
    }

    return dp[size - 1];
  }
};