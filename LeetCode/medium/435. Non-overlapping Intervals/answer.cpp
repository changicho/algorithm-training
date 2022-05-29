#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort and compare end
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
      if (a[1] != b[1]) return a[1] < b[1];
      return a[0] < b[0];
    });

    int count = 0;
    int lastEnd = INT_MIN;
    for (vector<int> &i : intervals) {
      if (i[0] < lastEnd) {
        count++;
        continue;
      }
      lastEnd = i[1];
    }

    return count;
  }
};