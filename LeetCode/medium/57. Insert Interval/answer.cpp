#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use merge and sort

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ret;

    intervals.push_back(newInterval);

    sort(intervals.begin(), intervals.end());

    for (vector<int> interval : intervals) {
      if (ret.empty()) {
        ret.push_back(interval);
      } else if (ret.back().back() >= interval.front()) {
        vector<int> cur = ret.back();
        ret.pop_back();

        ret.push_back({cur.front(), max(cur.back(), interval.back())});
      } else {
        ret.push_back(interval);
      }
    }

    return ret;
  }
};

// use iteration

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ret;
    int index = 0;
    int size = intervals.size();

    while (index < size && intervals[index].back() < newInterval.front()) {
      ret.push_back(intervals[index]);
      index++;
    }

    while (index < size && intervals[index].front() <= newInterval.back()) {
      newInterval.front() = min(newInterval.front(), intervals[index].front());
      newInterval.back() = max(newInterval.back(), intervals[index].back());
      index++;
    }
    // // other way
    // newInterval.front() = (index == size) ? newInterval.front() : min(newInterval.front(), intervals[index].front());
    // while (index < size && newInterval.back() >= intervals[index].front()) {
    //   index++;
    // }
    // newInterval.back() = (index == 0) ? newInterval.back() : max(intervals[index - 1].back(), newInterval.back());

    ret.push_back(newInterval);

    while (index < size) {
      ret.push_back(intervals[index]);
      index++;
    }
    return ret;
  }
};
