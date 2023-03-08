#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use ordered set
// time :
//   - addNum: O(log_2(N))
//   - getIntervals: O(N)
// space: O(N)
class SummaryRanges {
 private:
  set<int> nums;

 public:
  SummaryRanges() {}

  void addNum(int value) { nums.insert(value); }

  vector<vector<int>> getIntervals() {
    if (nums.empty()) {
      return {};
    }
    vector<vector<int>> ret;
    int left = -1, right = -1;
    for (int num : nums) {
      if (left == -1) {
        left = right = num;
      } else if (num == right + 1) {
        right = num;
      } else {
        ret.push_back({left, right});
        left = right = num;
      }
    }
    ret.push_back({left, right});
    return ret;
  }
};