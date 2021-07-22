#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap

class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(intervals.begin(), intervals.end());

    for (vector<int>& interval : intervals) {
      int from = interval[0], to = interval[1];
      if (pq.empty()) {
        pq.push(to);
        continue;
      }

      if (from >= pq.top()) pq.pop();
      pq.push(to);
    }

    return pq.size();
  }
};

// use map (BST)

class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> m;  // key: time, val: +1 if start, -1 if end

    for (vector<int>& interval : intervals) {
      int from = interval[0], to = interval[1];
      m[from]++;
      m[to]--;
    }

    int count = 0, answer = 0;
    for (auto &cur : m) {
      count += cur.second;
      answer = max(count, answer);
    }

    return answer;
  }
};