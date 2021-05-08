#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ret;

    for (vector<int> interval : intervals) {
      if (ret.empty()) {
        ret.push_back(interval);
        continue;
      }

      vector<int> top = ret.back();
      if (top.back() >= interval.front()) {
        ret.pop_back();
        ret.push_back({top.front(), max(top.back(), interval.back())});
      } else {
        ret.push_back(interval);
      }
    }

    return ret;
  }
};