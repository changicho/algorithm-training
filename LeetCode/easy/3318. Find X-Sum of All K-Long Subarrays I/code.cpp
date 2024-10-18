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

// use hash map & heap
// time : O(N * K * log_2(X))
// space : O(K + X)
class Solution {
 private:
  int calc(unordered_map<int, int> &counts, int x) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (auto [key, val] : counts) {
      pq.push({val, key});
      if (pq.size() > x) {
        pq.pop();
      }
    }

    int ret = 0;
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();

      ret += cur.first * cur.second;
      x--;
    }
    return ret;
  }

 public:
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    int size = nums.size();

    unordered_map<int, int> counts;
    for (int i = 0; i < k; i++) {
      counts[nums[i]]++;
    }
    vector<int> answer;
    for (int left = 0, right = k - 1; right < size; left++, right++) {
      int cur = calc(counts, x);
      answer.push_back(cur);

      if (right + 1 < size) {
        counts[nums[left]]--;
        if (counts[nums[left]] == 0) {
          counts.erase(nums[left]);
        }
        counts[nums[right + 1]]++;
      }
    }
    return answer;
  }
};