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

// use priority queue
// time : O((N + K) * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Data {
    int pass, total;

    bool operator<(const Data &b) const {
      double cur = (double)(pass + 1) / (total + 1) - (double)(pass) / (total);
      double comp =
          (double)(b.pass + 1) / (b.total + 1) - (double)(b.pass) / (b.total);
      return cur < comp;
    }
  };

 public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    int size = classes.size();

    priority_queue<Data> pq;

    for (vector<int> &c : classes) {
      int pass = c[0], total = c[1];

      pq.push({pass, total});
    }

    while (extraStudents--) {
      Data cur = pq.top();
      pq.pop();

      cur.pass += 1;
      cur.total += 1;

      pq.push(cur);
    }

    double sum = 0;
    while (!pq.empty()) {
      Data cur = pq.top();
      pq.pop();

      double ratio = (double)cur.pass / cur.total;
      sum += ratio;
    }
    return sum / size;
  }
};