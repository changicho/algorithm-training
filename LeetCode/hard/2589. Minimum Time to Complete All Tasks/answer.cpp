#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy & sort
// time : O(N * log_2(N))
// space : O(2000)
class Solution {
 public:
  int findMinimumTime(vector<vector<int>>& tasks) {
    bool isTimeSpent[2001] = {
        false,
    };

    // sort endtime ascending
    sort(tasks.begin(), tasks.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

    for (vector<int>& task : tasks) {
      int usedTime = 0;
      for (int t = task[0]; t <= task[1]; t++) {
        if (isTimeSpent[t]) usedTime++;
      }

      for (int t = task[1]; usedTime < task[2] && t >= task[0]; t--) {
        if (isTimeSpent[t] == false) {
          usedTime++;
          isTimeSpent[t] = true;
        }
      }
    }

    int answer = 0;
    for (int t = 0; t <= 2000; t++) {
      if (isTimeSpent[t]) answer++;
    }
    return answer;
  }
};