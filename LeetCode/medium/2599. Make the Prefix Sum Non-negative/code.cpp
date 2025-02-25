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
  int makePrefSumNonNegative(vector<int>& nums) {
    long long sum = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    int answer = 0;
    for (int& num : nums) {
      sum += num;
      pq.push(num);

      while (!pq.empty() && sum < 0) {
        sum -= pq.top();
        answer++;
        pq.pop();
      }
    }

    return answer;
  }
};