#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use two pointer & heap
// time : O((K + C) * log_2(C))
// space : O(C)
class Solution {
 private:
  struct Data {
    int cost, index;

    const bool operator<(const Data& b) const {
      if (cost != b.cost) return cost > b.cost;
      return index > b.index;
    }
  };

 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    int size = costs.size();

    priority_queue<Data> pq;

    int left = candidates - 1, right = size - candidates;

    if (left >= right) {
      for (int i = 0; i < size; i++) {
        pq.push({costs[i], i});
      }
    } else {
      for (int i = 0; i <= left; i++) {
        pq.push({costs[i], i});
      }
      for (int i = size - 1; i >= right; i--) {
        pq.push({costs[i], i});
      }
    }

    long long answer = 0;
    for (int i = 0; i < k && !pq.empty(); i++) {
      Data cur = pq.top();
      pq.pop();

      answer += cur.cost;

      if (left + 1 >= right) continue;
      // pick from left
      if (cur.index <= left && (left < size - 1)) {
        left++;
        pq.push({costs[left], left});
      } else if (right > 0) {
        right--;
        pq.push({costs[right], right});
      }
    }
    return answer;
  }
};