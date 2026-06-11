#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// one pass
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                         vector<int>& waterStartTime,
                         vector<int>& waterDuration) {
    int lSize = landStartTime.size();
    int wSize = waterStartTime.size();

    function<int(int, vector<int>&, vector<int>&)> calc =
        [&](int start, vector<int>& starts, vector<int>& durations) {
          int ret = INT_MAX;

          int size = starts.size();

          for (int i = 0; i < size; i++) {
            ret = min(ret, max(start, starts[i]) + durations[i]);
          }
          return ret;
        };

    int answer = INT_MAX;
    int landMin = INT_MAX;
    for (int i = 0; i < lSize; i++) {
      int cur = landStartTime[i] + landDuration[i];
      landMin = min(cur, landMin);
    }
    answer = min(answer, calc(landMin, waterStartTime, waterDuration));

    int waterMin = INT_MAX;
    for (int i = 0; i < wSize; i++) {
      int cur = waterStartTime[i] + waterDuration[i];

      waterMin = min(cur, waterMin);
    }

    answer = min(answer, calc(waterMin, landStartTime, landDuration));

    return answer;
  }
};