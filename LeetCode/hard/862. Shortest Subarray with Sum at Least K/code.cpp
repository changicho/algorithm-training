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
  int shortestSubarray(vector<int>& nums, int k) {
    int size = nums.size();

    int answer = INT_MAX;

    // sum, index
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        minHeap;
    long long sum = 0;

    for (int i = 0; i < size; i++) {
      sum += nums[i];

      if (sum >= k) {
        answer = min(answer, i + 1);
      }

      while (!minHeap.empty() && sum - minHeap.top().first >= k) {
        answer = min(answer, i - minHeap.top().second);
        minHeap.pop();
      }

      minHeap.push({sum, i});
    }

    return answer == INT_MAX ? -1 : answer;
  }
};