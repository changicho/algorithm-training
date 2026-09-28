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

// sort & heap
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long countIntersectingIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    long long answer = 0;
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