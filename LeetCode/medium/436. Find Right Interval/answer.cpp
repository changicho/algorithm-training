#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Interval {
    int start, end, index;

    bool operator<(const Interval &b) const { return start < b.start; }
  };

  int getIndex(vector<Interval> &arr, int target) {
    int left = 0, right = arr.size();

    int ret = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (target <= arr[mid].start) {
        // pick left;
        right = mid;
        ret = mid;
      } else {
        // pick right;
        left = mid + 1;
      }
    }

    if (ret == -1) return -1;
    return arr[ret].index;
  }

 public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int size = intervals.size();

    vector<int> ret(size, -1);
    vector<Interval> arr;
    for (int i = 0; i < size; i++) {
      vector<int> &interval = intervals[i];
      arr.push_back({interval[0], interval[1], i});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < size; i++) {
      Interval &cur = arr[i];

      ret[cur.index] = getIndex(arr, cur.end);
    }

    return ret;
  }
};