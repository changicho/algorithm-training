#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Job {
    int start, end, profit;

    const bool operator<(const Job& b) const { return end < b.end; }
  };

 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int size = startTime.size();
    // key : time, val : maximum
    // maximum val until time
    unordered_map<int, int> dp;

    vector<Job> jobs;
    for (int i = 0; i < size; i++) {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());

    vector<int> keys;
    int before = -1;
    for (int i = 0; i < size; i++) {
      Job cur = jobs[i];

      int leftCost = 0;
      int leftIdx =
          (upper_bound(keys.begin(), keys.end(), cur.start) - keys.begin()) - 1;
      if (leftIdx >= 0) {
        leftCost = dp[keys[leftIdx]];
      }

      dp[cur.end] = max(leftCost + cur.profit, before);
      before = dp[cur.end];
      keys.push_back(cur.end);
    }

    return dp[keys.back()];
  }
};