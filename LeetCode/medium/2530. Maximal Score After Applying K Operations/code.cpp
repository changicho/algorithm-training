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
// time : O((N + K) * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;

    for (int& num : nums) {
      pq.push(num);
    }

    long long answer = 0;
    while (k--) {
      int cur = pq.top();
      pq.pop();

      answer += cur;

      pq.push(ceil((double)cur / 3));
    }
    return answer;
  }
};