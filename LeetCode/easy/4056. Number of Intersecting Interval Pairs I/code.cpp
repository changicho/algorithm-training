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

using ll = long long;

// brute force
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  bool check(vector<int>& a, vector<int>& b) {
    return a[0] <= b[1] && b[0] <= a[1];
  }

 public:
  int countIntersectingIntervals(vector<vector<int>>& intervals) {
    int size = intervals.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (check(intervals[i], intervals[j])) {
          answer++;
        }
      }
    }
    return answer;
  }
};

// sort & priority queue
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int countIntersectingIntervals(vector<vector<int>>& intervals) {
    int size = intervals.size();

    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int answer = 0;
    for (vector<int>& i : intervals) {
      while (!pq.empty() && pq.top() < i[0]) {
        pq.pop();
      }

      answer += pq.size();

      pq.push(i[1]);
    }
    return answer;
  }
};