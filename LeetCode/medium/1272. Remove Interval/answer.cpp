#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                     vector<int>& toBeRemoved) {
    vector<vector<int>> answer;

    for (vector<int>& interval : intervals) {
      if (interval[1] < toBeRemoved[0] || toBeRemoved[1] < interval[0]) {
        answer.push_back(interval);
      } else if (toBeRemoved[0] <= interval[0] &&
                 interval[1] <= toBeRemoved[1]) {
        continue;
      }

      if (toBeRemoved[0] <= interval[1] && interval[0] < toBeRemoved[0]) {
        answer.push_back({interval[0], toBeRemoved[0]});
      }
      if (interval[0] <= toBeRemoved[1] && toBeRemoved[1] < interval[1]) {
        answer.push_back({toBeRemoved[1], interval[1]});
      }
    }

    return answer;
  }
};