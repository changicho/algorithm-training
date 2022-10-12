#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & one pass
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int size = logs.size();
    int answer = logs.front()[0];
    int time = logs.front()[1];

    sort(logs.begin(), logs.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    for (int i = 1; i < size; i++) {
      int curTime = logs[i][1] - logs[i - 1][1];

      if (curTime > time) {
        answer = logs[i][0];
        time = curTime;
      } else if (curTime == time) {
        answer = min(answer, logs[i][0]);
      }
    }
    return answer;
  }
};