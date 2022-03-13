#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use priority queue & hash map
// time : O(N * log_2(K))
// space : O(N)
class Solution {
 private:
  struct Element {
    int num, count;

    bool operator<(const Element &b) const { return count > b.count; }
  };

 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> counts;  // key:num, val:count

    for (int &num : nums) {
      counts[num] += 1;
    }

    priority_queue<Element> pq;

    for (auto &it : counts) {
      pq.push({it.first, it.second});

      if (pq.size() > k) pq.pop();
    }

    vector<int> answer;
    while (!pq.empty()) {
      Element cur = pq.top();
      pq.pop();
      answer.push_back(cur.num);
    }

    return answer;
  }
};