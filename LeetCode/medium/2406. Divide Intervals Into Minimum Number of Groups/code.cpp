#include <algorithm>
#include <climits>
#include <cmath>
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

// use sort & multiset
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    multiset<int> ms;
    int answer = 0;
    for (vector<int>& interval : intervals) {
      int left = interval[0], right = interval[1];

      auto it = ms.lower_bound(left);
      if (it == ms.begin()) {
        ms.insert(right);
      } else {
        int target = *prev(it);
        // remove only one
        ms.extract(target);
        ms.insert(right);
      }

      answer = max((int)ms.size(), answer);
    }

    return answer;
  }
};

// use sort & count
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    vector<pair<int, int>> inAndOut;
    for (vector<int>& interval : intervals) {
      int left = interval[0], right = interval[1];

      // income +1, outcome -1
      inAndOut.push_back({left, 1});
      inAndOut.push_back({right + 1, -1});
    }

    sort(inAndOut.begin(), inAndOut.end());

    int answer = 0;
    int curSize = 0;
    for (pair<int, int>& p : inAndOut) {
      curSize += p.second;

      answer = max(answer, curSize);
    }

    return answer;
  }
};

// use counting sort
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    int inAndOut[1000002] = {
        0,
    };

    int from = INT_MAX, to = INT_MIN;
    for (vector<int>& interval : intervals) {
      int left = interval[0], right = interval[1];

      inAndOut[left]++;
      inAndOut[right + 1]--;

      from = min(from, left);
      to = max(to, right + 1);
    }

    int answer = 0;
    int curSize = 0;

    for (int time = from; time <= to; time++) {
      curSize += inAndOut[time];

      answer = max(answer, curSize);
    }

    return answer;
  }
};