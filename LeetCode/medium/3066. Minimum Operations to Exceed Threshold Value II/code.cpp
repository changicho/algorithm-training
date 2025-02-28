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
  int minOperations(vector<int>& nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(
        nums.begin(), nums.end());

    int answer = 0;
    while (pq.size() >= 2 && pq.top() < k) {
      long long first = pq.top();
      pq.pop();
      long long second = pq.top();
      pq.pop();

      pq.push(min(first, second) * 2 + max(first, second));

      answer++;
    }

    if (pq.empty() || pq.top() < k) return -1;
    return answer;
  }
};