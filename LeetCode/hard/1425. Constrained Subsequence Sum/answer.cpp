#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Data {
    int val, index;

    bool operator<(const Data& b) const { return val < b.val; }
  };

 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    size_t size = nums.size();

    priority_queue<Data> pq;
    // max heap
    pq.push({nums[0], 0});
    int answer = nums[0];

    for (int i = 1; i < size; i++) {
      while (i - pq.top().index > k) {
        pq.pop();
      }

      int cur = max(0, pq.top().val) + nums[i];
      answer = max(answer, cur);
      pq.push({cur, i});
    }

    return answer;
  }
};