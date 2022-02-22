#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) {
           return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
         });

    int count = 0;
    int prevEnd = 0;
    for (vector<int> &interval : intervals) {
      int end = interval[1];

      if (prevEnd < end) {
        count++;
        prevEnd = end;
      }
    }
    return count;
  }
};

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  bool checkCovered(vector<int> &a, vector<int> &b) {
    return b[0] <= a[0] && a[1] <= b[1];
  }

 public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    int size = intervals.size();
    int answer = size;

    for (int from = 0; from < size; from++) {
      bool isCovered = false;

      for (int to = 0; to < size; to++) {
        if (from == to) continue;

        if (checkCovered(intervals[from], intervals[to])) {
          isCovered = true;
          break;
        }
      }

      if (isCovered) answer--;
    }

    return answer;
  }
};