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
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> avoidFlood(vector<int>& rains) {
    int size = rains.size();

    unordered_map<int, int> before;
    vector<int> nexts(size, size + 1);
    for (int i = 0; i < size; i++) {
      int r = rains[i];
      if (r == 0) continue;
      if (before.count(r)) {
        nexts[before[r]] = i;
      }

      before[r] = i;
    }

    // index, value
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> count;

    vector<int> answer;
    for (int i = 0; i < size; i++) {
      int r = rains[i];

      if (r == 0) {
        if (!pq.empty()) {
          pair<int, int> cur = pq.top();
          pq.pop();

          answer.push_back(cur.second);
          count[cur.second]--;
        } else {
          answer.push_back(1);
        }
      } else {
        if (count[r] > 0) return {};

        answer.push_back(-1);

        pq.push({-nexts[i], r});
        count[r]++;
      }
    }

    return answer;
  }
};

// use BST set
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> avoidFlood(vector<int>& rains) {
    int size = rains.size();
    vector<int> answer(size, 1);

    set<int> zeroSet;
    unordered_map<int, int> lastI;

    for (int i = 0; i < size; i++) {
      int r = rains[i];

      if (r == 0) {
        zeroSet.insert(i);
      } else {
        answer[i] = -1;

        if (lastI.count(r)) {
          auto it = zeroSet.lower_bound(lastI[r]);
          if (it == zeroSet.end()) {
            return {};
          }
          answer[*it] = r;
          zeroSet.erase(it);
        }
        lastI[r] = i;
      }
    }
    return answer;
  }
};