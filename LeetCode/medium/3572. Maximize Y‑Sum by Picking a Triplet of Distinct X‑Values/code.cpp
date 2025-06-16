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

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
    int size = x.size();
    unordered_map<int, int> yMax;

    for (int i = 0; i < size; i++) {
      yMax[x[i]] = max(yMax[x[i]], y[i]);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [k, v] : yMax) {
      pq.push(v);
      if (pq.size() > 3) pq.pop();
    }

    if (pq.size() < 3) return -1;
    int answer = 0;
    while (!pq.empty()) {
      answer += pq.top();
      pq.pop();
    }
    return answer;
  }
};