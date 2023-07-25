#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O(K * log_2(K))
// space : O(K)
class Solution {
 private:
  struct Data {
    int sum, idx1, idx2;

    bool operator<(const Data& other) const { return sum > other.sum; }
  };

 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    int size1 = nums1.size(), size2 = nums2.size();

    vector<vector<int>> answer;
    set<pair<int, int>> visited;

    priority_queue<Data> pq;
    pq.push({nums1[0] + nums2[0], 0, 0});

    while (answer.size() < k && !pq.empty()) {
      Data cur = pq.top();
      pq.pop();

      int idx1 = cur.idx1, idx2 = cur.idx2;

      if (visited.count({idx1, idx2}) > 0) continue;
      visited.insert({idx1, idx2});

      answer.push_back({nums1[idx1], nums2[idx2]});

      if (idx1 + 1 < size1) {
        pq.push({nums1[idx1 + 1] + nums2[idx2], idx1 + 1, idx2});
      }
      if (idx2 + 1 < size2) {
        pq.push({nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1});
      }
    }

    return answer;
  }
};