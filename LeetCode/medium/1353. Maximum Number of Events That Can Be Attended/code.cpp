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

// use heap
// time : O((M + N) * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    int size = events.size();
    int maxDay = 0;
    for (vector<int>& e : events) {
      maxDay = max(maxDay, e[1]);
    }

    priority_queue<int, vector<int>, greater<>> pq;
    sort(events.begin(), events.end());
    int answer = 0;

    for (int day = 0, i = 0; day <= maxDay; day++) {
      while (i < size && events[i][0] <= day) {
        pq.push(events[i][1]);
        i++;
      }

      while (!pq.empty() && pq.top() < day) {
        pq.pop();
      }
      if (!pq.empty()) {
        pq.pop();
        answer++;
      }
    }

    return answer;
  }
};