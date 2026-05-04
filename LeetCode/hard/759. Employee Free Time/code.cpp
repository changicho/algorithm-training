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

class Interval {
 public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

// bst diff map
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<Interval> answer;

    map<int, int> diff;
    for (vector<Interval>& s : schedule) {
      for (Interval& i : s) {
        diff[i.start]++;
        diff[i.end]--;
      }
    }

    int before = INT_MIN;
    int beforeTemp = 0;
    int temp = 0;
    for (auto [key, val] : diff) {
      beforeTemp = temp;
      temp += val;

      if (temp == 0) {
        before = key;
      } else if (beforeTemp == 0 && temp > 0) {
        if (before > 0) {
          answer.push_back({before, key});
        }
      }
    }

    return answer;
  }
};