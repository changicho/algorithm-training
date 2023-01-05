#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O((N + K) * log_2(N))
// space : O(N)
class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;

    for (int& pile : piles) {
      pq.push(pile);
    }

    for (int i = 0; i < k; i++) {
      int cur = pq.top();
      pq.pop();

      cur = (cur + 1) / 2;
      pq.push(cur);
    }

    int answer = 0;
    while (!pq.empty()) {
      answer += pq.top();
      pq.pop();
    }
    return answer;
  }
};