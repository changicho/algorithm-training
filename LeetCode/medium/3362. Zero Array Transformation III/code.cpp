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
// time : O(N * log_2(Q))
// space : O(N + Q)
class Solution {
 public:
  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    int size = nums.size(), qSize = queries.size();

    sort(queries.begin(), queries.end());
    priority_queue<int> pq;

    vector<int> diffs(size + 1, 0);
    int minus = 0, qI = 0;

    for (int i = 0; i < size; i++) {
      minus += diffs[i];

      while (qI < qSize && queries[qI][0] <= i) {
        pq.push(queries[qI][1]);
        qI++;
      }

      while (minus < nums[i]) {
        if (pq.empty() || pq.top() < i) {
          return -1;
        }

        int right = pq.top();
        diffs[right + 1]--;
        pq.pop();

        minus++;
      }
    }

    return pq.size();
  }
};