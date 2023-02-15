#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use priority queue
// time : O((N + K) \* log_2(N))
// space : O(N)
class Solution {
 public:
  long long pickGifts(vector<int>& gifts, int k) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int& g : gifts) {
      pq.push(g);
    }

    while (k-- && !pq.empty()) {
      int top = pq.top();
      pq.pop();

      int next = sqrt(top);
      pq.push(next);
    }

    while (!pq.empty()) {
      int top = pq.top();
      pq.pop();
      answer += top;
    }

    return answer;
  }
};